/*
	AUTHOR: Morgan Visnesky
	DATE: 09/22/2020
 	FILENAME: Flashlight.h
	DESCRIPTION:
	* This is in class assignment #7   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment covers creating classes and corresponding member functions.
	* This particular file holds the specification for the Flashlight class, 
	* specification meaning it holds the declaration of the Flashlight class.
*/


using namespace std;

// class decalration for Flashlight class.
class Flashlight
{
	private:
		// private member variables to hold values of voltage,
		// bulb resistance and the state of the switch.
		double voltage;
		double bulbResistance;
		bool switchState;
		
	public:
		// Accessor, mutator, and constructor methods.
		Flashlight();
		void setVoltage(double);
		void setBulbResistance(double);
		void setSwitchState(bool);
		double getVoltage();
		double getBulbResistance();
		bool getSwitchState();
		double getCurrentBulb();
		double getDissPowBulb();
		void infoOut();
};
