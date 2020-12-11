//
//  diceSimRevised.cpp
//  
//
//  Created by Morgan Visnesky on 9/15/18.
//

#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iomanip>
#include <array>

double oddsArray[13];
double rolledArray[12];
double percentErrorArray[12];
double expected_Array[13] = {0, 0,.01/.36,.02/.36,.03/.36,.04/.36,.05/.36,.06/.36,.05/.36,.04/.36,.03/.36,.02/.36,.01/.36};

using namespace std;
int rollSim();
void initializeArray();
void calcPercentError(double &rolls);
void calcOdds(double &rolls);
int numRolls;

int main(void)
{
    int diceOutput;
    char runAgain = 'Y';
    
    cout << "This program rolls two dice and tabulates the results." << "\n";
    cout << endl;
    
    do
    {
        numRolls = 0;
        initializeArray();
        int diceOutput = 0;
        double expected_Array[13] = {0, 0,.01/.36,.02/.36,.03/.36,.04/.36,.05/.36,.06/.36,.05/.36,.04/.36,.03/.36,.02/.36,.01/.36};
        srand(time(0));
        cout << "please enter the number of rolls you want to make: " << "\n";
        cin >> numRolls;
        double jon = numRolls * 1.0;
        
        for (int i = 0; i < numRolls; i++)
        {
            int roll = rollSim() + rollSim();
            rolledArray[roll]++;
        }
        calcOdds(jon);
        calcPercentError(jon);
        cout << left << setw(10) << "Sum" << setw(10) << "#Rolled" << setw(10) << "Odds" << setw(10) << "% Error";
        cout << endl;
        
        for (int i = 2; i < 13; i++)
        {
            cout << left << setw(10)<< i << " "    ;
            cout << left << setw(10) << rolledArray[i] << " ";
            cout << setw(10) << oddsArray[i];
            cout << setw(10)<< percentErrorArray[i];
            cout << endl;
        }
        cout << endl;
        cout << endl;
        cout << "Would you like to try again? " << "\n";
        cin >> runAgain;
    }
    while ((runAgain != 'N' && runAgain != 'n'));
    system("pause");
}

void calcPercentError(double &rolls)
{
    for (int k = 2; k < 13; k++)
    {
        percentErrorArray[k] = ( fabs(oddsArray[k] - rolledArray[k]) / oddsArray[k]) * 100.0;
    }
}

void calcOdds(double &rolls)
{
    for (int k = 2; k < 13; k++)
    {
        oddsArray[k] = expected_Array[k] * rolls;
    }
}

int rollSim()
{
    int diceOutput = (1 + rand() % 6);
    return diceOutput;
}

void initializeArray()
{
    for (int j = 2; j < 13; j++)
    {
        oddsArray[j] = 0;
        rolledArray[j] = 0;
        percentErrorArray[j] = 0;
    }
}
