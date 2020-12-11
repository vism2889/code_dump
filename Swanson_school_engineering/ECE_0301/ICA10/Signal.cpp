/*
	AUTHOR: Morgan Visnesky
	DATE: 10/10/2020
 	FILENAME: Signal.cpp
	DESCRIPTION:
	* This is in class assignment #10   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment covers the topic of time doamin signals.
	* This holds the definition of the signla class and all member functions
*/

//includes header file
#include "Signal.h"

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
void Signal::setFileNameTemp(std::string fnt)
{
	fileNameTemp = fnt;
}

//member function that outputs a header and information about the signal 
//to an output file
void Signal::fileOutput()
{
	std::ofstream fileOut;
	std::string filename = fileNameTemp + ".txt";
	fileOut.open(filename);
	
	fileOut << "ECE 0301: Time-Domain Signal Samples" << std::endl;
	fileOut << "The number of samples is " << getNumSamples() << std::endl;
	fileOut << "The sample rate is " << getFrequency() << std::endl;
	fileOut << "The initial time is " << getTimeInit() << std::endl;
	fileOut << "Here is your signal:" << std::endl;
	fileOut << "t, s(t)" << std::endl;
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
