/*
	AUTHOR: Morgan Visnesky
	DATE: 10/10/2020
 	FILENAME: ece0301_ICA11_step05.cpp
	DESCRIPTION:
	* This is in class assignment #11   for fall 2020 PITT ECE-0301 taught by Dr. Mai Abdelhakim and Dr. Amr Mahmoud.

	* This assignment covers the topic of time doamin signals.
	
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
#include "Signal.cpp"

int main() 
{
	
	Signal signalm(401, 10000, 0);
	signalm.fillSignalVec(0);
	signalm.signalVecFill(0.5, 100, 0.0);
	signalm.setSignalLabel("m");
	
	signalm.setFileNameTemp();
	
	Signal signalw(401, 10000, 0);
	signalw.fillSignalVec(0);
	signalw.fillSignalVec(1);
	signalw.setSignalLabel("w");
	signalw.setFileNameTemp();
	
	Signal signalx(401, 10000, 0);
	signalx.fillSignalVec(0);
	signalx.setSignalLabel("x");
	signalx = signalm + signalw;
	signalx.setFileNameTemp();
	
	
	Signal signaly(401, 10000, 0);
	signaly.fillSignalVec(0);
	signaly.signalVecFill(120,4000, -M_PI/4);
	signaly.setSignalLabel("y");
	signaly.setFileNameTemp();
	
	Signal signalz(401, 10000, 0);
	signalz.fillSignalVec(0);
	signalz.setSignalLabel("z");
	signalz = signalx * signaly;
	signalz.setFileNameTemp();
	
	signalm.rounder();
	signalw.rounder();
	signalx.rounder();
	signaly.rounder();
	signalz.rounder();
	
	signalm.fileOutput();
	signalw.fileOutput();
	signalx.fileOutput();
	signaly.fileOutput();
	signalz.fileOutput();
	
	
	return 0;
}
