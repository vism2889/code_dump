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
		vector<double> signalVec;
		vector<double> timeVec;
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
		vector<double> getSignalVec();
		vector<double> getTimeVec();
		
		string textNum(double x) const;
		void fillSignalVec(double);
		double getSignalVec(unsigned int);
		double getTimeVec(unsigned int);
		void zeroSignalVec();
		void zeroTimeVec();
		void fillTimeVec();
		void setFileNameTemp();
		void fileOutput();
		void operator=(const Signal & );
		Signal(unsigned int, double, double);
		Signal();
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
	setTimeInit(0);
	setSignalLabel("x");
	setFileNameTemp();
	setExpression(textNum(0.00));
	signalVec.resize(getNumSamples());
	timeVec.resize(getNumSamples());
	zeroSignalVec();
	zeroTimeVec();
	fillTimeVec();
}

Signal::Signal(unsigned int numSamps, double freq, double time)
{
	setNumSamples(numSamps);
	setFrequency(freq);
	setTimeInit(time);
	setSignalLabel("x");
	setFileNameTemp();
	setExpression(textNum(0.00));
	signalVec.resize(getNumSamples());
	timeVec.resize(getNumSamples());
	zeroSignalVec();
	zeroTimeVec();
	fillTimeVec();
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
vector<double> Signal::getSignalVec()
{
	return signalVec;
}

//member function that returns the pointer pointing to the time array
vector<double> Signal::getTimeVec()
{
	return timeVec;
}

//returns a single element of the signal vector specified by the index
double Signal::getSignalVec(unsigned int index)
{
	double temp = signalVec[index];
	return temp;
}

//returns a single element of the time vector specified by the index
double Signal::getTimeVec(unsigned int index)
{
	double temp = timeVec[index];
	return temp;
}

//member function to fill time array with values
void Signal::fillTimeVec()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		timeVec.at(i) = timeInit + (static_cast<double>(i)/frequency);
	}
}

//member function to fill the signal array with zeros
void Signal::zeroSignalVec()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		signalVec[i] = 0;
	}
	
}

void Signal::fillSignalVec(double constant)
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		signalVec[i] = constant;
	}
}

//member function to fill the time array with zeros
void Signal::zeroTimeVec()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		timeVec[i] = 0;
	}
	
}

string Signal::textNum(double x) const
{
	if (x >= 100)
	// large numbers truncated as int -> string
		return std::to_string(int(x));
	else
	{
		// small numbers will get 3 digits
		string x_exp = std::to_string(x);
		// return 4 characters, or 5 if x<0
		return x_exp.substr(0, 4 + (x<0));
	}
}

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
	fileOut << "-------" << endl;
	
	for (unsigned int i = 0;i < getNumSamples(); i ++)
	{
		fileOut  << timeVec[i] <<  ", " << signalVec[i] << std::endl ;
	}
	fileOut.close();
}

void Signal::operator=(const Signal &sig)
{
		frequency = sig.frequency;
		numSamples = sig.numSamples;
		timeInit = sig.timeInit;
		expression = sig.expression;
		timeVec = sig.timeVec;
		signalVec = sig.signalVec;
}

int main() 
{
	// Signal #1 declaration and file output
	Signal sig1;
	sig1.fillSignalVec(1.00);
	sig1.setExpression(sig1.textNum(1.00));
	sig1.fileOutput();
	
	// Signal #2 declaration and file output
	Signal sig2(401, 10000, -0.01);
	sig2.setSignalLabel("y");
	sig2 = sig1;
	//sig2.fillTimeVec();
	sig2.setFileNameTemp();
	sig2.fileOutput();
	
	return 0;
}
