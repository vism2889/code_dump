/*
	AUTHOR: Morgan Visnesky
	DATE: 10/10/2020
 	FILENAME: ece0301_ICA10_step04.cpp
	DESCRIPTION:
	* This is in class assignment #10   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment covers the topic of time doamin signals.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <fstream>

using namespace std;

class Signal 
{
	private:
		unsigned int numSamples;
		double frequency, timeInit;
		double *signalPtr;
		double *timePtr;
		string fileNameTemp;
	public:
		void setNumSamples(unsigned int);
		void setFrequency(double);
		void setTimeInit(double);
		unsigned int getNumSamples();
		double getFrequency();
		double getTimeInit();
		double *getSignalPtr();
		double *getTimePtr();
		void zeroArray();
		void timeArray();
		void setFileNameTemp(string);
		void fileOutput();
		Signal();
		~Signal();
};

//member function that sets the number of samples
void Signal::setNumSamples(unsigned int num)
{
	numSamples = num;
}

void Signal::setFrequency(double freq)
{
	frequency = freq;
}

void Signal::setTimeInit(double time)
{
	timeInit = time;
}

unsigned int Signal::getNumSamples()
{
	return numSamples;
}

double Signal::getFrequency()
{
	return frequency;
}

double Signal::getTimeInit()
{
	return timeInit;
}

double *Signal::getSignalPtr()
{
	return signalPtr;
}

double *Signal::getTimePtr()
{
	return timePtr;
}

void Signal::timeArray()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		getTimePtr()[i] =  ((i)/getFrequency());
	}
}

void Signal::zeroArray()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		getSignalPtr()[i] = 0;
	}
}

Signal::Signal()
{
	setNumSamples(101);
	setFrequency(100.0);
	setTimeInit(0.0);
	signalPtr = new double[getNumSamples()];
	timePtr = new double[getNumSamples()];
	zeroArray();
	timeArray();
	fileNameTemp = "tdsig";
	
}

Signal::~Signal()
{
	delete signalPtr;
	delete timePtr;
}

void Signal::setFileNameTemp(string fnt)
{
	fileNameTemp = fnt;
}

void Signal::fileOutput()
{
	ofstream fileOut;
	string filename = fileNameTemp + ".txt";
	fileOut.open(filename);
	
	fileOut << "ECE 0301: Time-Domain Signal Samples" << endl;
	fileOut << "The number of samples is " << getNumSamples() << endl;
	fileOut << "The sample rate is " << getFrequency() << endl;
	fileOut << "The initial time is " << getTimeInit() << endl;
	fileOut << "Here is your signal:" << endl;
	fileOut << "t, s(t)" << endl;
	for (unsigned int i = 0;i < getNumSamples(); i ++)
	{
		fileOut << setprecision(2) << getTimePtr()[i] <<  ", " << getSignalPtr()[i] <<endl ;
	}
	fileOut.close();
}
	
/***********************************************************************
 * 
 * 					**	main()  **
 **********************************************************************/
int main()
{
	Signal sig;
	sig.setFileNameTemp("time_domain_signal_samples");
	sig.fileOutput();
	return 0;
}
	
