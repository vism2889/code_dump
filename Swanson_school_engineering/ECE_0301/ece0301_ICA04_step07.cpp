/*
	AUTHOR: Morgan Visnesky
	DATE: 09/04/2020
 	FILENAME: ece0301_ICA04_step07.cpp
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
	
	
	
	// store value of the first line of the file into the valiable "firstLine"
	inputFile >> firstLine;
	
	// Creates an out filestream object to write to a solutions .txt file
	ofstream lineOut;
	lineOut.open("divider_wheatstone_solutions.txt");
	
	// if statement to hold the logic for computing voltage "Divider" files
	if (firstLine == "Divider"){
		// declares variables used for the voltage divider option
		int r1, r2;
		double vs;
		
		
		
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
		
		// reads 7 lines from the file that hold the values for Vs, Is, R1-R5
		double v_s, i_s;
		int r1, r2, r3, r4, r5;
		inputFile >> v_s;
		inputFile >> i_s;
		inputFile >> r1 >> r2 >> r3 >> r4 >> r5;
		
		// performs the divide by zero checks provided in the assignment's problem statements
		if ((r2 ==0 ) || (r3 ==0) || ((v_s-(i_s*r4) > -10e-13) && (v_s-(i_s*r4) < 10e-13)) || ((v_s+(i_s*r5) > -10e-13) && (v_s+(i_s*r5) < 10e-13))){
			// Divide by zero error
			cout << "ERROR! Unstable floating-point division.";
			return -1;
		}
		
		
		// sends message to the outputFile with the same header the is displayed to the standard output when the program starts
		lineOut << "ECE 0301: Circuit Solver for Voltage Divider" << endl << "and Wheatstone bridge example circuits." << endl;
		
		// sends message to the outputFile indicating that the user has selected a "Divider" file
		lineOut << "-----" << endl << "Circuit #1 (Wheatstone Bridge)" << endl << "---" << endl;
		
		//sends message to the outputFile indicating the values for source voltage and resistors r1 and r2
		lineOut << "Source voltage: Vs = " << v_s << " Volts." << endl;
		lineOut << "Source current: Is = " << i_s << " Amperes." << endl;
		lineOut << "Resistor: R1 = " << r1 << " Ohms." << endl;
		lineOut << "Resistor: R2 = " << r2 << " Ohms." << endl;
		lineOut << "Resistor: R3 = " << r3 << " Ohms." << endl;
		lineOut << "Resistor: R4 = " << r4 << " Ohms." << endl;
		lineOut << "Resistor: R5 = " << r5 << " Ohms." << endl << endl;
		
		// declares variables to hold voltage and current values
		double i1, i2, i3, i4, i5, v1, v2, v3, v4, v5;
		
		
		// declares and initializes variables for a-f with expressions that 
		// represent thier values, using the values taken from the input file.
		double a = 1 + (static_cast<double>(r4)/r2);
		double c = 1 + (static_cast<double>(r5)/r3);
		double b = v_s - (i_s*r4);
		double d = v_s + (i_s*r5);
		double e = static_cast<double>(r1)/r2;
		double f = static_cast<double>(r1)/r3;
		
		// declares and initializes variables for w-z with expressions that represent thier values.
		double w = (a+e)/b;
		double x = (f/b);
		double y = (e/d);
		double z = (c+f)/d;
		
		// does the computations to initialize v1-v5 with equations 
		// that are using our known values up to this point.
		v3 = (y-w)/((x*y) - (w*z));
		v2 = (1-(x*v3))/w;
		v1 = e*v2 + f*v3;
		v4 = v_s - v1 - v2;
		v5 = v_s - v1 - v3;
		
		// uses ohms law to find the currents i1-i5 using v1-v5 and r1-r5.
		i1 = v1/r1;
		i2 = v2/r2;
		i3 = v3/r3;
		i4 = v4/r4;
		i5 = v5/r5;
		
		// sends messages to the output file to display the calulated voltage and current values 
		// for each of the 5 resistors.
		lineOut << "Resistor voltage: V1 = " << v1 << " Volts." << endl;
		lineOut << "Resistor current: I1 = " << i1 << " Amperes." << endl;
		
		lineOut << "Resistor voltage: V2 = " << v2 << " Volts." << endl;
		lineOut << "Resistor current: I2 = " << i2 << " Amperes." << endl;
		
		lineOut << "Resistor voltage: V3 = " << v3 << " Volts." << endl;
		lineOut << "Resistor current: I3 = " << i3 << " Amperes." << endl;
		
		lineOut << "Resistor voltage: V4 = " << v4 << " Volts." << endl;
		lineOut << "Resistor current: I4 = " << i4 << " Amperes." << endl;
		
		lineOut << "Resistor voltage: V5 = " << v5 << " Volts." << endl;
		lineOut << "Resistor current: I5 = " << i5 << " Amperes." << endl;
		
		
	}
	
	else{
		// sends message to standard output that alerts the user about an invalid header in the file they opened.
		cout << "ERROR! Invalid header." << endl;
		return -1;
	}
	
	// closes the outputFile
	lineOut.close();
	return 0;	
}
