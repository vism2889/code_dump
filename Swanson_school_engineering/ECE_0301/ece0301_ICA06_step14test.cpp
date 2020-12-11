/*
	AUTHOR: Morgan Visnesky
	DATE: 09/16/2020
 	FILENAME: ece0301_ICA06_step07.cpp
	DESCRIPTION:
	* This is in class assignment #6   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	This assignment covers boolean logic, binary representation of numbers, and POS and SOP.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "array_dim.h"




using namespace std;

int getN(ifstream &, double [][DIM], double [DIM]);
void displayEquation(int, double[][DIM], double[DIM], ofstream &, double[DIM]);
void matrixMultiply(double[][DIM], double[DIM], double[DIM]);
void matrixDisplay( double[][DIM], int, ofstream &);
void upperLeft(double[][DIM], double[][DIM], int, int, int);
double det(double[][DIM], int);
void colReplace(double[][DIM], double[DIM], double[][DIM], int);

int main() {
	
	
	ofstream fileOut;
	fileOut.open("ECE0301_ICA06_Axeqb_solution.txt");
	
	ifstream fileIn;
	fileIn.open("ECE0301_ICA06_Axeqb_problem.txt");
	
	double a[DIM][DIM];
	double b[DIM];
	double x[DIM];
	double product[DIM];
	int fileDimensions = getN(fileIn, a, b);
	int i = 1, j=2, n=DIM;
	
	matrixDisplay(a, n, fileOut);
	double copyArray[DIM][DIM];
	
	upperLeft(a, copyArray, i, j, DIM);
	double detVal = det(a, DIM);
	fileOut << "det(A) = " << detVal << endl;
	
	double colRep[DIM][DIM];
	for (int i = 0;i < DIM; i++){
		colReplace(a,b,colRep,i);
		matrixDisplay(colRep, DIM, fileOut);
		fileOut << "colRep -"<< i << ": "<< det(colRep, DIM) << endl;
	}

	
	fileIn.close();
	return 0;
}

int getN(ifstream &fileInput, double arrayA[][DIM], double arrayB[DIM]){
	string requiredHeader = "ECE 0301: Ax = b Problem";
	string headerLine;
	string numLine;
	int cols = DIM;
	
	getline(fileInput, headerLine);
	
	if (headerLine != requiredHeader){
		cout << "ERROR! Input file format error.";
		return -1;
	}
	
	getline(fileInput, numLine);
	int val = stoi(numLine.substr(3), nullptr);
	
	
	//cout << "Value for DIM in file: " << val << endl;
	if (val != DIM){
		cout << "ERROR! Dimension mismatch, N != DIM.";
		return -1;
	}
	
	string line;
	getline(fileInput, line); // should be 'A ='
	if (line != "A = "){
		cout << "ERROR! Input file format error.";
		return -1;
	}
	for (int i = 0; i < cols; i++){
		for (int j = 0; j < DIM; j++){
			getline(fileInput, line);
			//cout << "LINE " << line << endl;
			//cout << line << endl;
			//cout << int(line[3]);
			double matrixVal = std::atof(line.substr(0).c_str());
			//cout << "MATRIX VAL :" << matrixVal << endl;
			arrayA[i][j] = matrixVal;
			//cout << "FROM ARRAY A: "<< arrayA[i][j] << " " << endl;
		}
	}
	getline(fileInput, line); // should be 'b ='
	if (line != "b = "){
		cout << "ERROR! Input file format error.";
		return -1;
	}
	for (int i = 0;i < DIM; i++){
		getline(fileInput, line);
		double matrixVal = std::atof(line.substr(0).c_str());
		arrayB[i] = matrixVal;
		//cout <<"B: " <<  arrayB[i] << endl;
	}
	
	return val;
};

void displayEquation(int N, double arrayA[][DIM], double arrayB[DIM], ofstream &fileOut, double arrayX[DIM]){
	fileOut << "ECE - 0301 Matrix-Vector Computations," << endl;
	fileOut << "Determinants and Cramers Rule." << endl << endl;
	
	fileOut << "Global array dimension: DIM = " << DIM << endl;
	fileOut << "Input file: N = " << N << endl << endl;
	
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
	cout << endl;
		
		
	// EQUATION OUTPUT	
	fileOut << "A * x = b" << endl;
	for (int i = 0; i < N; i++){
		fileOut << "[";
		for (int j = 0; j < N; j++){
			fileOut << setw(10) << arrayA[i][j];
		}
		
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
	for (int i = 0; i < DIM; i++){
		arrayProduct[i] = 0;
	}
	for (int i = 0; i < DIM; i++){
		arrayProduct[i] = 0;
		for (int j = 0; j < DIM; j++){
			arrayProduct[i] += arrayA[i][j] * arrayX[j];
		}
		cout << arrayProduct[i] << endl;
	}
};

void upperLeft(double arrayA[][DIM], double newArrayA[][DIM], int i, int j, int n){
	int temp = 0;
	
	
	for (int k = 0; k < DIM; k++){
		if (k == i){
			k++;
		}
		int temp2 = 0;
		for (int l = 0; l < DIM; l++){
			
			if (l == j){
				l++;
			}
			newArrayA[temp][temp2] = arrayA[k][l];
			//cout << "new" << newArrayA[temp][temp2] <<endl;
			temp2++;
		}
		temp ++;
	}
};

double det(double arrayA[][DIM], int n){
	
	if (n ==1){
		return arrayA[0][0];
	}
	
	double detVal = 0;
	
	double subMatrix[DIM][DIM];
	
	//for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			upperLeft(arrayA, subMatrix, 0, j, n-1);
			double val = det(subMatrix, n-1);
			detVal += val*pow(-1,j)*arrayA[0][j];
			//return detVal;
		}
	//}
	return detVal;
	
};

void colReplace(double arrayA[][DIM], double arrayB[DIM], double arrayCopy[][DIM], int colNum){
	int temp = 0, temp2 = 0;
	for (int i = 0; i < DIM; i++){
		for (int j = 0; j < DIM; j++){
			if (j == colNum){
				arrayCopy[i][j] = arrayB[i];
				temp++;
			}
			else
			{
				arrayCopy[i][j] = arrayA[i][j];
				temp++;
			}
		}
	}
};

