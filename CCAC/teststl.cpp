//
//  stlmap.cpp
//
//
//  Created by Morgan Visnesky on 12/01/18.
//



#include <stdio.h>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  map<string, string> names;
  map<int, string> sortednames;


  names["Paul Brown"] = "123-45-6790";
  names["Mary Smith"] = "123-45-6791";
  names["John Smith"] = "123-45-6789";
  names["Lisa Brown"] = "123-45-6792";

  cout << endl;
  cout << "This program demonstrates the use of an STL map to store" << endl;
  cout << "social security numbers." << endl << endl;

  map<string,string>::const_iterator iter;
  for (iter = names.begin(); iter != names.end(); iter++)
  {
    // first prints original map
    cout << "Person " << iter->second << ": " << iter->first << endl;

    // next three lines format SS and convert to int
    string mystr = iter->second;
    mystr.erase(remove(mystr.begin(),mystr.end(), '-'),mystr.end());
    int num = stoi(mystr);

    // stores values into new map with SS as key and name as value
    // keeps output in numerical order of SS numbers
    sortednames[num] = iter->first;
  }

  cout << endl << "Iterating through the list..." << endl;
  // creates new iterator to print values from new map
  map<int,string>::const_iterator iter2;
  for (iter2 = sortednames.begin(); iter2 != sortednames.end(); iter2++)
  {
    cout << iter2->first << ": " << iter2->second << endl;
  }

  cout << endl;

  if (names.find("John Brown") == names.end())
  {
    cout << "John Brown not found" << endl;
  }

  if (names.find("Paul Brown") != names.end())
  {
    // for loop so output would match example output given
    for (iter2 = sortednames.begin(); iter2 != sortednames.end(); iter2++)
    {
      if (iter2->second == "Paul Brown")
      {
        cout << "Paul Brown found " << iter2->first << endl;
      }
    }
  }

  system("pause");
  return 0;

}
