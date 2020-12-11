/*
	AUTHOR: Morgan Visnesky
	DATE: 09/30/2020
 	FILENAME: ece0301_ICA09_step07.cpp
	DESCRIPTION:
	* This is in class assignment #9   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment is to implement merge sort
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <memory>

using namespace std;

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
		void completeSort();
};

SortableArray::SortableArray(unsigned int elem)
{
	numElem = elem;
	startPtr = new double[elem];
	zeroFill();
	
}


SortableArray::SortableArray()
{
	numElem = 10;
	startPtr = new double[10];
	zeroFill();
}

SortableArray::~SortableArray()
{
	delete [] startPtr;
}

double *SortableArray::getStartPtr()
{
	return startPtr;
}

unsigned int SortableArray::getNumElem()
{
	return numElem;
}

void SortableArray::zeroFill()
{
	for (unsigned int i = 0; i < getNumElem(); i++)
	{
		startPtr[i] = 0;
	}
}

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
		outfile << "Sorted Array:" << endl;
	
		for (unsigned int i = 0; i < getNumElem(); i++)
		{
			outfile << getStartPtr()[i] << endl;
		}
	}
	
}

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

void SortableArray::splitArrays(double * addressPre, double * addressPost, unsigned int indexPre, unsigned int indexPost)
{
	if (indexPost != (indexPre+1))
	{
		unsigned int mid = (indexPre + indexPost)/2;
		splitArrays(addressPost, addressPre, indexPre, mid);
		splitArrays(addressPost, addressPre, mid, indexPost);
		mergeArrays(addressPre, addressPost, indexPre, mid, indexPost);
	}
}

void SortableArray::completeSort()
{
	double * newPtr = getStartPtr();
	SortableArray workingArr(getNumElem());
	double * workingPtr = workingArr.getStartPtr();
	
	for (unsigned int i = 0; i < getNumElem(); i++)
	{
		workingArr.getStartPtr()[i] = getStartPtr()[i];
	}
	splitArrays(workingPtr, newPtr, 0, getNumElem());
	
}

SortableArray readFile(ifstream &);

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

int main()
{
	ofstream fileOut;
	fileOut.open("ece0301_merge_sort_results.txt");
	
	ifstream inFile;
	inFile.open("ece_0301_unsorted_array.txt");
	
	SortableArray sArr = readFile(inFile);
	sArr.displayOutput(fileOut, false);
	sArr.completeSort();
	sArr.displayOutput(fileOut, true);
	
	sArr.~SortableArray();
	fileOut.close();
	inFile.close();
	
	return 0;
}
