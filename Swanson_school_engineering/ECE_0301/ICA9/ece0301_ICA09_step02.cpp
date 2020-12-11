/*
	AUTHOR: Morgan Visnesky
	DATE: 09/30/2020
 	FILENAME: ece0301_ICA09_step03.cpp
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
		void displayOutput(ofstream &);
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

void SortableArray::displayOutput(ofstream &outfile)
{
	outfile << "ECE 0301 - Sorting Arrays" << endl;
	outfile << "Unsorted Array:" << endl;
	
	for (unsigned int i = 0; i < getNumElem(); i++)
	{
		outfile << getStartPtr()[i] << endl;
	}
}

SortableArray readFile(ifstream &);

SortableArray readFile(ifstream &file)
{
	//SortableArray array;
	string correctHeader = "LENGTH = ";
	string header;
	getline(file, header);
	unsigned int numFromFile;
	
	numFromFile = static_cast<unsigned int>(stoi(header.substr(9)));
	//int unNum = numFromFile;
	header = header.substr(0,9);
	cout << header << endl << numFromFile << endl;
	
	
	
	if (header != correctHeader)
	{
		cout << "ERROR! Invalid file header.";
		//return -1;
	}
	SortableArray newArray = SortableArray(numFromFile);
	//double numLine;
	
	for (unsigned int i = 0; i < numFromFile; i++)
	{
		//file >> numLine;
		file >> *(newArray.getStartPtr()+i);
		//cout << "Numline: " << numLine << endl;
		
		//newArray.getStartPtr()[i] = numLine;
		cout << *(newArray.getStartPtr()+i) << endl;
	}
	
	return newArray;
}

int main()
{
	ofstream fileOut;
	fileOut.open("ece0301_merge_sort_results.txt");
	
	ifstream inFile;
	inFile.open("ece_0301_unsorted_array.txt");
	//SortableArray arr = readFile(inFile);
	
	SortableArray sArr = readFile(inFile);
	sArr.displayOutput(fileOut);
	
	sArr.~SortableArray();
	fileOut.close();
	inFile.close();
	
	return 0;
}
