

/***********************************************************************
 * 			Signal class member function definitions are below:
 *
 **********************************************************************/

#include "Signal.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>


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
	fileNameTemp = "diff_eqn_soln_" + signalLabel;
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
	//signalVec.resize(getNumSamples());
	//timeVec.resize(getNumSamples());
	//zeroSignalVec();
	//zeroTimeVec();
	//fillTimeVec();
}

Signal::Signal(unsigned int numSamps, double freq, double time)
{
	setNumSamples(numSamps);
	setFrequency(freq);
	setTimeInit(time);
	setSignalLabel("x");
	setFileNameTemp();
	setExpression(textNum(0.00));
	//signalVec.resize(getNumSamples());
	//timeVec.resize(getNumSamples());
	//zeroSignalVec();
	//zeroTimeVec();
	//fillTimeVec();
}

//member function that sets the number of samples
void Signal::setNumSamples(unsigned int num)
{
	numSamples = num;
	timeVec.resize(num);
	signalVec.resize(num);
	fillTimeVec();
}

//member function that sets the frequency
void Signal::setFrequency(double freq)
{
	frequency = freq;
	fillTimeVec();
}

// member function that sets the inition time
void Signal::setTimeInit(double time)
{
	timeInit = time;
	fillTimeVec();
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

Signal Signal::operator*(const Signal &sig)
{
		if ((this->frequency == sig.frequency) && 
			(this->numSamples == sig.numSamples) &&
			(this->timeInit == sig.timeInit))
		{
				
			Signal signal(this->numSamples, this->frequency, this->timeInit);
		
			//signal.frequency = this->frequency + sig.frequency;
			//signal.numSamples = this->numSamples + sig.numSamples;
			//signal.timeInit = this->timeInit + sig.timeInit;
			
			signal.setExpression("(" + this->expression + ")(" + sig.expression+")");
		
			//signal.timeVec = this->timeVec;
			
			for (unsigned int i = 0;i < getNumSamples(); i ++)
			{
				signal.signalVec[i] = this->signalVec[i] * sig.signalVec[i];
			}
			
			return signal;
		}
		else
		{
			std::cout << "ERROR!  Attempt to multiply incompatible signals.";
			exit(EXIT_FAILURE);
		}
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

void Signal::expSigFill(double tao, double a)
{
	std::stringstream stream;
	std::stringstream stream1;
	std::stringstream stream2;
	
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		double temp = a * exp(-(timeVec[i]-timeInit)/tao);
		signalVec[i] = temp;
	}
	stream << std::fixed << std::setprecision(2) << tao;
	std::string tt = stream.str();
	stream1 << std::fixed << std::setprecision(2) << a;
	std::string aa = stream1.str();
	stream2 << std::fixed << std::setprecision(2) << timeInit;
	std::string tim = stream2.str();
	std::string exp = aa+" exp( -(t - " + tim+") / "+tt+" )";
	setExpression(exp);
}
