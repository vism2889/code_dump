#include "Lhdeccic.cpp"
#include "Folhdeccic.h"
#include <fstream>

Folhdeccic::Folhdeccic():Lhdeccic{}
{
}

Folhdeccic::Folhdeccic(double b, double timeInitial, double k):Lhdeccic{b, timeInitial, k}
{
}

std::string Folhdeccic::textExp() const
{
	std::string text = getSolutionLabel() + "'(t) + " + textNum(getB()) + " " + getSolutionLabel() +"(t) = 0";
	return text;
}

void Folhdeccic::outputFile(std::ofstream &fileOutput) const
{
	fileOutput << "---------------------------------" << std::endl;
	fileOutput << "First-Order Differential Equation" << std::endl;
	fileOutput << "---------------------------------" << std::endl;
	fileOutput << textExp() << std::endl << std::endl;
	
	fileOutput << "Initial Condition" << std::endl;
	fileOutput << "-----------------" << std::endl;
	fileOutput << initCond() << std::endl << std::endl;
}

std::string Folhdeccic::initCond() const
{
	std::string text = getSolutionLabel() + "(" + textNum(getTimeInitial()) + ") = " + textNum(getK());
	return text;
}


