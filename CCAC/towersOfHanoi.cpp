//
//  towersOfHanoi.cpp
//  
//
//  Created by Morgan Visnesky on 10/27/18.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;




void towersOfHanoi(int n, string firstrod, string lastrod, string middlerod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << firstrod << " to " << lastrod << endl;
        return;
    }
    towersOfHanoi(n-1, firstrod, middlerod, lastrod);
    cout << "Move disk " << n << " from " << firstrod << " to " << lastrod << endl;
    towersOfHanoi(n-1, middlerod, lastrod, firstrod);
}
    


int main(void)
{
    int numDisks;
    cout << "How many disks would you like to start with? " << endl;
    cin >> numDisks;
    towersOfHanoi(numDisks, "first rod", "last rod", "middle rod");
    system("pause");
}
