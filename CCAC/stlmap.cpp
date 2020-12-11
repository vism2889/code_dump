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

using namespace std;

int main()
{
  map<string, int> names;
  map<int, string> sortednames;


  names["Paul Brown"] = 123456790;
  names["Mary Smith"] = 123456791;
  names["John Smith"] = 123456789;
  names["Lisa Brown"] = 123456792;

  cout << endl;

  map<string,int>::const_iterator iter;
  for (iter = names.begin(); iter != names.end(); iter++)
  {
    // first prints original map
    // would have liked to format SS with hyphen's
    cout << "Person " << iter->second << ": " << iter->first << endl;
    sortednames[iter->second] = iter->first;
    // stores values into new map with SS as key and name as value
    // keeps output in numerical order of SS numbers
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
    cout << "Paul Brown found " << names["Paul Brown"] << endl;
  }
  
  system("pause");
  return 0;
}
