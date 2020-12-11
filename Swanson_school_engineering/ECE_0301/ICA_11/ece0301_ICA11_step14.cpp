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

//using namespace std;


// Signal class specification
class Signal 
{
	private:
		unsigned int numSamples;
		double frequency, timeInit;
		std::vector<double> signalVec;
		std::vector<double> timeVec;
		std::string fileNameTemp;
		std::string signalLabel;
		std::string expression;
	public:
		void setSignalLabel(std::string);
		std::string getSignalLabel();
		std::string getFileNameTemp();
		void setExpression(std::string);
		std::string getExpression();
		void setNumSamples(unsigned int);
		void setFrequency(double);
		void setTimeInit(double);
		unsigned int getNumSamples();
		double getFrequency();
		double getTimeInit();
		std::vector<double> getSignalVec();
		std::vector<double> getTimeVec();
		void plotSignal();
		std::string textNum(double x) const;
		void fillSignalVec(double);
		double getSignalVec(unsigned int);
		double getTimeVec(unsigned int);
		void zeroSignalVec();
		void zeroTimeVec();
		void fillTimeVec();
		void setFileNameTemp();
		void fileOutput();
		void operator=(const Signal &);
		void signalVecFill(double, double, double);
		void rounder();
		Signal operator+(const Signal &);
		Signal(unsigned int, double, double);
		Signal();
};


/***********************************************************************
 * 			Signal class member function definitions are below:
 *
 **********************************************************************/

// Sets the expression representing the signal in the form of a string
void Signal::setExpression(std::string exp)
{
	expression = exp;
}

// Returns the expression representing the signal in the form of a string
std::string Signal::getExpression()
{
	return expression;
}

// Sets the signal label
void Signal::setSignalLabel(std::string label)
{
	signalLabel = label;
}

// Returns the signal label
std::string Signal::getSignalLabel()
{
	return signalLabel;
}

// Returns the filename template
std::string Signal::getFileNameTemp()
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
std::vector<double> Signal::getSignalVec()
{
	return signalVec;
}

//member function that returns the pointer pointing to the time array
std::vector<double> Signal::getTimeVec()
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
	expression = textNum(constant);
}

//member function to fill the time array with zeros
void Signal::zeroTimeVec()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		timeVec[i] = 0;
	}
	
}

std::string Signal::textNum(double x) const
{
	if (x >= 100)
	// large numbers truncated as int -> string
		return std::to_string(int(x));
	else
	{
		// small numbers will get 3 digits
		std::string x_exp = std::to_string(x);
		// return 4 characters, or 5 if x<0
		return x_exp.substr(0, 4 + (x<0));
	}
}

void Signal::signalVecFill(double amplitude, double freq, double phase)
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		double time = timeInit + (i/frequency);
		signalVec[i] = amplitude * cos(2*M_PI*freq*time + phase);
	}
	std::string exp = textNum(amplitude) + "cos(" + textNum(2*M_PI*freq) + "t " + textNum(phase) + ")";
	expression = exp;
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
	fileOut << "Signal label: " << getSignalLabel() << std::endl;
	fileOut << "Mathematical expression" << std::endl;
	fileOut << getSignalLabel() << "(t) = " << getExpression() << std::endl;
	fileOut << "Time and signal samples in .csv format" << std::endl;
	fileOut << "t, " << getSignalLabel() << "(t)" << std::endl;
	fileOut << "-------" << std::endl;
	
	for (unsigned int i = 0;i < getNumSamples(); i ++)
	{
		fileOut  << timeVec[i] <<  ", " << signalVec[i] << std::endl ;
	}
	fileOut.close();
}

void Signal::rounder()
{
	for (unsigned int i = 0;i < getNumSamples(); i ++)
	{
		signalVec[i] = round(signalVec[i]);
	}
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

Signal Signal::operator+(const Signal &sig)
{
		if ((this->frequency == sig.frequency) && 
			(this->numSamples == sig.numSamples) &&
			(this->timeInit == sig.timeInit))
		{
				
			Signal signal(this->numSamples, this->frequency, this->timeInit);
		
			//signal.frequency = this->frequency + sig.frequency;
			//signal.numSamples = this->numSamples + sig.numSamples;
			//signal.timeInit = this->timeInit + sig.timeInit;
			std::string plus = " + ";
			signal.setExpression(this->expression + plus + sig.expression);
		
			//signal.timeVec = this->timeVec;
			
			for (unsigned int i = 0;i < getNumSamples(); i ++)
			{
				signal.signalVec[i] = this->signalVec[i] + sig.signalVec[i];
			}
			
			return signal;
		}
		else
		{
			std::cout << "ERROR!  Attempt to add incompatible signals.";
			exit(EXIT_FAILURE);
		}
}

//member function that plots the signal array and then outputs that data
// to two types of images files
void Signal::plotSignal()
{
	std::string filetemplate = fileNameTemp + "step14";
	std::string epsExt = filetemplate + ".eps";
	std::string pngExt = filetemplate + ".png";
	mglData time(getNumSamples()), signal(getNumSamples());
	
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		time.a[i] = timeVec[i];
		signal.a[i] = signalVec[i];
	}
	mglGraph graph;
	std::string title = signalLabel + "(t)";
	graph.Title(title.c_str());
	double min=0;
	double max=0;
	double maxSig = 0;
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		if (timeVec[i] < min)
		{
			min = timeVec[i];
		}
		
		if (timeVec[i] > max)
		{
			max = timeVec[i];
		}
	}
	
	
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		//maxSig = signalVec[i];
		if (signalVec[i] > maxSig)
		{
			maxSig = signalVec[i];
		}
	}
	graph.SetRanges(min, max, maxSig, -maxSig);
	graph.SetOrigin(0,0);
	graph.Axis();
	graph.Puts( mglPoint(min-0.2, (-maxSig+maxSig)/2), mglPoint(min-0.2, (-maxSig+maxSig)/2), "Voltage");
	graph.Puts( mglPoint((min+max)/2, maxSig-1.25), "Time");
	graph.Plot(time, signal);
	graph.WriteEPS(epsExt.c_str());
	graph.WritePNG(pngExt.c_str());
}

int main() 
{
	// Signal #1 declaration and file output
	
	// complex signal
	Signal signalQ(2001, 500, -0.01);
	signalQ.fillSignalVec(0);
	signalQ.setSignalLabel("Q");
	
	int k = 5;
	for (int i =1; i <= k; i++)
	{
		Signal sigX(2001, 500, -0.01);
		sigX.signalVecFill(4/(i*M_PI),i, (M_PI/2)*(i + 1));
		//sigX.setSignalLabel("x_i");
		signalQ = signalQ + sigX;
		signalQ.setFileNameTemp();
	}
	signalQ.fileOutput();
	signalQ.plotSignal();
	
	/*
	Signal sig1(401, 10000, -0.01);
	sig1.signalVecFill(100, 200, -M_PI/2);
	sig1.fileOutput();
	sig1.plotSignal();
	
	// Signal #2 declaration and file output
	Signal sig2(401, 10000, -0.01);
	sig2.setSignalLabel("y");
	sig2.setFileNameTemp();
	sig2.fillSignalVec(250);
	sig2.fileOutput();
	sig2.plotSignal();
	
	Signal sig3;
	sig3.setSignalLabel("z");
	
	sig3 = sig1 + sig2;
	sig3.setFileNameTemp();
	//sig3.rounder();
	sig3.fileOutput();
	sig3.plotSignal();
	*/
	return 0;
}
