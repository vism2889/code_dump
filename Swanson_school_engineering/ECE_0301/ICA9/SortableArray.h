/*
	AUTHOR: Morgan Visnesky
	DATE: 09/30/2020
 	FILENAME: ece0301_ICA09_step10.cpp
	DESCRIPTION:
	* This is in class assignment #9   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment is to implement merge sort
*/

#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

/***********************************************************************
 * SortableArray class holds data members and functions that will be used
 * to create a sortable array object and perferm operations on it.
************************************************************************/
class SortableArray
{
	private:
		double *startPtr;
		unsigned int numElem;
		void mergeArrays(double *, double *, unsigned int, unsigned int, unsigned int); 
		void splitArrays(double *, double *, unsigned int, unsigned int);
	public:
		SortableArray();
		SortableArray(unsigned int);
		~SortableArray();
		double *getStartPtr();
		unsigned int getNumElem();
		void zeroFill();
		void displayOutput(ofstream &, bool);
		void completeSort();
		void pseudoR();
};

#endif
