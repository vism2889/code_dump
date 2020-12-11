/*
	AUTHOR: Morgan Visnesky
	DATE: 08/31/2020
 	FILENAME: ece0301_ICA03_step06.cpp
	DESCRIPTION:
	* This is in class assignment #3 for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.
	
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

const double pi = 4 * atan(1.0);
using namespace std;

int main() {
	
	// Declares variables to hold users numbers for first input.
	double number1, number2;
	
	
	// FIRST USER PROMPT TO GET NUMBERS
	
	// Displays introductory message to the standard output.
	cout << "ECE 0301 -  Vectors in R2 and Complex Numbers" << endl;
	cout << "Please enter two numbers, separated by a space," << endl;
	cout << "that will represent a vector or a complex number." << endl;
	
	
	
	// Takes user input of two numbers and stores them in variables number1 and number2 respectively.
	cin >> number1 >> number2;
	
	// Displays the values the user has just entered in fixed point notation.
	cout << setprecision(3) << fixed << "You entered " << number1 << " and " << number2 << "." << endl << endl;
	
	
	char userChoice;
	
	// Instructs user to choose 'c' or 'p' to denote cartesian or polar coordinates respectively.
	cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?" << endl;
	cout << "Please enter a single character as your choice." << endl;
	
	// Takes user input and stores it in the userChoice variable.
	cin >> userChoice;
	
	// Declares variables to hold values for conversions between Cartesian and polar coordinates.
	double x, y, r, theta;
	
	// Switch statement to handle the conversion type depending on the users choice.
	switch (userChoice){
		
		// Cases 'c' and 'C' which handle the cartesian to polar conversion.
		case 'c':
		case 'C':
			
			// Initializes variables x and y with user inputs number1 and number2 respectively.
			x = number1;
			y = number2;
			
			// The if / else if block below handles the logic and calculations to determine
			// the value of theta depending on the values provided for x and y.
			if (x >= 0){
				theta = atan(y/x);
			}
			else if (x < 0 && y >= 0){
				theta = atan(y/x) + pi;
			}
			else if (x < 0 && y < 0){
				theta = atan(y/x) - pi;
			}
			
			// Calculation to determine the value of r.
			r = sqrt(pow(x,2)+pow(y,2));
			
			// Displays the Cartesian to polar conversion to the standard output.
			cout << "You entered Cartesian coordinates." << endl;
			cout << "The equivalent polar coordinates are:" << endl;
			cout << "R = " << r << ", theta = " << theta << endl;
			break;
		
		// Cases 'p' and 'P' which handle the polar to cartesian conversion.
		case 'p':
		case 'P':
			
			// Initializes r and theta with the user inputs number1 and number2 respectively. 
			r = number1;
			theta = number2;
			
			// Checks to make sure r is greater than zero and that the given value
			// for theta is between negative pi and positive pi.
			if (r < 0 || theta > pi || theta < -pi) {
				// Displays error message if user inputs are not valid.
				cout << "ERROR! Invalid polar coordinates, exiting." << endl;
				return -1;
			}
			
			// Initializes x and y with expressions that yield thier respective values from
			// the user provided r and theta.
			x = r * cos(theta);
			y = r * sin(theta);
			
			// Displays the polar to Cartesian conversion to the standard output.
			cout << "You entered polar coordinates." << endl;
			cout << "The equivalent Cartesian coordinates are:" << endl;
			cout << "x = " << x << ", y = " << y << endl;
			break;
		
		// Default statement that is displayed to the output if the user does not enter 
		// one of the following ('c', 'C', 'p', 'P').
		default:
			cout << "ERROR! Invalid selection, exiting.";
			return -1;
		}
		
		
	// SECOND USER PROMPT TO GET NUMBERS
		
	// Declares variables to hold users number inputs for the second conversion.
	double number3, number4;
	
	// Displays message to the standard output asking for a new pair of numbers.
	cout << "Please enter another pair of numbers, separated by a" << endl;
	cout << "space, to represent a second vector or a complex number." << endl << endl;
	
	
	
	// Grabs user input for number3 and number4.
	cin >> number3 >> number4;
	
	// Displays the values the user has just entered in fixed point notation
	cout << setprecision(3) << fixed << "You entered " << number3 << " and " << number4 << "." << endl << endl;
	
	
	char userChoice2;
	
	// Instructs user to choose 'c' or 'p' to denote cartesian or polar coordinates respectively.
	cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?" << endl;
	cout << "Please enter a single character as your choice." << endl;
	
	cin >> userChoice2;
	
	// Declares variables to hold values for second conversion between Cartesian or polar coordinates.
	double x2, y2, r2, theta2;
	
	// Switch statement to handle the conversion type depending on the users choice.
	switch (userChoice2){
		
		// Cases 'c' and 'C' which handle the cartesian to polar conversion.
		case 'c':
		case 'C':
			
			// Initializes variables x and y with user inputs number3 and number4 respectively.
			x2 = number3;
			y2 = number4;
			
			// The if / else if block below handles the logic and calculations to determine
			// the value of theta depending on the values provided for x2 and y2.
			if (x2 >= 0){
				theta2 = atan(y2/x2);
			}
			else if (x2 < 0 && y2 >= 0){
				theta2 = atan(y2/x2) + pi;
			}
			else if (x2 < 0 && y2 < 0){
				theta2 = atan(y2/x2) - pi;
			}
			
			// Calculation to determine the value of r2.
			r2 = sqrt(pow(x2,2)+pow(y2,2));
			
			// Displays the second Cartesian to polar conversion to the standard output.
			cout << "You entered Cartesian coordinates." << endl;
			cout << "The equivalent polar coordinates are:" << endl;
			cout << "R = " << r2 << ", theta = " << theta2 << endl;
			break;
		
		// Cases 'p' and 'P' which handle the polar to cartesian conversion.
		case 'p':
		case 'P':
			
			// Initializes r and theta with the user inputs number1 and number2 respectively. 
			r2 = number3;
			theta2 = number4;
			
			// Checks to make sure r2 is greater than zero and that the given value
			// for theta is between negative pi and positive pi.
			if (r2 < 0 || theta2 > pi || theta2 < -pi) {
				cout << "ERROR! Invalid polar coordinates, exiting." << endl;
				return -1;
			}
			
			// Initializes x and y with expressions that yield thier respective values from
			// the user provided r and theta.
			x2 = r2 * cos(theta2);
			y2 = r2 * sin(theta2);
			
			// Displays the second polar to Cartesian conversion to the standard output.
			cout << "You entered polar coordinates." << endl;
			cout << "The equivalent Cartesian coordinates are:" << endl;
			cout << "x = " << x2 << ", y = " << y2 << endl;
			break;
		
		// Default statement that is displayed to the output if the user does not enter 
		// one of the following ('c', 'C', 'p', 'P').
		default:
			cout << "ERROR! Invalid selection, exiting.";
			return -1;
		}
		
		
	return 0;
}
