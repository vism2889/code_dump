/*
	AUTHOR: Morgan Visnesky
	DATE: 09/22/2020
 	FILENAME: ece0301_ICA07_NOT_gate.cpp
	DESCRIPTION:
	* This is in class assignment #7   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment covers creating classes and corresponding member functions.
	* This particular program creates a class to represent a NOT gate.
*/

// include statements
#include <iostream>
#include <math.h>
#include <string>


using namespace std;

// class declaration for NotGate
class NotGate
{
	private:
		string textLabel;
		bool inputNode;
	
	public:
		void setTextLabel(string);
		void setInputNode(bool);
		string getLabel();
		bool getInputNode();
		string getNotLabel();
		bool getInputNodeNot();
};

// NotGate member function that is used to set the text label 
void NotGate::setTextLabel(string label)
{
	textLabel = label;
}

// NotGate member function that is used to set the state of the input node
void NotGate::setInputNode(bool val)
{
	inputNode = val;
}

// NotGate member function that is used to get the current text label
string NotGate::getLabel()
{
	return textLabel;
}

// NotGate member function that is used to get the current input state.
bool NotGate::getInputNode()
{
	return inputNode;
}

// NotGate member function that is used to get the complement of the current text label
string NotGate::getNotLabel()
{
	return textLabel.append("_NOT");
}

// NotGate member function that is used to complement the current value of the input node
bool NotGate::getInputNodeNot()
{
	return !inputNode;
}


int main() {
	NotGate gate;
	string gateVal;
	bool logicVal;
	
	cout << "This program will simulate a not gate." << endl;
	cout << "What is the label for the gate input?" << endl;
	cin >> gateVal;
	cout << endl;
	
	cout << "What is the logic value at the input (0/1)?" << endl;
	cin >> logicVal;
	cout << endl;
	
	gate.setTextLabel(gateVal);
	gate.setInputNode(logicVal);
	
	cout << "Here are the data on the not gate:" << endl;
	cout << "Input label: " << gate.getLabel() << endl;
	cout << "Output label: " << gate.getNotLabel() << endl;
	cout << "Logic value at input: " << gate.getInputNode() << endl;
	cout << "Logic value at output: " << gate.getInputNodeNot();
	
	
	return 0;
}


