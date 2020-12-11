/*
	AUTHOR: Morgan Visnesky
	DATE: 08/26/2020
 	FILENAME: ece0301_ICA02_step10.cpp
	DESCRIPTION:
	* This is in class assignment #2 for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.
	* This serves as a computer program to introduce propositional logic and evaluating boolean expressions.
	
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	cout << "ECE 0301 Propositional Logic Example" << endl << endl;
	
	// Declares three string variables prop1-prop3 that hold propositional logic statements.
	string prop1, prop2, prop3;
	
	// Initializes the variables prop1-prop3 with the propositional phrases from the assignment outline.
	prop1 = "Pigs can fly.";
	prop2 = "Earth is flat.";
	prop3 = "The moon is cheese.";
	
	// Displays each of the propositions to the standard output.
	cout << "P1: " << prop1 << endl;
	cout << "P2: " << prop2 << endl;
	cout << "P3: " << prop3 << endl << endl;
	
	// Declares three boolean variables to store the truth values that correspond to the
	// already declared and initialized proposition variables.
	bool truth1, truth2, truth3;
	
	// Displays statements to the standard output to ask the user about the truth values.
	cout << "Enter P1 truth value: ";
	cin >> truth1;
	
	cout << "Enter P2 truth value: ";
	cin >> truth2;
	
	cout << "Enter P3 truth value: ";
	cin >> truth3;
	
	// Displays to the standard output the values that the user has just entered using
	// the boolalpha function.
	cout << endl << boolalpha << "You entered: P1 = " << truth1 << ", P2 = " << truth2 << ", P3 = " << truth3 << "." << endl << endl;
	
	// Declares a boolean variable and initializes it based on the logic 
	// of this statment: "Pigs can fly, Earth is not flat, and the moon is cheese."
	bool truth4 = truth1 && (truth2 == 0) && truth3;
	
	// Declares a boolean variable and initializes it based on the logic 
	// of this statment: "Pigs cannot fly, or Earth is flat, or the moon is cheese."
	bool truth5 = (truth1 == 0) || truth2 || truth3;
	
	// Declares a boolean variable and initializes it based on the logic 
	// one the elementary propositions is true and two are false.
	bool truth6 = ((truth1 + truth2 + truth3) == 1);
	
	// Declares a boolean variable and initializes it based on the logic 
	// none of the elementary propositions are true.
	bool truth7 = ((truth1 + truth2 + truth3) == 0);
	
	// Declares a boolean variable and initializes it based on the logic 
	// a majority of the elementary propositions are true.
	bool truth8 = ((truth1 + truth2 + truth3) >= 2);
	
	// Declares a boolean variable and initializes it based on the logic 
	// of this statement: "Pigs cannot fly, and either Earth is flat or the moon is cheese, but not both."
	bool truth9 = (truth1 == 0) && ((truth2 == 1 && truth3 == 0) || (truth2 == 0 && truth3 ==1));
	
	// Displays a neatly formatted truth table to the standard output that shows the truth 
	// values for all of the propositional statements.
	cout << "Truth Table:" << endl << "Proposition" << "\t" << "Truth Value" << endl;
	cout << "-----------" << "\t" << "-----------" << endl;
	cout << "P1" << "\t\t" << truth1 << endl;
	cout << "P2" << "\t\t" << truth2 << endl;
	cout << "P3" << "\t\t" << truth3 << endl;
	cout << "P4" << "\t\t" << truth4 << endl;
	cout << "P5" << "\t\t" << truth5 << endl;
	cout << "P6" << "\t\t" << truth6 << endl;
	cout << "P7" << "\t\t" << truth7 << endl;
	cout << "P8" << "\t\t" << truth8 << endl;
	cout << "P9" << "\t\t" << truth9 << endl;
	
	return 0;
	
}
