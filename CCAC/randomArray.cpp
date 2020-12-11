//
//  randomArray.cpp
//  
//
//  Created by Morgan Visnesky on 9/21/18.
//
//
// Write a program that generates random numbers between 1 and 10 and fill an array of  size 20 with
// them.  Have your program sort the array then output in order the number of occurrences of each random number
// generated.  Use the STL sort function to sort your array.
//
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <time.h>

int randomNums[20];
int countArray[11];
int randomNum();
int counter = 1;

using namespace std;

int main(void)
{
    char runAgain = 'Y';
    
    cout << endl << "This program generates random numbers and tabulates the results." << endl << endl;
    do
    {
        srand(time(0));
        
        
        for (int i = 1; i < 11; i++)
        {
            countArray[i] = 0;
        }
        
        
        for (int i = 0; i < 20; i++)
        {
            int t = randomNum();
            randomNums[i] = t;
            countArray[t]++;
        }
        cout << "Your original List: " << endl;
        for (int i = 0; i < 20; i++)
        {
            cout << "a[" << counter << "]" << randomNums[i] << endl;
            counter ++;
        }
        
        
        counter = 1;
        sort(randomNums, randomNums+20);
        cout << "Your list sorted: " << endl;
        for (int i = 0; i < 20; i++)
        {
            cout << "a[" << counter << "]" << randomNums[i] << endl;
            counter++;
        }
        
        cout << "Occurances: " << endl;
        for (int i = 1; i < 11; i++)
        {
            cout << i << ": " << countArray[i] << endl;
        }
        
        cout << "Would you like to make another calculation? (Y/N)" << "\n";
        cin >> runAgain;
    } while ((runAgain != 'N' && runAgain != 'n'));
    
    system("pause");
}

int randomNum()
{
    int num = (1 + rand() % 10);
    return num;
}
