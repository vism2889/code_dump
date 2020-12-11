 /*
	AUTHOR: Morgan Visnesky
	DATE: 09/16/2020
 	FILENAME: ece0301_ICA06_step07.cpp
	DESCRIPTION:
	* This is in class assignment #6   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	This assignment covers cramers rule and matrix vector operations.
*/


// include statements to call upon required 
// c++ libraries.
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "array_dim.h"




using namespace std;

// function prototypes for functions declared outside of main
// getN() which grabs values from an input file and 
// displayEquation which displays a formatted equation to the output file.

int getN(ifstream &, double [][DIM], double [DIM]);
void displayEquation(int, double[][DIM], double[DIM], ofstream &);


// Main function
int main() {
	
	// declares ofstream object to write to an ouput file
	// then opens that file.
	ofstream fileOut;
	fileOut.open("ECE0301_ICA06_Axeqb_solution.txt");
	
	// declares ifstream object to read from an input file
	// then opens that file.
	ifstream fileIn;
	fileIn.open("ECE0301_ICA06_Axeqb_problem.txt");
	
	// declares a 2D array to hold the values of 'A' from the input file
	double a[DIM][DIM];
	
	// declares a 1D array to hold the values of 'b' from the input file
	double b[DIM];
	
	// variable initialized to the 'input file' dimension via use of the getN function 
	// which reads from the input file
	int fileDimensions = getN(fileIn, a, b);
	
	// call to displayEquation which writes the full equation 'Ax=b' to the 
	// output file.
	displayEquation(fileDimensions, a, b, fileOut);
	
	
	// closes input file
	fileIn.close();
	return 0;
}



int getN(ifstream &fileInput, double arrayA[][DIM], double arrayB[DIM]){
	// getN is a function that takes an ifstream object passed by reference, a 2D array
	// that is used to hold the 'A' values from an input file, and a 1D array that
	// stores the 'b' values from the input file.
	
	// declares string valirable to compare to first line of the input file to 
	// verify it will work correctly
	string requiredHeader = "ECE 0301: Ax = b Problem";
	
	// variable to hold input from firstline of input file
	string headerLine;
	
	// variable to hold input from the line containing the dimension number
	string numLine;
	
	// variable that holds the required dimensions from the header file
	int cols = DIM;
	
	// grabs headerline with getline() function
	getline(fileInput, headerLine);
	
	// tests to make sure the header is correct for the input file, and stops
	// the program if it is incorrect.
	if (headerLine != requiredHeader){
		cout << "ERROR! Input file format error.";
		return -1;
	}
	
	//grabs the line containing the dimension number from the input file
	getline(fileInput, numLine);
	
	// converts the number in the numberline into an integer.
	int val = stoi(numLine.substr(3), nullptr);
	
	
	// displays a header and the value for dimension taken form the input file
	cout << "Value for DIM in file: " << val << endl;
	
	// stops program if the dimension taken from the input file does not match
	// the one in the header file
	if (val != DIM){
		cout << "ERROR! Dimension mismatch, N != DIM.";
		return -1;
	}
	
	// variable to hold the values of 'A' and 'b' as they are read into arrays
	// to store them in our program.
	string line;
	
	
	// grabs the next line and makes sure it is correctly formatted or
	// it stops the program.
	getline(fileInput, line); // should be 'A ='
	if (line != "A = "){
		cout << "ERROR! Input file format error.";
		return -1;
	}
	
	// for-loop used to iterate over the lines of the input file and grab
	// the values for 'A' and store them in our arrayA.
	for (int i = 0; i < cols; i++){
		for (int j = 0; j < DIM; j++){
			getline(fileInput, line);
			double matrixVal = std::atof(line.substr(0).c_str());
			arrayA[i][j] = matrixVal;
		}
	}
	
	// grabs the next line and makes sure it is correctly formatted or
	// it stops the program.
	getline(fileInput, line); // should be 'b ='
	if (line != "b = "){
		cout << "ERROR! Input file format error.";
		return -1;
	}
	
	// for-loop used to iterate over the lines of the input file and grab
	// the values for 'b' and store them in our arrayB.
	for (int i = 0;i < DIM; i++){
		getline(fileInput, line);
		double matrixVal = std::atof(line.substr(0).c_str());
		arrayB[i] = matrixVal;
		cout <<"B: " <<  arrayB[i] << endl;
	}
	
	// returns the file dimensions
	return val;
};

void displayEquation(int N, double arrayA[][DIM], double arrayB[DIM], ofstream &fileOut){
	// This is a function that is used to display data to our output file
	// it takes an integer N that represents the dimension from the input file, 
	// a 2D array that contains the values for 'A', a 1D array that contains the values
	// for 'b', and an ofstream object poassed by reference that is used to send 
	// data to the outputfile.
	
	// Displays an intro message to the output file
	fileOut << "ECE - 0301 Matrix-Vector Computations," << endl;
	fileOut << "Determinants and Cramers Rule." << endl << endl;
	
	// Displays the global, and input file dimensions which should match.
	fileOut << "Global array dimension: DIM = " << DIM << endl;
	fileOut << "Input file: N = " << N << endl << endl;
	
	// The code below this point displays a formatted version of 
	// the 'A' and 'b' matrices to the outputfile
	fileOut << "A =" << endl;
	
	for (int i = 0; i < N; i++){
		fileOut << "[";
		for (int j = 0; j < N; j++){
			
			fileOut << setw(10) << arrayA[i][j];
		}
		fileOut << "]" << endl;
	}
	fileOut << endl << "b =" << endl;
	for (int i = 0; i < N; i++){
		fileOut << "[" << setw(10) << arrayB[i] << "]" << endl;
	}
		
	
};

