#ifndef FOLHDECCIC_H
#define FOLHDECCIC_H


class Folhdeccic: public Lhdeccic
{
	public:
		Folhdeccic();
		Folhdeccic(double, double, double);
		virtual std::string textExp() const;
		virtual void outputFile(std::ofstream&) const;
		virtual std::string initCond() const;
		
};

#endif
