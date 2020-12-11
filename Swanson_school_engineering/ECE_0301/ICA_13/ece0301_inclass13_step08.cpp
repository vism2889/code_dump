#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
#include "Signal.cpp"
#include "Folhdeccic.cpp"
//using namespace std;

int main()
{
	//Signal sig(51, 200, 0.01);
	//sig.setSignalLabel("y");
	//sig.expSigFill(0.25, 5);
	//sig.fileOutput();
	std::ofstream fileOutput;
	fileOutput.open("ECE 0301 - Differential Equation Reports.txt");
	Folhdeccic fo;
	fo.outputFile(fileOutput);
	Folhdeccic fp(10, -2.5, 1);
	fp.setSolutionLabel("x");
	fp.outputFile(fileOutput);
	//std::cout << fo.getB() << std::endl << fo.getTimeInitial() << std::endl << fo.getK();
	fileOutput.close();
	return 0;
}
 
