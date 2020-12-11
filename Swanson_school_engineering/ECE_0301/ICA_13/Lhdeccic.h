//class specification


#ifndef LHDECCIC_H
#define LHDECCIC_H
#include <fstream>

class Lhdeccic 
{
	private:
		double b;
		double timeInitial;
		double K;
		std::string solutionLabel;
		Signal diffEq;
	public:
		void setB(double);
		void setTimeInitial(double);
		void setK(double);
		void setSolutionLabel(std::string);
		double getB() const;
		double getTimeInitial() const;
		double getK() const;
		std::string getSolutionLabel() const;
		Lhdeccic();
		Lhdeccic(double, double, double);
		std::string textNum(double) const;
		virtual std::string textExp() const = 0;
		virtual void outputFile(std::ofstream &) const = 0;
		virtual std::string initCond() const = 0;
		Signal* getSigPtr();
};

#endif
