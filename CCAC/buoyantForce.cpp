//
//  buoyantForce.cpp
//  
//
//  Created by Morgan Visnesky on 9/6/18.
//

#include "buoyantForce.hpp"
#include <iostream>
#include <math.h>

using namespace std;

const double PI = 3.141592;
const double WW = 62.4f; // water weight

int main(void)
{
    double radius = 0.00f, weight = 0.00f, buoyantF = 0.00f, volume = 0.00f;
    char runAgain = 'Y';
    
    
    do {
        cout << "This program computes Buoyant Force in water given sphere radius." << "\n";
        cout << "Based on the weight of the sphere, it determines whether the sphere foats or sinks." << "\n";
        cout << endl;
        
        cout << "Enter the radius of the sphere." << "\n";
        cin >> radius;
        cout << "You entered " << radius << "\n";
        
        cout << "Enter the weight of the sphere." << "\n";
        cin >> weight;
        cout << "You entered " << weight << "\n";
        
        volume = ((4.0/3.0) * PI * (pow(radius, 3))); // must use '4.0/3.0' to get correct value
        buoyantF = volume * WW;
        
        cout << "Buoyant Force  = " << buoyantF << "\n";
        
        if (buoyantF >= weight)
        {
            cout << "It Floats!!" << "\n";
        }
        else
        {
            cout << "It Sunk!!" << "\n";
        }
        
        cout << "Would you like to make another calculation? (Y/N)" << "\n";
        cin >> runAgain;
    } while ((runAgain != 'N' && runAgain != 'n'));
    
    system("pause");
    return 0;
}
