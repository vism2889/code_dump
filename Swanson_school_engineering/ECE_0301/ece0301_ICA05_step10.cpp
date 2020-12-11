/*
	AUTHOR: Morgan Visnesky
	DATE: 09/07/2020
 	FILENAME: ece0301_ICA05_step10.cpp
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
void displayTruthTable(ofstream &, int);
void displayTruthTableCpos(ofstream &, int);
bool andThreeGate(bool, bool, bool);
 

// declarations for min and max term functions
string minTerm(int);
string maxTerm(int);
bool minTerm(bool, bool, bool, int);
bool maxTerm(bool, bool, bool, int);
string csop(int);
string cpos(int);
bool csop(bool, bool, bool, int);
bool cpos(bool, bool, bool, int);


int main(){
	
	// Displays starting message to the standard output
	cout << "ECE 0301: Boolean Functions of 3 Variables." << endl << "Realization in Canonical Forms." << endl;
	
	// creates file instream object
	ifstream fileIn;
	string line1;
	string line2;
	
	// declares variables to hold number from the input file
	//int numFromFile;
	
	// opens input file
	fileIn.open("Bool_func_3var.txt");
	
	// initializes numFromFile with the the number taken from the input file
	getline(fileIn, line1);
	getline(fileIn, line2);
	int numFromFile = stoi(line2.substr(16), nullptr);
	
	
	// creates file outstream object
	ofstream fileOut;
	
	// opens output file
	fileOut.open("Bool_func_3var_CSOP_CPOS.txt");
	// Sends message header to the output file
	fileOut << "ECE 0301: Boolean Functions of 3 Variables." << endl << "Realization in Canonical Forms." << endl << endl;
	
	// Displays and formats lines for output file that display the result 
	// from the CSOP and CPOS functions.
	fileOut << "CSOP: "<< "f" << numFromFile << " = " << csop(numFromFile) << endl << endl;
	
	displayTruthTable(fileOut, numFromFile);
	fileOut << endl;
	
	fileOut << "CPOS: " << "f" << numFromFile << " = " << cpos(numFromFile) << endl << endl;
	displayTruthTableCpos(fileOut, numFromFile);
	
	return 0;
}


string csop(int num){
	string csopOut = "";
	string csopStringOut = "";
	// Edge case to ensure the number from the input file is between 0-255
	if (num > 255 || num < 0){
		cout << "ERROR! Function index out of range." << endl;
	}
	
	for (int i = 7; i >= 0;i--){
		int x = (num >> i) %2;
		csopOut.append(to_string(x));
		if (x == 1){
			if (i != 0){
				csopStringOut.append(minTerm(7-i)+ " + ");
			}
			else 
			{
				csopStringOut.append(minTerm(7-i));
			}
		}
	}
	return csopStringOut;
}

string cpos(int num){
	string csopOut = "";
	string csopStringOut = "";
	// Edge case to ensure the number from the input file is between 0-255
	if (num > 255 || num < 0){
		cout << "ERROR! Function index out of range." << endl;
	}
	
	for (int i = 0; i < 7;i++){
		int x = (num >> i) %2;
		csopOut.append(to_string(x));
		if (x == 1){
			if (i != 0){
				csopStringOut.append("(" + maxTerm(i) + ")");
			}
			else 
			{
				csopStringOut.append("(" + maxTerm(i) + ")");
			}
		}
	}
	return csopStringOut;
}

bool csop(bool x, bool y, bool z, int num){
	string csopOut = "";
	string csopStringOut = "";
	bool returnVal = 0;
	// Edge case to ensure the number from the input file is between 0-255
	if (num > 255 || num < 0){
		cout << "ERROR! Function index out of range." << endl;
	}
	
	for (int i = 7; i >=0;i--){
		int temx = (num >> i) %2;
		if (temx ==1){
			bool temp = returnVal || minTerm(x,y,z, 7-i);
			returnVal = temp;
		}
	}
	return returnVal;
}

bool cpos(bool x, bool y, bool z, int num){
	string csopOut = "";
	string csopStringOut = "";
	bool returnVal = 1;
	// Edge case to ensure the number from the input file is between 0-255
	if (num > 255 || num < 0){
		cout << "ERROR! Function index out of range." << endl;
	}
	
	for (int i = 7; i >=0;i--){
		int temx = (num >> i) %2;
		if (temx ==0){
			bool temp = returnVal && maxTerm(x,y,z, 7-i);
			returnVal = temp;
		}
	}
	return returnVal;
}

bool minTerm(bool x, bool y, bool z, int num){
	
	string stringOut = "";
	
	int i = num%2;
	int j = (num >> 1) %2;
	int k = (num >> 2) %2;
	
	if (k == 0){
		x = !x; 
	}
	else {
		x = x;
	}
	
	if (j == 0){
		y = !y;
	}
	else {
		y = y;
	}
	
	if (i == 0){
		z = !z;
	}
	else {
		z = z;
	}
	
	return andThreeGate(x,y,z);
}

bool maxTerm(bool x, bool y, bool z, int num){
	
	int i = num%2;
	int j = (num >> 1) %2;
	int k = (num >> 2) %2;
	
	if (k == 0){
		x = x; 
	}
	else {
		x = !x;
	}
	
	if (j == 0){
		y = y;
	}
	else {
		y = !y;
	}
	
	if (i == 0){
		z = z;
	}
	else {
		z = !z;
	}
	
	return orThreeGate(x,y,z);
}

string minTerm(int num){
	// This function takes a number between 0-7 as input, it then calculates
	// the minterm and returns a string representation of it.
	
	// Declares variable to hold return string
	string minTermOut;
	
	// Edge case to ensure the number from the input file is between 0-7
	if (num > 7 || num < 0){
		cout << "ERROR! Invalid minterm index." << endl;
	}
	
	// declares temp variables initialized to expressions to hold bit values
	bool z = num%2;	// least significant bit
	bool y = (num >> 1) %2; // middle bit
	bool x = (num >> 2) %2; // most significant bit
	
	// if - else statments to translate the conveted bits into the new
	// representation of the min term.
	if (x == 0){
		minTermOut.append("x\'");
	}
	else
	{
		minTermOut.append("x");
	}
	
	if (y == 0){
		minTermOut.append("y\'");
	}
	else
	{
		minTermOut.append("y");
	}
	
	if (z == 0){
		minTermOut.append("z\'");
	}
	else
	{
		minTermOut.append("z");
	}
	// returns minTerm
	return minTermOut;
}

string maxTerm(int num){
	// This function takes a number between 0-7 as input, it then calculates
	// the maxterm and returns a string representation of it.
	
	// Declares variable to hold return string
	string maxTermOut;
	
	// Edge case to ensure the number from the input file is between 0-7
	if (num > 7 || num < 0){
		cout << "ERROR! Invalid maxterm index." << endl;
	}
	
	// declares temp variables initialized to expressions to hold bit values
	bool z = num%2;	// least significant bit
	bool y = (num >> 1) %2; // middle bit
	bool x = (num >> 2) %2; // most significant bit
	
	// if - else statments to translate the conveted bits into the new
	// representation of the max term.
	if (x == 0){
		maxTermOut.append("x + ");
	}
	else
	{
		maxTermOut.append("x\' + ");
	}
	
	if (y == 0){
		maxTermOut.append("y +");
	}
	else
	{
		maxTermOut.append("y\' +");
	}
	
	if (z == 0){
		maxTermOut.append(" z");
	}
	else
	{
		maxTermOut.append(" z\'");
	}
	// returns maxTerm
	return maxTermOut;
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

void displayTruthTable(ofstream &outputFile, int num){
	// Takes an ofstream object as argument (the argument is passed to the parameter as reference.
	
	bool x, y, z;
	
	// If the provided argument is 1 (true) the following and case will be triggered,
	// which displays the truth table for a three input OR gate in the output file.
	
	// Displays header for the AND gate to the output file.
	outputFile << "Truth table for CSOP form of function " << num << "." << endl << endl;
	outputFile << "x\ty\tz\tf(x,y,z)" << endl;
	outputFile << "--------------------------------" << endl;
		
	// for loop to iterate  
	for (int i = 0; i <= 7; i++){
		
		// stores the bit values for the number of the current iteration in x,y,z variables
		z = i%2;	// least significant bit
		y = (i >> 1) %2; // middle bit
		x = (i >> 2) %2; // most significant bit
			
		// adds values from current iteration to the truth table in the output file.
		outputFile << x <<"\t"<< y<<"\t"<< z << "\t"<< csop(x,y,z, num) << endl;
	}
}

void displayTruthTableCpos(ofstream &outputFile, int num){
	// Takes an ofstream object as argument (the argument is passed to the parameter as reference.
	
	bool x, y, z;
	
	// If the provided argument is 1 (true) the following and case will be triggered,
	// which displays the truth table for a three input OR gate in the output file.
	
	// Displays header for the AND gate to the output file.
	outputFile << "Truth table for CPOS form of function " << num << "." << endl << endl;
	outputFile << "x\ty\tz\tf(x,y,z)" << endl;
	outputFile << "--------------------------------" << endl;
		
	// for loop to iterate  
	for (int i = 0; i <= 7; i++){
		
		// stores the bit values for the number of the current iteration in x,y,z variables
		z = i%2;	// least significant bit
		y = (i >> 1) %2; // middle bit
		x = (i >> 2) %2; // most significant bit
			
		// adds values from current iteration to the truth table in the output file.
		outputFile << x <<"\t"<< y<<"\t"<< z << "\t"<< cpos(x,y,z, num) << endl;
	}
}
	
