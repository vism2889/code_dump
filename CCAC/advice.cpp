//
//  advice.cpp
//  
//
//  Created by Morgan Visnesky on 10/20/18.
//

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string adviceInput;
    std::ifstream inStream;
    std::ofstream outStream;
    char next;
    
    inStream.open("advice.txt");
    if (!inStream.fail())
    {
        string getContent;
        cout << "found advice.txt file." << endl;
        cout << "Old advice: " << endl;
        //inStream.get(next);
        while (!inStream.eof())
        {
            //cout << next;
            //inStream >> getContent;
            std::getline(inStream, getContent);
            cout << getContent << endl;
        }
        cout << "Enter your phrase for the next user: " << endl;
        outStream.open("advice.txt");
        getline(cin, adviceInput);
        outStream << adviceInput;
    }
    else
    {    // This file does NOT exist.
        cout << "Could not open Advice.txt" << endl;
        cout << "Assumption: first run -- creating a new file...";
        inStream.close(); // close the input file stream
        inStream.open("advice.txt", ios::in | ios::out | ios::trunc);  // create new file
        cout << "Enter your phrase for the next user: " << endl;
        outStream.open("advice.txt");
        getline(cin, adviceInput);
        outStream << adviceInput;
    }
    inStream.close();
    outStream.close();
    system("pause");
    return(0);
}

