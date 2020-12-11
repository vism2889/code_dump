/*
	AUTHOR: Morgan Visnesky
	DATE: 09/22/2020
 	FILENAME: ece0301_ICA07_flashlight.cpp
	DESCRIPTION:
	* This is in class assignment #7   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.


	* This assignment covers creating classes and corresponding member functions.
	* This particular file holds the main driver for the Flashlight class,
	* where we are actually creating instances of it and making calls to the classes methods. 

*/


// include statements
#include <iostream>
#include <math.h>
#include <string>
#include "Flashlight.h"
#include "Flashlight.cpp"


using namespace std;

//Main function
int main()
{
	// This short program displays an interactive user prompt that represents
	// the functionality of a flashlight from a perspective of the electical circuit,
	// and the state of the switch of the flashlight.
	
	// creates an instance of the Flashlight class.
	Flashlight light;
	
	// declares a variable to hold the user selection
	int userEntry = 0;
	
	// While loop continues to prompt for user entry so long as user
	// does not exit the program.
	while (userEntry != 4)
	{
		// Displays the options the user can choose from
		cout << "(1) Change the battery voltage" << endl;
		cout << "(2) Change the bulb resistance" << endl;
		cout << "(3) Toggle the switch state" << endl;
		cout << "(4) Exit the program" << endl;
		
		// stores the users input
		cin >> userEntry;
		
		// switch case to handle which option depending on the userEntry
		// variable.
		switch(userEntry)
		{
			case 1:
				// case-1 prompts the user to change the voltage and 
				// then outputs the updated info about the state of 
				// the flashlight.
				double newVoltage;
				cout << "Enter the new battery voltage: ";
				cin >> newVoltage;
				light.setVoltage(newVoltage);
				light.infoOut();
				cout << endl;
				break;
			case 2:
				// case-2 prompts the user to change the battery resistance 
				// and then outputs the updated info about the state of 
				// the flashlight.
				double newResistance;
				cout << "Enter the new battery resistance: ";
				cin >> newResistance;
				light.setBulbResistance(newResistance);
				light.infoOut();
				cout << endl;
				break;
			case 3:
				// case-3 changes the state of the switch, no prompt is given
				// to the user, but the new state of the flashlight is displayed.
				light.setSwitchState(light.getSwitchState());
				light.infoOut();
				cout << endl;
				break;
			case 4:
				// Exits program if option '4' is chosen.
				break;
			default:
				// If input is invalid, the user prompt is shown again from outside of 
				// the switch statement.
				if ((userEntry != 1) || (userEntry != 2) || (userEntry != 3))
				{
					break;
				}
				break;
		}
		
	}
		
	return 0;

}
