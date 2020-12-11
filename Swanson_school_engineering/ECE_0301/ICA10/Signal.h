/*
	AUTHOR: Morgan Visnesky
	DATE: 10/10/2020
 	FILENAME: Signal.h
	DESCRIPTION:
	* This is in class assignment #10   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment covers the topic of time doamin signals.
	* This holds the specification of the signal class.
*/


#ifndef SIGNAL_H
#define SIGNAL_H

class Signal 
{
	private:
		unsigned int numSamples;
		double frequency, timeInit;
		double *signalPtr;
		double *timePtr;
		std::string fileNameTemp;
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
		void setFileNameTemp(std::string);
		void fileOutput();
		void signalArrayFill(double, double, double);
		void rounder();
		void plotSignal();
		Signal();
		Signal(unsigned int, double, double);
		~Signal();
};

#endif
