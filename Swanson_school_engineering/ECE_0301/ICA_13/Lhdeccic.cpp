

#include "Lhdeccic.h"
#include <fstream>


void Lhdeccic::setB(double bee)
{
	b = bee;
}

void Lhdeccic::setTimeInitial(double timeInitiall)
{
	timeInitial = timeInitiall;
}
	
void Lhdeccic::setK(double kay)
{
	K = kay;
}

void Lhdeccic::setSolutionLabel(std::string label)
{
	solutionLabel = label;
	diffEq.setSignalLabel(label);
}


double Lhdeccic::getB() const
{
	return b;
}

double Lhdeccic::getTimeInitial() const
{
	return timeInitial;
}
	
double Lhdeccic::getK() const
{
	return K;
}

std::string Lhdeccic::getSolutionLabel() const
{
	return solutionLabel;
}

Lhdeccic::Lhdeccic()
{
	setTimeInitial(0);
	setK(1);
	setB(getK());
	setSolutionLabel("y");
}

Lhdeccic::Lhdeccic(double bee, double timeInitiall, double kay)
{
	setTimeInitial(timeInitiall);
	setK(kay);
	setB(bee);
	setSolutionLabel("y");
}

std::string Lhdeccic::textNum(double x) const
{
	if (x >= 100)
		// large numbers truncated as int -> string
		return std::to_string(int(x));
	else
	{
		// small numbers will get 3 digits
		std::string x_exp = std::to_string(x);
		// return 4 characters, or 5 if x<0
		return x_exp.substr(0, 4 + (x<0));
	}
}

Signal * Lhdeccic::getSigPtr()
{
	Signal *p;
	p = &diffEq;
	return p;
}


