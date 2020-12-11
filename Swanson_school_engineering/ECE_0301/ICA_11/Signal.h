// Signal class specification


#ifndef SIGNAL_H
#define SIGNAL_H
#include <string>
#include <vector>

class Signal 
{
	private:
		unsigned int numSamples;
		double frequency, timeInit;
		std::vector<double> signalVec;
		std::vector<double> timeVec;
		std::string fileNameTemp;
		std::string signalLabel;
		std::string expression;
	public:
		void setSignalLabel(std::string);
		std::string getSignalLabel();
		std::string getFileNameTemp();
		void setExpression(std::string);
		std::string getExpression();
		void setNumSamples(unsigned int);
		void setFrequency(double);
		void setTimeInit(double);
		unsigned int getNumSamples();
		double getFrequency();
		double getTimeInit();
		std::vector<double> getSignalVec();
		std::vector<double> getTimeVec();
		std::string textNum(double x) const;
		void fillSignalVec(double);
		double getSignalVec(unsigned int);
		double getTimeVec(unsigned int);
		void zeroSignalVec();
		void zeroTimeVec();
		void fillTimeVec();
		void setFileNameTemp();
		void fileOutput();
		
		void signalVecFill(double, double, double);
		void rounder();
		
		void operator=(const Signal &);
		Signal operator+(const Signal &);
		Signal operator*(const Signal &);
		
		Signal(unsigned int, double, double);
		Signal();
};

#endif
