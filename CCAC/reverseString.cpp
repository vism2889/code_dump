//
//  reverseString.cpp
//  
//
//  Created by Morgan Visnesky on 10/2/18.
//

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <array>
#include <string>
#include <stack>


using namespace std;

int main(void)
{
    string userString;
    char runAgain = 'Y';

    do
    {
        cout << endl << "This program reverses a string using STL stack" << endl;
        cout << "Enter your string of less than 80 characters followed by an ENTER" << endl << endl;
        char* s = (char *)malloc(80);
        cin.getline(s,81, '\n');
        stack<char> revS;
        
        for(int i=0; i<strlen(s); i++)
            revS.push(s[i]);
        
        for(int i=0; i<strlen(s); i++)
        {
            s[i] = revS.top();
            revS.pop();
        }
        
        cout << endl << s << endl << endl;
        free(s);
        cout << "Enter another? (Y/N)" << endl;
        cin >> runAgain;
        int c = getchar();
    }while ((runAgain != 'N' && runAgain != 'n'));
    
    
    system("pause");
}


