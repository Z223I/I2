// FxLoopTemplateProject.cpp : main project file.

#include "stdafx.h"

using namespace System;

#include "FxLoop.h"

#define MYTYPE int

// Disable warnings when symbols are longer than 255 characters.
#pragma warning(disable:4786)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



bool HasNotReachedUpperBound (FxLoop<MYTYPE>& _myFxLoop) {
	bool bTest;
	bTest = _myFxLoop.HasNotReachedUpperbound();
	return bTest;
}

int analyze(vector<FxLoop<MYTYPE>>& _MyFxLoops) {
	vector<FxLoop<MYTYPE>>::iterator myFxLoopsIter;
	
	FxLoop<MYTYPE> myFxLoop;

    for (
			myFxLoopsIter =  _MyFxLoops.begin(); 
			myFxLoopsIter != _MyFxLoops.end(); 
			myFxLoopsIter++) 
	{
			cout << myFxLoopsIter->iCurrentValue  << "\t";
    }
    cout << endl;

	return 0;
}


// FxLoops will be sorted by NumberOfSteps, not by Name.
bool operator<(const FxLoop<MYTYPE>& x, const FxLoop<MYTYPE>& y)
{
    return x.NumberOfSteps < y.NumberOfSteps;

	// Problem child
    //return x.GetNumberOfSteps() < y.GetNumberOfSteps();
}


// FxLoops will be sorted by NumberOfSteps, not by Name.
bool operator==(const FxLoop<MYTYPE>& x, const FxLoop<MYTYPE>& y)
{
    return x.NumberOfSteps == y.NumberOfSteps;
}

#ifdef INCLUDE_THIS
#endif

// Define a template class for a vector of FxLoops.
typedef vector<FxLoop<MYTYPE>, allocator<FxLoop<MYTYPE>> > NAMEVECTOR;



int main(array<System::String ^> ^args)
{
	FxLoop<MYTYPE> myLoopKaren(1, 4, 1, "Inner Loop");
	FxLoop<MYTYPE> myLoopAda(1, 4, 1, "Outer Loop");
	FxLoop<float> myLoop2;
	
	// Declare a dynamically allocated vector of FxLoops.
    NAMEVECTOR myFxLoops;

    // Iterator is used to loop through the vector.
    NAMEVECTOR::iterator theIterator;


    // Put the objects in the container.
    myFxLoops.push_back(myLoopKaren);
    myFxLoops.push_back(myLoopAda);

    // Output the contents of the vector.
    cout << endl << "NumberOfSteps and variable names:" << endl;
    for ( theIterator = myFxLoops.begin(); 
		  theIterator != myFxLoops.end();
          theIterator++)
        cout << theIterator->NumberOfSteps  << "\t"
             << theIterator->Name << endl;

    cout << endl;


	bool bFinished;

	do {
		analyze(myFxLoops);

		theIterator = 
			find_if(
				myFxLoops.begin(), 
				myFxLoops.end(),
				HasNotReachedUpperBound
			);

		if (theIterator == myFxLoops.end() ) { 
			bFinished = true; 
		} else {
			bFinished = false;
		}

	} while ( !bFinished );  // Can handle any level of nesting


	int iNumberOfStepsCheck;
	bool bSameNumberOfSteps = true;

	iNumberOfStepsCheck = myFxLoops.front().NumberOfSteps;
	for (theIterator = myFxLoops.begin(); theIterator != myFxLoops.end(); theIterator++) {
		if ( theIterator->NumberOfSteps != iNumberOfStepsCheck) {
//		if ( *theIterator.NumberOfSteps != iNumberOfStepsCheck) {
			bSameNumberOfSteps = false;
			break;
		}
	}

	if (!bSameNumberOfSteps) {
		return 1;
	}


	for (int i=1; i<=iNumberOfStepsCheck; i++) {

		analyze(myFxLoops);

		for_each(
			myFxLoops.begin(), 
			myFxLoops.end(),
			HasNotReachedUpperBound
		);

	}

    return 0;
}
