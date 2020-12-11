/*
	AUTHOR: Morgan Visnesky
	DATE: 10/10/2020
 	FILENAME: ece0301_ICA10_step08.cpp
	DESCRIPTION:
	* This is in class assignment #10   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment covers the topic of time doamin signals.
	* This file holds the declaration and definition of a function that
	* accesses and reads from a file.  Along with the main() function 
	* that is used to create a signal object and ouput information about
	* that object to an ouput image and test file.
*/

#include <mgl2/mgl.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "Signal.cpp"

	
// declaration for function that grabs data from an input file
unsigned int signalDataGrab(double &, double &, double &, double &, double &);


/***********************************************************************
 * 					**	signalInfoParser  **
 * 
 * Grabs required information from an input file, returns an error message to 
 * the standard output if the format of the file is incorrect.
 **********************************************************************/
unsigned int signalDataGrab(double & sampFrequency, double & initialTime, double & amplitude, double & frequency, double & phase)
{
	// declares ifstream variable to hold input file
	std::ifstream signalIn;
	signalIn.open("sine_wave_specification.txt");
	
	// String to hold first line of file
	std::string lineOne;
	getline(signalIn, lineOne);
	std::string lineOneHeader = lineOne.substr(0,19);
	
	// Ensures samples line is formatted correctly
	if (lineOneHeader != "Number of samples: ")
	{
		std::cout << "ERROR! Invalid input file header.";
		return -1;
	}
	
	// stores samples in the vairbale that was passed by reference
	double numSamples = static_cast<double>(stof(lineOne.substr(19)));
	
	// string variable to hold all the following lines of the file
	std::string line;
	getline(signalIn, line);
	
	// Ensures frequency line is formatted correctly
	if (line.substr(0,20) != "Sampling frequency: ")
	{
		std::cout << "ERROR! Invalid input file header.";
		return -1;
	}
	sampFrequency = static_cast<double>(stof(line.substr(20)));
	
	getline(signalIn, line);
	// Ensures Initial time line is formatted correctly
	if (line.substr(0,14) != "Initial time: ")
	{
		std::cout << "ERROR! Invalid input file header.";
		return -1;
	}
	initialTime = static_cast<double>(stof(line.substr(14)));
	
	
	getline(signalIn, line);
	// Ensures amplitude line is formatted correctly
	if (line.substr(0,11) != "Amplitude: ")
	{
		std::cout << "ERROR! Invalid input file header.";
		return -1;
	}
	amplitude = static_cast<double>(stof(line.substr(11)));
	
	
	getline(signalIn, line);
	// Ensures frequency line is formatted correctly
	if (line.substr(0,11) != "Frequency: ")
	{
		std::cout << "ERROR! Invalid input file header.";
		return -1;
	}
	frequency = static_cast<double>(stof(line.substr(11)));
	
	getline(signalIn, line);
	// Ensures phase line is formatted correctly
	if (line.substr(0,7) != "Phase: ")
	{
		std::cout << "ERROR! Invalid input file header.";
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
	unsigned int numSamples; // holds number of samples
	double sampleFreq, initTime, amp, freq, phase;
	std::string filetemplate = "time_domain_signal_samples"; // holds template for file names
	
	numSamples = signalDataGrab(sampleFreq, initTime, amp, freq, phase); // assigns numSamples to value returned from dataGrab
	Signal sig = Signal(numSamples, sampleFreq, initTime);
	
	sig.signalArrayFill(amp, freq, phase);
	sig.rounder();
	sig.setFileNameTemp("time_domain_signal_samples");
	sig.fileOutput();
	sig.plotSignal();
	return 0;
}
