/*
	AUTHOR: Morgan Visnesky
	DATE: 10/10/2020
 	FILENAME: ece0301_ICA11_step05.cpp
	DESCRIPTION:
	* This is in class assignment #11   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment covers the topic of time doamin signals.
	
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include <mgl2/mgl.h>
#include <memory>
#include <cmath>
#include <algorithm>

using namespace std;


// Signal class specification
class Signal 
{
	private:
		unsigned int numSamples;
		double frequency, timeInit;
		vector<double> signalPtr;
		vector<double> timePtr;
		std::string fileNameTemp;
		std::string signalLabel;
		std::string expression;
	public:
		void setSignalLabel(string);
		string getSignalLabel();
		string getFileNameTemp();
		void setExpression(string);
		string getExpression();
		void setNumSamples(unsigned int);
		void setFrequency(double);
		void setTimeInit(double);
		unsigned int getNumSamples();
		double getFrequency();
		double getTimeInit();
		vector<double> getSignalPtr();
		vector<double> getTimePtr();
		
		double getSignalPtr(unsigned int);
		double getTimePtr(unsigned int);
		void zeroArray();
		void zeroTimeArray();
		void timeArray();
		void setFileNameTemp();
		void fileOutput();
		void signalArrayFill(double, double, double);
		void rounder();
		void plotSignal();
		Signal();
		Signal(unsigned int, double, double);
		//~Signal();
		
};


/***********************************************************************
 * 			Signal class member function definitions are below:
 *
 **********************************************************************/

// Sets the expression representing the signal in the form of a string
void Signal::setExpression(string exp)
{
	expression = exp;
}

// Returns the expression representing the signal in the form of a string
string Signal::getExpression()
{
	return expression;
}

// Sets the signal label
void Signal::setSignalLabel(string label)
{
	signalLabel = label;
}

// Returns the signal label
string Signal::getSignalLabel()
{
	return signalLabel;
}

// Returns the filename template
string Signal::getFileNameTemp()
{
	return fileNameTemp;
}

// Default constructor for the Signal class
Signal::Signal()
{
	setNumSamples(101);
	setFrequency(100.0);
	setTimeInit(0.0);
	setSignalLabel("x");
	setFileNameTemp();
	setExpression("0");
	signalPtr.resize(getNumSamples());
	timePtr.resize(getNumSamples());
	zeroArray();
	zeroTimeArray();
	timeArray();
}

//constructor that allows you to set number of samples, rate, and initial time
Signal::Signal(unsigned int numSamps, double rate, double initialTime)
{
	setNumSamples(numSamps);
	setFrequency(rate);
	setTimeInit(initialTime);
	signalPtr.resize(getNumSamples());
	timePtr.resize(getNumSamples());
	zeroArray();
	zeroTimeArray();
	timeArray();
}

//member function that sets the number of samples
void Signal::setNumSamples(unsigned int num)
{
	numSamples = num;
}

//member function that sets the frequency
void Signal::setFrequency(double freq)
{
	frequency = freq;
}

// member function that sets the inition time
void Signal::setTimeInit(double time)
{
	timeInit = time;
}

//member function that returns the number of samples
unsigned int Signal::getNumSamples()
{
	return numSamples;
}

//member function that returns the frequency
double Signal::getFrequency()
{
	return frequency;
}

//member function that returns the initial time
double Signal::getTimeInit()
{
	return timeInit;
}

//member function that returns a the pointer pointing to the signal array
vector<double> Signal::getSignalPtr()
{
	return signalPtr;
}

//member function that returns the pointer pointing to the time array
vector<double> Signal::getTimePtr()
{
	return timePtr;
}

//returns a single element of the signal vector specified by the index
double Signal::getSignalPtr(unsigned int index)
{
	double temp = signalPtr[index];
	return temp;
}

//returns a single element of the time vector specified by the index
double Signal::getTimePtr(unsigned int index)
{
	double temp = timePtr[index];
	return temp;
}

//member function to fill time array with values
void Signal::timeArray()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		timePtr[i] = getTimeInit() + ((i)/getFrequency());
	}
}

//member function to fill the signal array with zeros
void Signal::zeroArray()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		signalPtr[i] = 0;
	}
	
}

//member function to fill the time array with zeros
void Signal::zeroTimeArray()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		timePtr[i] = 0;
	}
	
}

//member function to fill the signal array with actual signal values
void Signal::signalArrayFill(double amplitude, double frequency, double phase)
{
	
	
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		double time = getTimeInit() + (i/getFrequency());
		getSignalPtr()[i] = amplitude * cos(2*M_PI*frequency*time + phase);
		
	}
}


/*

//deconstructor
Signal::~Signal()
{
	delete signalPtr;
	delete timePtr;
}
* */

//member function that sets the file name template
void Signal::setFileNameTemp()
{
	fileNameTemp = "signal_" + getSignalLabel();
}

//member function that outputs a header and information about the signal 
//to an output file
void Signal::fileOutput()
{
	std::ofstream fileOut;
	std::string filename = fileNameTemp + ".txt";
	fileOut.open(filename);
	
	fileOut << "Time-Domain Signal Samples" << std::endl;
	fileOut << "N = " << getNumSamples() << std::endl;
	fileOut << "fs = " << getFrequency() << std::endl;
	fileOut << "t0 = " << getTimeInit() << std::endl;
	fileOut << "Signal label: " << getSignalLabel() << endl;
	fileOut << "Mathematical expression" << std::endl;
	fileOut << getSignalLabel() << "(t) = " << getExpression() << std::endl;
	fileOut << "Time and signal samples in .csv format" << endl;
	fileOut << "t, " << getSignalLabel() << "(t)" << endl;
	fileOut << "------" << endl;
	
	
	for (unsigned int i = 0;i < getNumSamples(); i ++)
	{
		fileOut << std::setprecision(3) << getTimePtr()[i] <<  ", " << getSignalPtr()[i] << std::endl ;
	}
	fileOut.close();
	
}

// member function that rounds data in the signal array
void Signal::rounder()
{
	for (unsigned int i = 0;i < getNumSamples(); i ++)
	{
		getSignalPtr()[i] = round(getSignalPtr()[i]);
	}
}

//member function that plots the signal array and then outputs that data
// to two types of images files
void Signal::plotSignal()
{
	std::string filetemplate = "time_domain_signal_samples";
	std::string epsExt = filetemplate + ".eps";
	std::string pngExt = filetemplate + ".png";
	mglData time(getNumSamples()), signal(getNumSamples());
	
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		time[i] = getTimePtr()[i];
		signal[i] = getSignalPtr()[i];
	}
	mglGraph graph;
	graph.Title("Time Domain signals");
	double min=0;
	double max=0;
	double maxSig;
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		if (getTimePtr()[i] < min)
		{
			min = getTimePtr()[i];
		}
		
		if (getTimePtr()[i] > max)
		{
			max = getTimePtr()[i];
		}
	}
	
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		maxSig = getSignalPtr()[i];
		if (getSignalPtr()[i] > max)
		{
			maxSig = getSignalPtr()[i];
		}
	}
	graph.SetRanges(min, max, maxSig, -maxSig);
	graph.SetOrigin(0,0);
	graph.Axis();
	graph.Puts( mglPoint(min-0.02, -0.5), mglPoint(min-0.02, 0.5), "Voltage");
	graph.Puts( mglPoint((min+max)/2, maxSig-1.25), "Time");
	graph.Plot(time, signal);
	graph.WriteEPS(epsExt.c_str());
	graph.WritePNG(pngExt.c_str());
}


int main() 
{
	Signal sig;
	
	cout << sig.getNumSamples() << endl;
	cout << sig.getSignalPtr().size() << endl;
	cout << sig.getSignalLabel() << endl;
	sig.setExpression("cos( 10 t)");
	cout << sig.getExpression() << endl;
	cout << sig.getFileNameTemp() << endl << endl;
	sig.fileOutput();
	
	Signal sig2;
	
	cout << sig2.getNumSamples() << endl;
	cout << sig2.getSignalPtr().size() << endl;
	sig2.setSignalLabel("y");
	sig2.setFileNameTemp();
	cout << sig2.getSignalLabel() << endl;
	sig2.setExpression("sin( 10 t)");
	cout << sig2.getExpression() << endl;
	cout << sig2.getFileNameTemp() << endl;
	sig2.fileOutput();
	/*for (unsigned int i =0; i < sig.getNumSamples(); i++)
	{
		cout << sig.getSignalPtr()[i] << endl;
	}*/
	return 0;
}
