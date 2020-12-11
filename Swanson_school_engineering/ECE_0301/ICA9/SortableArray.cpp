/*
	AUTHOR: Morgan Visnesky
	DATE: 09/30/2020
 	FILENAME: ece0301_ICA09_step10.cpp
	DESCRIPTION:
	* This is in class assignment #9   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment is to implement merge sort
*/


#include "SortableArray.h"


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

void SortableArray::pseudoR()
{
	unsigned seed = time(NULL);
	srand(seed);
	for (unsigned int i = 0; i < getNumElem(); i++)
	{
		double rand_01 = static_cast<double>(rand()) / RAND_MAX;
		*(getStartPtr() + i) = 2*rand_01 -1;
	}
	
}
