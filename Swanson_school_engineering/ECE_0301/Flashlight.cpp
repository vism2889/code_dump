/*
	AUTHOR: Morgan Visnesky
	DATE: 09/22/2020
 	FILENAME: Flashlight.cpp
	DESCRIPTION:
	* This is in class assignment #7   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.
	
	* This assignment covers creating classes and corresponding member functions.
	* This particular file holds the implementation for the Flashlight class, 
	* implementation meaning it holds the definitions of the Flashlight class
	* methods.
*/


// include statements
#include <iostream>
#include <math.h>

using namespace std;

// Consturctor method that initializes the private member variables
Flashlight::Flashlight()
{
	setVoltage(3.0);
	setBulbResistance(100);
	setSwitchState(1);
}

// Function to set the voltage of the flashlight
void Flashlight::setVoltage(double newVoltage)
{
	voltage = newVoltage;
}

// Function to set the resistance of the flashlight
void Flashlight::setBulbResistance(double newRes)
{
	bulbResistance = newRes;
}

// Function to set the state of the flashlights switch
void Flashlight::setSwitchState(bool state)
{
	switchState = !state;
}

// function that returns the current voltage of the flashlight
double Flashlight::getVoltage()
{
	return voltage;
}

// Function that returns the current resistance of the light bulb in
// the flashlight
double Flashlight::getBulbResistance()
{
	return bulbResistance;
}

// Function that resturns the current state of the switch
bool Flashlight::getSwitchState()
{
	return switchState;
}

// Function that calculates and returns the current in the light bulb 
// of the flashlight
double Flashlight::getCurrentBulb()
{
	if (switchState == 1){
		
		return voltage/bulbResistance;
	}
	else 
	{
		return 0;
	}
}

// Function that returns the dissapated power through the light bulb in the flash light
double Flashlight::getDissPowBulb()
{
	if (switchState == 1){
		
		return (pow(voltage, 2)/bulbResistance);
	}
	else 
	{
		return 0;
	}
	
}

// Function that outputs all the current information about the flash light
// to the standard output.
void Flashlight::infoOut()
{
	cout << "Here are the data on the Flashlight:\n";
	cout << "The battery voltage is " << getVoltage() << " Volts." << endl;
	cout << "The bulb resistance is " << getBulbResistance() << " Ohms." << endl;
	if (getSwitchState() == 0)
	{
		cout << "The switch is open." << endl;
		cout << "The Flashlight is off." << endl;
	}
	else
	{
		cout << "The switch is closed." << endl;
		cout << "The Flashlight is on." << endl;
	}
	
	cout << "The bulb current is " << getCurrentBulb() << " Amperes." << endl;
	cout << "The bulb power is " << getDissPowBulb() << " Watts." << endl;
}
