//
//  Babylonian.cpp
//  
//
//  Created by Morgan Visnesky on 9/6/18.
//
//  calculations
//      1) guess = input/2
//      2) r = input/guess
//      3) guess = (guess+r)/2
//      4) go to 2 until done
//

#include "Babylonian.hpp"
#include <iostream>

using namespace std;


int main(void)
{
    double input = 0.000f;
    double guess;
    double r;
    char runAgain = 'Y';
    
    
    do {
        input = 0.0f;
        guess = 0.0f;
        r = 0.0f;
        cout << "Enter a number and I will apply the Babylonian square root " << "\n";
        cout << "until I am within .001 of the correct answer" << "\n";
        
        cin >> input;
        guess = input/2;
        do
        {
            
            r = input/guess;
            guess = (guess+r)/2;
            cout << "Guessing " << guess << "\n";
            
            
            
        }
        while (guess*guess >= (input + (input*0.001)) ) ;
        // could have used code below to be more accurate:
        // while (guess -input < .0001.);
        
        
        cout << "The Babylons algorithm gives " << guess << "\n";
        cout << "Checking: " << guess << " * " << guess << " = " << (guess * guess * 1.00f) << "\n";
        cout << "Would you like to continue? Enter (Y/N)" << "\n";
        cin >> runAgain;
    } while (runAgain != 'N' && runAgain != 'n');
    
    system("pause");
    return 0;
}
















