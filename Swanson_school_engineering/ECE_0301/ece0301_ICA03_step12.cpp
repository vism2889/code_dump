/*
	AUTHOR: Morgan Visnesky
	DATE: 08/31/2020
 	FILENAME: ece0301_ICA03_step12.cpp
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
		
		// Declares variable to hold user choice denoting whether the inputs have been vectors or complex numbers.
		char vectorComplexChoice;
		
		// Displays a message to ask the user whether they have input values 
		// representing vectors or complex numbers.
		cout << "Do the values you entered represent vectors (v) or complex numbers (c)?" << endl;
		cout << "Please enter a single character as your choice." << endl;
		
		// Initializes vectorComplexChoice to the users input.
		cin >> vectorComplexChoice;
		
		
		// ****************             **** Switch case to handle the different vector computations
		switch (vectorComplexChoice){
			case 'v':
			case 'V':
			// The code in this section executes if the vector choice has been made.
			//
			// A message is displayed to the standard output that shows both pairs of numbers that have 
			// been entered in both Cartesian and polar form.
				cout << "Cartesian:\tv1 = (" << x << ", " << y << ")" << endl;
				cout << "Polar:\t\tv1 = (" << r << ", " << theta << ")" << endl << endl;
				
				cout << "Cartesian:\tv2 = (" << x2 << ", " << y2 << ")" << endl;
				cout << "Polar:\t\tv2 = (" << r2 << ", " << theta2 << ")" << endl << endl;
				
				int sumDiffCase;
				
				// Message is displayed to the standard output asking user to choose
				// which computation they would like the program to compute.
				cout << "Which of the following vector sums or differences" << endl;
				cout << "would you like to compute?" << endl;
				cout << "(1) v1 + v2" << endl;
				cout << "(2) v1 - v2" << endl;
				cout << "(3) v2 - v1" << endl;
				cout << "(4) -v1 - v2" << endl << endl;
				
				cin >> sumDiffCase;
				double vectorSumDiffX, vectorSumDiffY, vectorSumDiffR, vectorSumDiffTheta;
				switch (sumDiffCase){
					case 1:
						// Initializes new x, y, and r variables to their new values for case 1 calculation.
						vectorSumDiffX = x + x2;
						vectorSumDiffY = y + y2;
						vectorSumDiffR = sqrt(pow(vectorSumDiffX, 2) + pow(vectorSumDiffY, 2));
						
						// Makes changes to theta based on values of vectorSumDiffX and vectorSumDiffY
						if (vectorSumDiffX >= 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX);
						}
						else if (vectorSumDiffX < 0 && vectorSumDiffY >= 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX) + pi;
						}
						else if (vectorSumDiffX < 0 && vectorSumDiffY < 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX) - pi;
						}
						
						// Displays the result of the calculation to the standard output
						cout << "Sum, Cartesian:\tv_sum = (" << vectorSumDiffX << ", " << vectorSumDiffY << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << vectorSumDiffR << ", " << vectorSumDiffTheta << ")" << endl;
						break;
					
					case 2:
						// Initializes new x, y, and r variables to their new values for case 2 calculation.	
						vectorSumDiffX = x - x2;
						vectorSumDiffY = y - y2;
						vectorSumDiffR = sqrt(pow(vectorSumDiffX, 2) + pow(vectorSumDiffY, 2));
						
						// Makes changes to theta based on values of vectorSumDiffX and vectorSumDiffY
						if (vectorSumDiffX >= 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX);
						}
						else if (vectorSumDiffX < 0 && vectorSumDiffY >= 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX) + pi;
						}
						else if (vectorSumDiffX < 0 && vectorSumDiffY < 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX) - pi;
						}
						
						// Displays the result of the calculation to the standard output
						cout << "Sum, Cartesian:\tv_sum = (" << vectorSumDiffX << ", " << vectorSumDiffY << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << vectorSumDiffR << ", " << vectorSumDiffTheta << ")" << endl;
						break;
					
					case 3:
						// Initializes new x, y, and r variables to their new values for case 3 calculation.
						vectorSumDiffX = x2 - x;
						vectorSumDiffY = y2 - y;
						vectorSumDiffR = sqrt(pow(vectorSumDiffX, 2) + pow(vectorSumDiffY, 2));
						
						// Makes changes to theta based on values of vectorSumDiffX and vectorSumDiffY
						if (vectorSumDiffX >= 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX);
						}
						else if (vectorSumDiffX < 0 && vectorSumDiffY >= 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX) + pi;
						}
						else if (vectorSumDiffX < 0 && vectorSumDiffY < 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX) - pi;
						}
						
						// Displays the result of the calculation to the standard output
						cout << "Sum, Cartesian:\tv_sum = (" << vectorSumDiffX << ", " << vectorSumDiffY << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << vectorSumDiffR << ", " << vectorSumDiffTheta << ")" << endl;
						break;
					
					case 4:
						// Initializes new x, y, and r variables to their new values for case 4 calculation.
						vectorSumDiffX = -x - x2;
						vectorSumDiffY = -y - y2;
						vectorSumDiffR = sqrt(pow(vectorSumDiffX, 2) + pow(vectorSumDiffY, 2));
						
						// Makes changes to theta based on values of vectorSumDiffX and vectorSumDiffY
						if (vectorSumDiffX >= 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX);
						}
						else if (vectorSumDiffX < 0 && vectorSumDiffY >= 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX) + pi;
						}
						else if (vectorSumDiffX < 0 && vectorSumDiffY < 0){
							vectorSumDiffTheta = atan(vectorSumDiffY/vectorSumDiffX) - pi;
						}
						
						// Displays the result of the calculation to the standard output
						cout << "Sum, Cartesian:\tv_sum = (" << vectorSumDiffX << ", " << vectorSumDiffY << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << vectorSumDiffR << ", " << vectorSumDiffTheta << ")" << endl;
						break;
					
					default:
						// Happens when user makes a selection other than (1-4). 
						cout << "ERROR! Invalid selection, exiting.";
						break;
						return -1;
				}
				
				double vectorProductPolar, vectorProductCart;
				vectorProductPolar = r*r2*cos(theta - theta2);
				vectorProductCart = x*x2+y*y2;
				cout << "The inner product of v1 and v2 using polar coordinates is " << vectorProductPolar << endl;
				cout << "The inner product of v1 and v2 using Cartesian coordinates is " << vectorProductCart << endl;
				
				break;
			case 'c':
			case 'C':
				// The code in this section executes if the complex number choice has been made.
				//
				// A message is displayed to the standard output that shows both pairs of numbers that have 
				// been entered in both Cartesian and polar form.
				cout << "Cartesian:\tz1 = " << x << " + j " << y << endl;
				cout << "Polar:\t\tz1 = " << r << " exp(j " << theta << ")" << endl << endl;
				
				cout << "Cartesian:\tz2 = " << x2 << " + j " << y2 << endl;
				cout << "Polar:\t\tz2 = " << r2 << " exp(j " << theta2 << ")" << endl << endl;
				
				// Declares variable that stores value for user choice of which of the 4 computations they have selected.
				int sumDiffCaseComp;
				
				// Message is displayed to the standard output asking user to choose
				// which computation they would like the program to compute.
				cout << "Which of the following complex number sums or differences" << endl;
				cout << "would you like to compute?" << endl;
				cout << "(1) z1 + z2" << endl;
				cout << "(2) z1 - z2" << endl;
				cout << "(3) z2 - z1" << endl;
				cout << "(4) -z1 - z2" << endl << endl;
				
				// Takes input from the user (1-4) based on the menu above and initializes sumDiffCaseComp.
				cin >> sumDiffCaseComp;
				
				// Declares variables to store the resulting x,y,r,and theta values from the user selected 
				// calculation.
				double compSumDiffX, compSumDiffY, compSumDiffR, compSumDiffTheta;
				
				// ****************             **** Switch case to handle the different complex number computations
				switch (sumDiffCaseComp){
					
					case 1:
					
						// Initializes new x, y, and r variables to their new values for case 1 calculation.
						compSumDiffX = x + x2;
						compSumDiffY = y + y2;
						compSumDiffR = sqrt(pow(compSumDiffX, 2) + pow(compSumDiffY, 2));
						
						// Makes changes to theta based on values of compSumDiffX and compSumDiffY
						if (compSumDiffX >= 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX);
						}
						else if (compSumDiffX < 0 && compSumDiffY >= 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX) + pi;
						}
						else if (compSumDiffX < 0 && compSumDiffY < 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX) - pi;
						}
						
						// Displays the result of the calculation to the standard output
						cout << "Sum, Cartesian:\tz_sum = " << compSumDiffX << " + j " << compSumDiffY << endl;
						cout << "Sum, Polar:\tz_sum = " << compSumDiffR << " exp(j " << compSumDiffTheta << ")" << endl;
						break;
					
					case 2:
						// Initializes new x, y, and r variables to their new values for case 2 calculation.
						compSumDiffX = x - x2;
						compSumDiffY = y - y2;
						compSumDiffR = sqrt(pow(compSumDiffX, 2) + pow(compSumDiffY, 2));
						
						// Makes changes to theta based on values of compSumDiffX and compSumDiffY
						if (compSumDiffX >= 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX);
						}
						else if (compSumDiffX < 0 && compSumDiffY >= 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX) + pi;
						}
						else if (compSumDiffX < 0 && compSumDiffY < 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX) - pi;
						}
						
						// Displays the result of the calculation to the standard output
						cout << "Sum, Cartesian:\tz_sum = " << compSumDiffX << " + j " << compSumDiffY << endl;
						cout << "Sum, Polar:\tz_sum = " << compSumDiffR << " exp(j " << compSumDiffTheta << ")" << endl;
						break;
					
					case 3:
						// Initializes new x, y, and r variables to their new values for case 3 calculation.
						compSumDiffX = x2 - x;
						compSumDiffY = y2 - y;
						compSumDiffR = sqrt(pow(compSumDiffX, 2) + pow(compSumDiffY, 2));
						
						// Makes changes to theta based on values of compSumDiffX and compSumDiffY
						if (compSumDiffX >= 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX);
						}
						else if (compSumDiffX < 0 && compSumDiffY >= 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX) + pi;
						}
						else if (compSumDiffX < 0 && compSumDiffY < 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX) - pi;
						}
						
						// Displays the result of the calculation to the standard output
						cout << "Sum, Cartesian:\tz_sum = " << compSumDiffX << " + j " << compSumDiffY << endl;
						cout << "Sum, Polar:\tz_sum = " << compSumDiffR << " exp(j " << compSumDiffTheta << ")" << endl;
						break;
						
					case 4:
						// Initializes new x, y, and r variables to their new values for case 4 calculation.
						compSumDiffX = -x - x2;
						compSumDiffY = -y - y2;
						compSumDiffR = sqrt(pow(compSumDiffX, 2) + pow(compSumDiffY, 2));
						
						// Makes changes to theta based on values of compSumDiffX and compSumDiffY
						if (compSumDiffX >= 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX);
						}
						else if (compSumDiffX < 0 && compSumDiffY >= 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX) + pi;
						}
						else if (compSumDiffX < 0 && compSumDiffY < 0){
							compSumDiffTheta = atan(compSumDiffY/compSumDiffX) - pi;
						}
						
						// Displays the result of the calculation to the standard output
						cout << "Sum, Cartesian:\tz_sum = " << compSumDiffX << " + j " << compSumDiffY << endl;
						cout << "Sum, Polar:\tz_sum = " << compSumDiffR << " exp(j " << compSumDiffTheta << ")" << endl;
						
						break;
					
					default:
						// Happens when user makes a selection other than (1-4).
						cout << "ERROR! Invalid selection, exiting.";
						return -1;
						
				}
				double productR1, productTheta, productRealCart, productImagCart;
				productR1 = r*r2;
				productTheta = theta + theta2;
				productRealCart = (x*x2)-(y*y2);
				productImagCart = (x*y2)+(y*x2);
				
				cout << endl;
				cout << "Product, polar:\t\tz1 * z2 = " << productR1 << " exp(j " << productTheta << ")" << endl;
				cout << "Product, Cartesian:\tz1 * z2 = " << productRealCart << " + j " << productImagCart << endl;
				
				double cartx, carty;
				cartx = productR1*cos(productTheta);
				carty = productR1*sin(productTheta);
				cout << "Polar, converted to Cartesian: z1 * z2 = " << cartx << " + j " << carty << endl;
				break;
				
			default:
				// Happens when user enters a selection other than 'v', 'V', 'c', or 'C'.
				cout << "ERROR! Invalid selection, exiting.";
				return -1;
		}
		
		
		
		
		
	return 0;

}
