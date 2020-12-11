/*
	AUTHOR: Morgan Visnesky
	DATE: 09/22/2020
 	FILENAME: ece0301_ICA07_cmplx_nmbr.cpp
	DESCRIPTION:
	* This is in class assignment #7   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.
	* 
	* This assignment covers creating classes and corresponding member functions.
	* This particular program creates a class to represent a complex number,
	* and class methods that can calculate the phase angle and the magnitude
	* of the complex number.

*/


// This program demonstrates a simple class.
#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
using namespace std;

// Rectangle class declaration.
class Rectangle
{
   private:
      double width;
      double length;
   public:
      void setWidth(double);
      void setLength(double);
      double getWidth() const;
      double getLength() const;
      double getArea() const;
};

// ComplexNum class declaration
class ComplexNum
{
	private:
		double real;
		double imaginary;
	
	public:
		void setReal(double);
		void setImaginary(double);
		double getReal();
		double getImaginary();
		double phaseAngle();
		double magnitude();
};

// Member function of complex num that sets the real part
// of a complex number.
void ComplexNum::setReal(double r)
{
	real = r;
}

// Member function of complex num that sets the imaginary part
// of a complex number.
void ComplexNum::setImaginary(double i)
{
	imaginary = i;
}

// Member function of complex num that gets the real part
// of a complex number.
double ComplexNum::getReal()
{
	return real;
}

// Member function of complex num that gets the real imaginary part
// of a complex number.
double ComplexNum::getImaginary()
{
	return imaginary;
}

// Member function of complex num that calculates and returns the phase angle
// of the complex number.
double ComplexNum::phaseAngle()
{
	return atan2(imaginary, real);
}

// Member function of complex num that calculates and returns the pmagnitude
// of the complex number.
double ComplexNum::magnitude()
{
	double realPow = pow(real,2);
	double imagPow = pow(imaginary, 2);
	
	return sqrt(realPow+imagPow);
}



//**************************************************
// setWidth assigns a value to the width member.   *
//**************************************************

void Rectangle::setWidth(double w)
{
   width = w;
}

//**************************************************
// setLength assigns a value to the length member. *
//**************************************************

void Rectangle::setLength(double len)
{
   length = len;
}

//**************************************************
// getWidth returns the value in the width member. *
//**************************************************

double Rectangle::getWidth() const
{
   return width;
}

//****************************************************
// getLength returns the value in the length member. *
//****************************************************

double Rectangle::getLength() const
{
   return length;
}

//*****************************************************
// getArea returns the product of width times length. *
//*****************************************************

double Rectangle::getArea() const
{
   return width * length;
}

//*****************************************************
// Function main                                      *
//*****************************************************

int main()
{
   ComplexNum comp;     
   double real;  
   double imaginary; 

   // Outputs intro message to the standard output, and prompts the user
  //  to enter the correpsonding parts to an imaginary number.
   cout << "This program will calculate the magnitude and phase" << endl;
   cout << "angle of a complex number" << endl << endl;
   cout << "What is the real part?" << endl;
   cin >> real;
   cout << "What is the imaginary part?" << endl;
   cin >> imaginary;
   cout << endl;
   
   comp.setReal(real);
   comp.setImaginary(imaginary);

   // Display the data for the complex number.
   cout << "Here are the data on complex number z:" << endl;
   cout << "Real part: " << comp.getReal() << endl;
   cout << "Imaginary part: " << comp.getImaginary() << endl;
   cout << "Magnitude: " << comp.magnitude() << endl;
   cout << "Phase angle (radians): " << comp.phaseAngle();
   return 0;
}
