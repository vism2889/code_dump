/*
	AUTHOR: Morgan Visnesky
	DATE: 09/07/2020
 	FILENAME: ece0301_ICA05_step03.cpp
	DESCRIPTION:
	* This is in class assignment #5   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	This assignment covers boolean logic, binary representation of numbers, and POS and SOP.
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;

// prototypes for the three functions used in the application
bool orThreeGate(bool, bool, bool);
void displayTruthTable(ofstream &, bool);
bool andThreeGate(bool, bool, bool);



int main(){
	
	cout << "ECE 0301: Boolean Functions of 3 Variables." << endl << "Realization in Canonical Forms." << endl;
	
	ofstream fileOut;
	fileOut.open("Bool_func_3var_CSOP_CPOS.txt");
	fileOut << "ECE 0301: Boolean Functions of 3 Variables." << endl << "Realization in Canonical Forms." << endl;
	displayTruthTable(fileOut, 0);
	displayTruthTable(fileOut, 1);
	//cout << orThreeGate(0,0,1);
	return 0;
}

bool orThreeGate(bool in1, bool in2, bool in3){
	// Replicates a 3 input boolean OR gate.
	// Takes three boolean values as arguments and returns a boolean 
	// value of false if and only if all of the input arguments are 
	// false, and true otherwise.
	return (in1 || in2 || in3);
}

bool andThreeGate(bool in1, bool in2, bool in3){
	// Replicates a 3 input boolean AND gate.
	// Takes three boolean values as arguments and returns a boolean 
	// value of true if and only if all of the input arguments are 
	// true.
	return (in1 && in2 && in3);
}

void displayTruthTable(ofstream &outputFile, bool andOR){
	// Takes an ofstream object as argument (the argument is passed to the parameter as reference.
	
	bool x, y, z;
	
	// If the provided argument is 1 (true) the following and case will be triggered,
	// which displays the truth table for a three input OR gate in the output file.
	if (andOR){
		// Displays header for the AND gate to the output file.
		outputFile << endl << "Truth table for AND gate." << endl << endl;
		outputFile << "x\ty\tz\tf(x,y,z)" << endl;
		outputFile << "--------------------------------" << endl;
		
		// for loop to iterate  
		for (int i = 0; i <= 7; i++){
		
			// stores the bit values for the number of the current iteration in x,y,z variables
			z = i%2;	// least significant bit
			y = (i >> 1) %2; // middle bit
			x = (i >> 2) %2; // most significant bit
			
			// adds values from current iteration to the truth table in the output file.
			outputFile << x <<"\t"<< y<<"\t"<< z <<"\t"<< andThreeGate(x,y,z) << endl;
		}
	}
	// If the provided argument is 0 (false) the following and case will be triggered,
	// which displays the truth table for a three input AND gate in the output file.
	else{
		outputFile << endl << "Truth table for OR gate." << endl << endl;
		outputFile << "x\ty\tz\tf(x,y,z)" << endl;
		outputFile << "--------------------------------" << endl;
		
		for (int i = 0; i <= 7; i++){
			
			// stores the bit values for the number of the current iteration in x,y,z variables
			z = i%2;
			y = (i >> 1) %2;
			x = (i >> 2) %2;
			
			// adds values from current iteration to the truth table in the output file.
			outputFile << x <<"\t"<< y<<"\t"<< z <<"\t"<< orThreeGate(x,y,z) << endl;
		}
	}
}

