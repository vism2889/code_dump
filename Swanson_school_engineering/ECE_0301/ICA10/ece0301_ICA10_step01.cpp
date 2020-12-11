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

using namespace std;

class Signal {
	private:
		unsigned int numSamples;
		double frequency, timeInit;
	public:
		void setNumSamples(unsigned int);
		void setFrequency(double);
		void setTimeInit(double);
		unsigned int getNumSamples();
		double getFrequency();
		double getTimeInit();
		Signal();
};

void Signal::setNumSamples(unsigned int num){
	numSamples = num;
}

void Signal::setFrequency(double freq){
	frequency = freq;
}

void Signal::setTimeInit(double time){
	timeInit = time;
}

unsigned int Signal::getNumSamples(){
	return numSamples;
}

double Signal::getFrequency(){
	return frequency;
}

double Signal::getTimeInit(){
	return timeInit;
}

Signal::Signal(){
	setNumSamples(101);
	setFrequency(100.0);
	setTimeInit(0.0);
}

int main(){
	Signal sig;
	cout << "ECE 0301: Time-Domain Signal Samples" << endl;
	cout << "The number of samples is " << sig.getNumSamples() << endl;
	cout << "The sample rate is " << sig.getFrequency() << endl;
	cout << "The initial time is " << sig.getTimeInit() << endl;
	
	
	return 0;
}
	
