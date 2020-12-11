//
//  counterClass.cpp
//  
//
//  Created by Morgan Visnesky on 9/28/18.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>


using namespace std;

class Counter
{
public:
    Counter()
    {
        counterVal = 0;
    }
    
    Counter(int startVal)
    {
        counterVal = startVal;
    }
    
    void increment(int incNum)
    {
        for (int i = 0; i < incNum; i++)
        {
            counterVal++;
            incDecCounter++;
        }
        
    }
    
    void decrement(int decNum)
    {
        for (int i = 0; i < decNum; i++)
        {
            counterVal--;
            incDecCounter++;
        }
    }
    
    void display()
    {
        cout << "current count: " << counterVal << endl;
        //return counterVal;
    }
    
    static void displayIncDecCount()
    {
        cout << "total increments and decrements: " << incDecCounter << endl;
    }
    
private:
    static int incDecCounter;
    int counterVal;
};

int Counter::incDecCounter = 0;

int main(void)
{
    
    Counter a, b(200);
    a.display();
    b.display();
    Counter::displayIncDecCount();
    a.increment(85);
    b.decrement(242);
    //cout << a.display() << " " << b.display() << endl;
    a.display();
    b.display();
    Counter::displayIncDecCount();
    system("pause");
    
}
