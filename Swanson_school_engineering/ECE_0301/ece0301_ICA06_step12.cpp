/*
	AUTHOR: Morgan Visnesky
	DATE: 09/16/2020
 	FILENAME: ece0301_ICA06_step12.cpp
	DESCRIPTION:
	* This is in class assignment #6   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	This assignment covers cramers rule and matrix vector operations.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "array_dim.h"




using namespace std;

// function prototypes for functions declared outside of main()
int getN(ifstream &, double [][DIM], double [DIM]);
void displayEquation(int, double[][DIM], double[DIM], ofstream &, double[DIM]);
void matrixMultiply(double[][DIM], double[DIM], double[DIM]);
void matrixDisplay( double[][DIM], int, ofstream &);
void upperLeft(double[][DIM], double[][DIM], int, int, int);
double det(double[][DIM], int);
void colReplace(double[][DIM], double[DIM], double[][DIM], int);


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
	
	// declares arrays to hold the values from the inputfile for 'A', 'b', 
	// and the calculated prodcut vector x
	double a[DIM][DIM];
	double b[DIM];
	double x[DIM];
	
	double product[DIM];
	
	//grabs dimensions from the input file
	int fileDimensions = getN(fileIn, a, b);
	
	// variables used to test our function that removes rows and cols
	int i = 1, j=2, n=DIM;
	
	// displays the formatted equation 'Ax =b' to the output file.
	matrixDisplay(a, n, fileOut);
	
	// declares used by the function upperLeft, which is used to copy the specified 
	// upperleft portion of a 2D array.
	double copyArray[DIM][DIM];
	
	// call to the upper left function to test it
	upperLeft(a, copyArray, i, j, DIM);
	
	// declares variable to store the determinant and then initializes it
	// with a call to the det() function.
	double detVal = det(a, DIM);
	
	// Displays the determinant to the output file.
	fileOut << "det(A) = " << detVal;
	

	// closes the input file.
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
	}
	
	// returns the file dimensions
	return val;
};

void displayEquation(int N, double arrayA[][DIM], double arrayB[DIM], ofstream &fileOut, double arrayX[DIM]){
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
	
	
	// The code below displays a formatted version of 
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
	
		
		
	// EQUATION OUTPUT
	// Code below is used to format and output the formatted equation 'Ax=b'	
	fileOut << "A * x = b" << endl;
	for (int i = 0; i < N; i++){
		fileOut << "[";
		for (int j = 0; j < N; j++){
			fileOut << setw(10) << arrayA[i][j];
		}
		
		//logic to handle where the '*' and '=' sign is placed in the formatted
		// output.
		if (i == (ceil(DIM/2))){
			fileOut << "] * [";
			fileOut << setw(10) << arrayX[i];
			fileOut << "] = [";
		}
		else 
		{
			fileOut << "]   [";
			fileOut << setw(10) << arrayX[i];
			fileOut << "]   [";
		}
		
		//outputs last col with vals from 'b' array.
		fileOut << setw(10) << arrayB[i];
		fileOut << "]" << endl;;
		 
	}
	
};

void matrixDisplay( double array2[][DIM], int N, ofstream &fileOut){
	for (int i = 0; i < N; i++){
		fileOut << "[";
		for (int j = 0; j < N; j++){
			
			fileOut << setw(10) << array2[i][j];
		}
		fileOut << "]" << endl;
	}
};



void matrixMultiply(double arrayA[][DIM], double arrayX[DIM], double arrayProduct[DIM]){
	// this function takes in a 2D array representing a matrix and a 1D array representing a
	// vector, and a 1D array to store the result. It performs the operations to complete
	// matrix - vector multiplication.
	
	// initializes product array to 0's
	for (int i = 0; i < DIM; i++){
		arrayProduct[i] = 0;
	}
	
	// for loop to compute the matrix vector product
	for (int i = 0; i < DIM; i++){
		// again to make sure product array values are being incremented from 0
		arrayProduct[i] = 0;
		for (int j = 0; j < DIM; j++){
			arrayProduct[i] += arrayA[i][j] * arrayX[j];
		}
	}
};

void upperLeft(double arrayA[][DIM], double newArrayA[][DIM], int i, int j, int n){
	// This function is used to copy a specified upper left portion of a matrix and copy it into a new matrix with 
	// specified rows and cols removed.  n represents the number of rows of the matrix to copy.
	// It takes the 'A' array, a new array to store the copy portion of A in, the int variables 'i' and 'j', 
	// which specify the rows and cols to be excluded, and n, to specifiy the first 'n' rows to be copied.
	
	// initializes a temporary counter used to skip over specified row
	int temp = 0;
	
	// outer loop handles rows
	for (int k = 0; k < DIM; k++){
		
		// if k=specified row to remove, skip over it
		if (k == i){
			k++;
		}
		// initializes a temporary counter used to skip over specified col
		int temp2 = 0;
		// inner loop handles cols
		for (int l = 0; l < DIM; l++){
			
			// if l=specified col to remove, skip over it
			if (l == j){
				l++;
			}
			// stores values into the new array
			newArrayA[temp][temp2] = arrayA[k][l];
			
			// increments col counter variable
			temp2++;
		}
		// increments row counter variable
		temp ++;
	}
};

double det(double arrayA[][DIM], int n){
	// this function performs the operations to find the determinant of a 
	// matrix and returns that value.  It takes in the array 'A' and an integer n
	// that is used in the recursive calls to the upperLeft function to specify what parts
	// of the submatrix to copy.
	
	// for a one by one matrix, the determinant is that value of the matrix
	if (n ==1){
		return arrayA[0][0];
	}
	
	// initializes the return variable for the determinant to 0
	double detVal = 0;
	
	//creates a 2D array to hold the submatrix in
	double subMatrix[DIM][DIM];
	
	
	// loop that makes recursive calls to det() function until j = n
	for (int j = 0; j < n; j++){
		upperLeft(arrayA, subMatrix, 0, j, n-1);
		double val = det(subMatrix, n-1);
		detVal += val*pow(-1,j)*arrayA[0][j];
			
	}
	
	// returns the calculated value of the determinant
	return detVal;
	
};

void colReplace(double arrayA[][DIM], double arrayB[DIM], double arrayCopy[][DIM], int colNum){
	// Takes in the arrays for 'A', 'b', and a copyArray to store the new array with a replaced column in it.
	// The array replaces the specified column with the values from the 'b' vector.
	
	// variables used to help skip over specified column
	int temp = 0;
	
	// for-loop to handle copying values from 'A' and values from 'b' into their correpsonding correct locations
	// in the copy matrix.
	for (int i = 0; i < DIM; i++){
		for (int j = 0; j < DIM; j++){
			if (j == colNum){
				
				// adds 'b' values into the copy matrix
				arrayCopy[i][temp] = arrayB[temp];
			}
			// adds the correct 'A' values into the copy matrix
			arrayCopy[i][temp] = arrayA[i][j];
			
			// increments the skip-counter variable
			temp++;
		}
	}
};
