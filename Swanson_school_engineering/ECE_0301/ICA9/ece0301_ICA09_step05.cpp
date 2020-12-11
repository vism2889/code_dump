/*
	AUTHOR: Morgan Visnesky
	DATE: 09/30/2020
 	FILENAME: ece0301_ICA09_step05.cpp
	DESCRIPTION:
	* This is in class assignment #9   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment is to implement merge sort in C++
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <memory>

using namespace std;

/***********************************************************************
 * SortableArray class holds data members and functions that will be used
 * to create a sortable array object and perferm operations on it.
************************************************************************/
class SortableArray
{
	private:
		double *startPtr;
		unsigned int numElem;
	public:
		SortableArray();
		SortableArray(unsigned int);
		~SortableArray();
		double *getStartPtr();
		unsigned int getNumElem();
		void zeroFill();
		void displayOutput(ofstream &, bool);
		void mergeArrays(double *, double *, unsigned int, unsigned int, unsigned int); 
		void splitArrays(double *, double *, unsigned int, unsigned int);
};

/***********************************************************************
 * Constructor that takes an unsigned int as an argument which is used to 
 * set the size of the sortable array object.
 * Sortable array is filled with zeros.
************************************************************************/
SortableArray::SortableArray(unsigned int elem)
{
	numElem = elem;
	startPtr = new double[elem];
	zeroFill();
	
}

/***********************************************************************
 * Default constructor 
 * Sets the size of the sortable array object to 10.
 * Sortable array is filled with zeros.
************************************************************************/
SortableArray::SortableArray()
{
	numElem = 10;
	startPtr = new double[10];
	zeroFill();
}

/***********************************************************************
 * Default deconstructor
************************************************************************/
SortableArray::~SortableArray()
{
	delete [] startPtr;
}

/***********************************************************************
 * Accessor method that returns the poiter which poitnts to the start 
 * of the sortable array object.
************************************************************************/
double *SortableArray::getStartPtr()
{
	return startPtr;
}

/***********************************************************************
 * Accessor method that returns the number of elements in the sortable 
 * array object.
************************************************************************/
unsigned int SortableArray::getNumElem()
{
	return numElem;
}

/***********************************************************************
 * Member function that fills the sortable array object with zeros.
************************************************************************/
void SortableArray::zeroFill()
{
	for (unsigned int i = 0; i < getNumElem(); i++)
	{
		startPtr[i] = 0;
	}
}

/***********************************************************************
 * Member function that displays the sortable array object to a output
 * file passed by reference.
 * If the bool argument is false the unsorted array is displayed.
 * If the argument is true the sorted array is displayed.
************************************************************************/
void SortableArray::displayOutput(ofstream &outfile, bool sorted)
{
	
	if (sorted == false)
	{
		outfile << "ECE 0301 - Sorting Arrays" << endl;
		outfile << "Unsorted Array:" << endl;
	
		for (unsigned int i = 0; i < getNumElem(); i++)
		{
			outfile << getStartPtr()[i] << endl;
		}
	}
	
	if (sorted == true)
	{
		//outfile << "ECE 0301 - Sorting Arrays" << endl;
		outfile << "Sorted Array:" << endl;
	
		for (unsigned int i = 0; i < getNumElem(); i++)
		{
			outfile << getStartPtr()[i] << endl;
		}
	}
	
}

/***********************************************************************
 * Member function that is used to merge to subarrays and sort the 
 * data member array. This is done with pointers.
************************************************************************/
void SortableArray::mergeArrays(double * addressPre, double * addressPost, unsigned int indexBLACKGREEN, unsigned int indexGRAYRED, unsigned int indexBLUE) 
{
	double *black, *gray, *red, *blue, *green;
	
	black = addressPre + indexBLACKGREEN;
	gray = addressPre + indexGRAYRED;
	red = addressPre + indexGRAYRED;
	blue = addressPre + indexBLUE;
	green = addressPost + indexBLACKGREEN;
	
	while (black < red && gray < blue)
	{
		if (*black < *gray)
		{
			*green = *black;
			black++;
			green++;
		}
		else
		{
			*green = *gray;
			gray++;
			green++;
		}
		
	}
	
	while (black < red)
	{
		*green = *black;
		green++;
		black++;
	}
	
	while (gray < blue)
	{
		*green = *gray;
		gray++;
		green++;
	}
}

/***********************************************************************
* Member function that is used to help sort arrays by splitting them into 
* subarrays.
************************************************************************/
void SortableArray::splitArrays(double * addressPre, double * addressPost, unsigned int indexPre, unsigned int indexPost)
{
	unsigned int mid = (indexPre + indexPost)/2;
	mergeArrays(addressPre, addressPost, indexPre, mid, indexPost);
}

SortableArray readFile(ifstream &);

/***********************************************************************
* Function that is used to read data from a file and create a sortable 
* array object set to the given length and the correct values.
************************************************************************/
SortableArray readFile(ifstream &file)
{
	string correctHeader = "LENGTH = ";
	string header;
	getline(file, header);
	unsigned int numFromFile;
	
	numFromFile = static_cast<unsigned int>(stoi(header.substr(9)));
	
	header = header.substr(0,9);
	
	if (header != correctHeader)
	{
		cout << "ERROR! Invalid file header.";
	}
	SortableArray newArray = SortableArray(numFromFile);
	
	for (unsigned int i = 0; i < numFromFile; i++)
	{
		file >> *(newArray.getStartPtr()+i);
	}
	return newArray;
}

/***********************************************************************
 * Main function used to create a sortable array object, and two file stream objects
 * one that is used to read from a file, and one that is used to display the results.
 * Once the sortable array object is created the unsorted output is displayed
 * followed by the sorted output.
************************************************************************/
int main()
{
	ofstream fileOut;
	fileOut.open("ece0301_merge_sort_results.txt");
	
	ifstream inFile;
	inFile.open("ece_0301_unsorted_array.txt");
	
	SortableArray sArr = readFile(inFile);
	sArr.displayOutput(fileOut, false);
	SortableArray arr2(sArr.getNumElem());
	sArr.splitArrays(sArr.getStartPtr(), arr2.getStartPtr(), 0, arr2.getNumElem());
	arr2.displayOutput(fileOut, true);
	
	sArr.~SortableArray();
	arr2.~SortableArray();
	fileOut.close();
	inFile.close();
	
	return 0;
}
