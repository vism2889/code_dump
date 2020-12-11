//
//  lowestTermsFraction.cpp
//  
//
//  Created by Morgan Visnesky on 9/15/18.
//
// Write a program that reduces a fraction to lowest terms.  Two functions should be implemented.  Function
// gcd should find and return the greatest common denominator and be called as g = gcd(num,den);. Function
// reduce(num,den); should call gcd to provide the lowest terms.  The lowest terms should be returned via
// reference in num and den.

#include <stdio.h>

#include <stdlib.h>
#include <iostream>

int numerator;
int denominator;
int greatestCD(int num, int den);
void reduce(int& numer, int& denomer);
char runAgain = 'Y';

using namespace std;

int main(void)
{
    cout << "This program takes a numerator and denominator and reduces to lowest terms" << endl;
    
    
    do
    {
        cout << "Enter the numerator" << endl;
        cin >> numerator;
        cout << "Enter the denominator" << endl;
        cin >> denominator;
        
        cout << "Your greatest common denominator is: " << greatestCD(numerator, denominator) << "." << endl;
        reduce(numerator, denominator);
        cout << "Your fraction reduced is: " << numerator << "/" << denominator << endl;
        //cout << numerator << "/" << denominator << endl;
        cout << endl;
        cout << "Would you like to try again? (Y/N) " << endl;
        cin >> runAgain;
    }
    while ((runAgain != 'N' && runAgain != 'n'));
    
    
    
    
}

int greatestCD(int num, int den)
{
    while (den != 0)
    {
        int t = den;
        den = num % den;
        num = t;
        
    }
    return num;
}


void reduce(int& numer, int& denomer)
{
    int gcd = greatestCD(numer, denomer);
    numerator = numer/gcd;
    denominator = denomer/gcd;
}

