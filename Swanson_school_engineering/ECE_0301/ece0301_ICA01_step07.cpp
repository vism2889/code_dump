/*
	AUTHOR: Morgan Visnesky
	DATE: 08/24/2020
 	FILENAME: ece0301_ICA01_step07.cpp
	DESCRIPTION:
	* This is in class assignment #1 for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud
	* This serves as a computer program to model a DC resistive circuit based on the assignment specifications.
	* The circuit contains 3 components, a voltage source, resistor 1, and resistor 2.
	* The program calculates:
			* Current flowing through each resistor
			* Power dissipated into each resistor
			* Energy supplied by voltage source over various times
			* Cost to run circuit for various time intervals at a cost of $0.10/kWh

*/


#include <iostream>


using namespace std;

int main() {
	// Introductory message displayed to standard output to describe program.
	cout << "ECE 0301 DC Resistive Circuit Simulation" << endl <<
					"Modeled after www.falstad.com/circuit/" << endl <<
					"Circuits -> Basics -> Ohm\'s Law" << endl;
	
	// Declares three variables vs for the voltage source, r1 for resistor 1, and r2 for resistor 2.
	double vs, r1, r2;
	
	// Initializes the three variables vs, r1, and r2 with values.
	vs = 7200; // 7.2 kV or 7200 volts
	r1 = 8; // 100 ohms
	r2 = 10; // 10 ohms
	
	// Displays the values of vs, r1, and r2 to the standard output.
	cout << "Vs = " << vs << " Volts" << endl;
	cout << "R1 = " << r1 << " Ohms" << endl;
	cout << "R2 = " << r2 << " Ohms" << endl;
	
	// Declares four variables to hold the current flowing through r1, and r2
	// along with the power dissipated in r1, and r2 respectively.
	double current1, current2, dissPower1, dissPower2;
	
	// Initializes the current variables using ohms law equation: I = V/R.
	current1 = vs / r1;
	current2 = vs / r2;
	
	// Initializes the power dissipated variables using the power rule: P = I * V.
	dissPower1 = current1 * vs;
	dissPower2 = current2 * vs;
	
	// Displays the values for current flowing through, and power dissipated in
	// r1 and r2.
	cout << "I1 = " << current1 << " Amperes" << endl;
	cout << "P1 = " << dissPower1 << " Watts" << endl;
	cout << "I2 = " << current2 << " Amperes" << endl;
	cout << "P2 = " << dissPower2 << " Watts" << endl;
	
	
	// Declares four variables to hold values for how much energy is supplied to 
	// the circuit over four different time intervals, 1 second, 1 hour, 1 day, and 1 year.
	float secondEnergy, hourEnergy, dayEnergy, yearEnergy;
	
	// Declares and initializes a variable to combine the dissipated power 
	// in r1 and r2 into a total dissipated power variable.
	double dissPowerTotal = dissPower1 + dissPower2;
	
	// Initializes energy supplied variables using the equation Energy = Power * Time(in seconds).
	secondEnergy = 1 * dissPowerTotal;
	hourEnergy = 3600 * dissPowerTotal;
	dayEnergy = 24 * 3600 * dissPowerTotal;
	yearEnergy = 365 * 24 * 3600 * dissPowerTotal;
	
	// Displays the values for energy supplied by the voltage source over different time
	// intervals to the standard output.
	cout << "Energy supplied in one second = " << secondEnergy << " Joules" << endl;
	cout << "Energy supplied in one hour = " << hourEnergy << " Joules" << endl;
	cout << "Energy supplied in one day = " << dayEnergy << " Joules" << endl;
	cout << "Energy supplied in one year = " << yearEnergy << " Joules" << endl;
	
	
	// Declares variables to hold cost values for different circuit runtime durations.
	double secondCost, hourCost, dayCost, yearCost;
	
	// Declares and initializes constant variables cost, for the cost per kWh, and jouleToKWH 
	// which serves as a conversion value between joules and kWh.
	const double cost = 0.10, jouleToKWH = 2.77778e-7;
	
	// Initializes cost variables with respective values for different runtime durations.
	secondCost = secondEnergy * jouleToKWH * cost;
	hourCost = hourEnergy * jouleToKWH * cost;
	dayCost = dayEnergy * jouleToKWH * cost;
	yearCost = yearEnergy * jouleToKWH * cost;
	
	// Displays the four cost variables to the standard output. 
	cout << "Cost of supplying energy for one second at $0.10/kWh = $" << secondCost << endl;
	cout << "Cost of supplying energy for one hour at $0.10/kWh = $" << hourCost << endl;
	cout << "Cost of supplying energy for one day at $0.10/kWh = $" << dayCost << endl;
	cout << "Cost of supplying energy for one year at $0.10/kWh = $" << yearCost << endl;
	
	
	
	
	return 0;
}
