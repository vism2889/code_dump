//
//  binarysearchtemplate.cpp
//
//
//  Created by Morgan Visnesky on 11/10/18.
//
/**
#include <iostream>
#include <math.h>

using namespace std;

template <class T>
bool binary_search(const T ar[], int low, int high, const T& key);


//template <class T>
//void binarySearch


template <class T>
bool binary_search(const T ar[], int low, int high, const T& key)
{
  T mid;

  while ( low <= high )
    {
      // find the middle index
      mid = low + ((high - low) >> 1);

      if ( ar[mid] == key ) // key found
        {
          return true;
        }
      else if ( ar[mid] != key ) // key may be on the left half
        {
          high = mid - 1;
        }
      else if ( ar[mid] < key ) // key may be on the right half
        {
          low = mid + 1;
        }
    }

  // key not found
  return false;
}

int main()
{
  int ar[] = {0, 1, 10, 2, 3, 5, 6, 13, 21, 32, 55};

  for ( int i = 0; i < sizeof(ar) / sizeof(ar[0]); ++i )
    {
      if ( binary_search(ar, 0, sizeof(ar) / sizeof(ar[0]) - 1, ar[i]) )
        {
          std::cout << ar[i] << " is present at index: " << i << std::endl;
        }
      else
        {
          std::cout << ar[i] << " is not present" << std::endl;
        }
    }

  //string ar3[] = {"boy", "girl", "man", "woman"};
  int ar1[] = {-1, 2, 3, 12, 23, 50, 90, 98, 100};
  for ( int i = 0; i < sizeof(ar1) / sizeof(ar1[0]); ++i )
    {
      if ( binary_search(ar, 0, sizeof(ar) / sizeof(ar[0]) - 1, ar1[i]) )
        {
          std::cout << ar1[i] << " is present at index: " << i << std::endl;
        }
      else
        {
          std::cout << ar1[i] << " is not present" << std::endl;
        }
    }
  return 0;
}

**/


#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
int binarysearch(T array[], int first, int last, T item);



template<class T>
int binarysearch(T array[], int first, int last, T item)
{
	int mid = (first + last) / 2;
	if(first > last)
  {
      return 0;
  }
	if(item == array[mid])
  {
      return mid;
  }
	if(item < array[mid])
  {
      return binarysearch(array, first, mid - 1, item);
  }
	return binarysearch(array, mid + 1, last, item);
}

int main()
{
  cout << endl;
  cout << "This program should perform a binary search on different data types:" << endl;
  cout << "WARNING: This program does not function with strings yet, only chars and ints!" << endl;
  int ar1[] = { 5, 8, 3, 5, 6, 13, 21, 32, 55, 60, 10, 20, 0, 0, 0};
  char ar[] = {'a','a','b','c'};

  for ( int i = 0; i < sizeof(ar) / sizeof(ar[0]); ++i )
    {
      if ( binarysearch(ar, 0, sizeof(ar) / sizeof(ar[0]) - 1, ar[i]) )
        {
          cout << ar[i] << " is present at index: " << i << std::endl;
        }
      else
        {
          cout << ar[i] << " is not present" << std::endl;
        }
    }

    cout << endl << endl;

    for ( int i = 0; i < sizeof(ar1) / sizeof(ar1[0]); ++i )
      {
        if ( binarysearch(ar1, 0, sizeof(ar1) / sizeof(ar1[0]) - 1, ar1[i]) )
          {
            cout << ar1[i] << " is present at index: " << i << std::endl;
          }
        else
          {
            cout << ar1[i] << " is not present" << std::endl;
          }
      }

  system("pause");
  return 0;
}
