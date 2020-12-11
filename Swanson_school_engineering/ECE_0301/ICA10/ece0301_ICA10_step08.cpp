/*
	AUTHOR: Morgan Visnesky
	DATE: 10/10/2020
 	FILENAME: ece0301_ICA10_step08.cpp
	DESCRIPTION:
	* This is in class assignment #10   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment covers the topic of time doamin signals.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <fstream>
#include <cmath>

using namespace std;

// Signal class declaration
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
		void signalArrayFill(double, double, double);
		void rounder();
		Signal();
		Signal(unsigned int, double, double);
		~Signal();
};

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
double *Signal::getSignalPtr()
{
	return signalPtr;
}

//member function that returns the pointer pointing to the time array
double *Signal::getTimePtr()
{
	return timePtr;
}

//member function to fill time array with values
void Signal::timeArray()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		getTimePtr()[i] =  getTimeInit() + ((i)/getFrequency());
	}
}

//member function to fill the signal array with zeros
void Signal::zeroArray()
{
	for (unsigned int i = 0; i < getNumSamples(); i ++)
	{
		getSignalPtr()[i] = 0;
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

//default constructor
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

//constructor that allows you to set number of samples, rate, and initial time
Signal::Signal(unsigned int numSamps, double rate, double initialTime)
{
	setNumSamples(numSamps);
	setFrequency(rate);
	setTimeInit(initialTime);
	signalPtr = new double[getNumSamples()];
	timePtr = new double[getNumSamples()];
	zeroArray();
	timeArray();
}

//deconstructor
Signal::~Signal()
{
	delete signalPtr;
	delete timePtr;
}

//member function that sets the file name template
void Signal::setFileNameTemp(string fnt)
{
	fileNameTemp = fnt;
}

//member function that outputs a header and information about the signal 
//to an output file
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
		fileOut << setprecision(3) << getTimePtr()[i] <<  ", " << getSignalPtr()[i] <<endl ;
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
	
/***********************************************************************
 * 					**	signalInfoParser  **
 **********************************************************************/	
unsigned int signalDataGrab(double &, double &, double &, double &, double &);

unsigned int signalDataGrab(double & sampFrequency, double & initialTime, double & amplitude, double & frequency, double & phase)
{
	ifstream signalIn;
	signalIn.open("sine_wave_specification.txt");
	string lineOne;
	getline(signalIn, lineOne);
	string lineOneHeader = lineOne.substr(0,19);
	
	cout << lineOneHeader << endl;
	if (lineOneHeader != "Number of samples: ")
	{
		cout << "ERROR! Invalid input file header.";
		return -1;
	}
	
	double numSamples = static_cast<double>(stof(lineOne.substr(19)));
	
	string line;
	getline(signalIn, line);
	if (line.substr(0,20) != "Sampling frequency: ")
	{
		cout << "ERROR! Invalid input file header.";
		return -1;
	}
	sampFrequency = static_cast<double>(stof(line.substr(20)));
	
	getline(signalIn, line);
	if (line.substr(0,14) != "Initial time: ")
	{
		cout << "ERROR! Invalid input file header.";
		return -1;
	}
	initialTime = static_cast<double>(stof(line.substr(14)));
	
	
	getline(signalIn, line);
	if (line.substr(0,11) != "Amplitude: ")
	{
		cout << "ERROR! Invalid input file header.";
		return -1;
	}
	amplitude = static_cast<double>(stof(line.substr(11)));
	
	
	getline(signalIn, line);
	if (line.substr(0,11) != "Frequency: ")
	{
		cout << "ERROR! Invalid input file header.";
		return -1;
	}
	frequency = static_cast<double>(stof(line.substr(11)));
	
	getline(signalIn, line);
	if (line.substr(0,7) != "Phase: ")
	{
		cout << "ERROR! Invalid input file header.";
		return -1;
	}
	phase = static_cast<double>(stof(line.substr(7)));
	
	signalIn.close();
	return numSamples;
}
	

/***********************************************************************
 * 					**	main()  **
 **********************************************************************/
int main()
{
	unsigned int numSamples;
	double sampleFreq, initTime, amp, freq, phase;
	numSamples = signalDataGrab(sampleFreq, initTime, amp, freq, phase);
	Signal sig = Signal(numSamples, sampleFreq, initTime);
	
	sig.signalArrayFill(amp, freq, phase);
	sig.rounder();
	sig.setFileNameTemp("time_domain_signal_samples");
	sig.fileOutput();
	return 0;
}
