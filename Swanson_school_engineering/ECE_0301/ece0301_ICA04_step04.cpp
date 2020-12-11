/*
	AUTHOR: Morgan Visnesky
	DATE: 09/04/2020
 	FILENAME: ece0301_ICA04_step04.cpp
	DESCRIPTION:
	* This is in class assignment #4   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.
	
	* This program reads values from files that are then used to calculate either voltage divider or Wheatstone bridge equations
	* and then writes those values in a formatted output to a solutions .txt file.
*/

// include statements
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(){
	// displays message to the standard output
	cout << "ECE 0301: Circuit Solver for Voltage Divider" << endl << "and Wheatstone bridge example circuits." << endl;
	
	// creates in filestream object
	ifstream inputFile;
	
	// uses in filestream object to open a text file
	inputFile.open("divider_wheatstone_circuits.txt");
	// declares sting to store value of first line of the .txt file
	string firstLine;
	
	// declares variables used for the voltage divider option
	int r1, r2;
	double vs;
	
	// store value of the first line of the file into the valiable "firstLine"
	inputFile >> firstLine;
	
	// Creates an out filestream object to write to a solutions .txt file
	ofstream lineOut;
	lineOut.open("divider_wheatstone_solutions.txt");
	
	// if statement to hold the logic for computing voltage "Divider" files
	if (firstLine == "Divider"){
		
		
		// sends message to the outputFile with the same header the is displayed to the standard output when the program starts
		lineOut << "ECE 0301: Circuit Solver for Voltage Divider" << endl << "and Wheatstone bridge example circuits." << endl;
		
		// sends message to the outputFile indicating that the user has selected a "Divider" file
		lineOut << "-----" << endl << "Circuit #1 (Voltage Divider)" << endl << "---" << endl;
		
		
		
		// Initializes the variables for source voltage vs, resistor1 r1, and resistor2 r2, with values from the .txt file
		inputFile >> vs;
		inputFile >> r1;
		inputFile >> r2;
		
		//sends message to the outputFile indicating the values for source voltage and resistors r1 and r2
		lineOut << "Source voltage: Vs = " << vs << " Volts." << endl;
		lineOut << "Resistor: R1 = " << r1 << " Ohms." << endl;
		lineOut << "Resistor: R2 = " << r2 << " Ohms." << endl << endl;
		
		// displays message to the standard output with the calculated current for the circuit loop
		lineOut << setprecision(3) << "Loop current: I = " << (vs/(r1+r2)) << " Amperes." << endl;
		
		// changes r1 and r2 to doubles so that we can perform division that yields a double and not 0
		double r1Current = static_cast<double>(r1)/(r1+r2);
		double r2Current = static_cast<double>(r2)/(r1+r2);
		
		// sends message to the outputFile in addition to calculating the respective voltages across
		// r1 and r2 using the currents we just calculated a few lines up
		lineOut << "Resistor voltage: V1 = " << vs*r1Current << " Volts." << endl;
		lineOut << "Resistor voltage: V2 = " << vs*r2Current << " Volts." << endl;
		
		
	}
	else if (firstLine == "Wheatstone"){
		// This case happens when the first line of the file is "Wheatstone"
		return -1;
	}
	else{
		// This case happens when the first line of the file is "Wheatstone"
		
		// A message is displayed to the standard output to let the user know 
		//that an invalid header was encountered with the file they tried to open.
		cout << "ERROR! Invalid header." << endl;
		return -1;
	}
	// closes the outputFile object
	lineOut.close();
	return 0;	
}
