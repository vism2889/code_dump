//
//  diceSimulator.cpp
//  
//
//  Created by Morgan Visnesky on 9/9/18.
//
//  Write a program that uses a function that returns a number between 1 and 6.  Use this function to simulate
//  the roll of a die.  Allow the user to specify the number of trials and then tabulate that number of rolls of
//  two dice.  The program must allow for repeated simulations. Initialize rand() using srand() and time().
//

#include <stdio.h>
//#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>


using namespace std;

int rollSim();

int main(void)
{
    int numRolls;
    int diceOutput;
    int roll;
    char runAgain = 'Y';
    std::vector<int> rollArray[0];
    std::list<int> myList;
    std::list<int>::iterator it;
    std::list<int>::iterator it2;
    
    // create array that holds a count value, increment array[rollNum] when rollNum is equal			
    
    do
    {
        srand(time(0));
        cout << "This program rolls two dice and tabulates the results." << "\n";
        cout << endl;
        cout << "Please enter the number of rolls you want to make: " << "\n";
        cin >> numRolls;
        
        for (int i = 0; i < numRolls; i++)
        {
            roll = rollSim() + rollSim();
            it = myList.begin();
            it2 = rollArray.begin();
            myList.insert(it,roll);
            rollArray.insert(it2, roll);
            cout << "roll " << (i+1) << ": " << roll << "\n";
            
        }
        
        // tabulation output and formatting
        cout << "Sum" << "\t\t" << "#Rolled" << "\t\t" << "odds" << "\t\t" << "%Error" << "\n";
        for (int j = 2; j < 12; j++)
        {
            cout << j << "\t\t" << 0 << "\n";
            //
            //int mycount = std::count (myints, myints+8, 10);
        
        
        }
        int myCount = count(rollArray.begin(), sizeof(rollArray), 3);
        cout << "count: " << myCount;
        cout << "list: " << myList.front() << "\n";
        
        cout << "Would you like to try again? " << "\n";
        cin >> runAgain;
    }
    while ((runAgain != 'N' && runAgain != 'n'));
    
    
    system("pause");
    return 0;
}

int rollSim(void)
{
    int diceOutput = (1 + rand() % 6);
    return diceOutput;
}
