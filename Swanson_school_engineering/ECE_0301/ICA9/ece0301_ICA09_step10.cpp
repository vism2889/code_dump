/*
	AUTHOR: Morgan Visnesky
	DATE: 09/30/2020
 	FILENAME: ece0301_ICA09_step10.cpp
	DESCRIPTION:
	* This is in class assignment #9   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment is to implement merge sort
*/

#include <string>
#include <fstream>
#include <memory>
#include <cstdlib>
#include <ctime>


using namespace std;
#include "SortableArray.cpp"
int main()
{
	ofstream fileOut;
	fileOut.open("ece0301_merge_sort_results.txt");
	
	SortableArray bigSort(256);
	bigSort.pseudoR();
	bigSort.displayOutput(fileOut,false);
	bigSort.completeSort();
	bigSort.displayOutput(fileOut,true);
	fileOut.close();
	return 0;
}
