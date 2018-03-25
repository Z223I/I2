#include "FxLoop.h"

//////////////////////////////////////////////////////////////////////
//
// Compile options needed: /GX
//
//    Opless.cpp -- Illustrates the defining the < operator to sort vectors
//
// Functions:
//
//    operator< - Vector comparison operator.
//
//    vector::begin - Returns an iterator to start traversal of the vector.
//
//    vector::end - Returns an iterator for the last element of the vector.
//
//    vector::iterator - Traverses the vector.
//
//    vector::push_back - Appends (inserts) an element to the end of a
//                        vector, allocating memory for it if necessary.
//
//    sort algorithm - Sorts the vector.
//
// Written by Tom Campbell
// of Microsoft Corporation
// Copyright (c) 1996 Microsoft Corporation. All rights reserved.
//////////////////////////////////////////////////////////////////////

// The debugger can't handle symbols more than 255 characters long.
// STL often creates symbols longer than that.
// When symbols are longer than 255 characters, the warning is disabled.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//#if _MSC_VER > 1020   // if VC++ version is > 4.2
//   using namespace std;  // std c++ libs implemented in std
//#endif




#define INCLUDE_THIS
#ifdef INCLUDE_THIS

bool HasNotReachedUpperBound (FxLoop<int>& _myFxLoop) {
	bool bTest;
	bTest = _myFxLoop.HasNotReachedUpperbound();
	return bTest;
}

int analyze(vector<FxLoop<int>>& _MyFxLoops) {
//	vector<FxLoop>::const_iterator myFxLoopsIter;
	vector<int>::const_iterator myFxLoopsIter;
	
	FxLoop<int> myFxLoop;

    for (
			myFxLoopsIter =  _MyFxLoops.begin(); 
			myFxLoopsIter != _MyFxLoops.end(); 
			myFxLoopsIter++) 
	{
			cout << myFxLoopsIter->NumberOfSteps  << "\t"
				 << myFxLoopsIter->iCurrentValue  << "\t"
				 << myFxLoopsIter->Name << endl;
    }
    cout << endl;

	return 0;
}


// FxLoops will be sorted by NumberOfSteps, not by Name.
bool operator<(const FxLoop<int>& x, const FxLoop<int>& y)
{
    return x.NumberOfSteps < y.NumberOfSteps;

	// Problem child
    //return x.GetNumberOfSteps() < y.GetNumberOfSteps();
}


// FxLoops will be sorted by NumberOfSteps, not by Name.
bool operator==(const FxLoop<int>& x, const FxLoop<int>& y)
{
    return x.NumberOfSteps == y.NumberOfSteps;
}



// Define a template class for a vector of FxLoops.
typedef vector<FxLoop<int>, allocator<FxLoop<int>> > NAMEVECTOR;


#endif

int main()
{


	FxLoop<int> myLoop(0, 9, 1, "Loop");
	FxLoop<float> myLoop2;
    

#ifdef INCLUDE_THIS
	
	// Declare a dynamically allocated vector of FxLoops.
    NAMEVECTOR myFxLoops;

    // Iterator is used to loop through the vector.
    NAMEVECTOR::iterator theIterator;



    //FxLoop myFxLoop(0, 9, 1, "Inner Loop");


    // Create a pseudo-random vector of players and NumberOfStepss.
    myFxLoops.push_back(FxLoop(0, 9, 1, "Karen Palmer"));
    myFxLoops.push_back(FxLoop(0, 9, 1, "Ada Campbell"));
//    myFxLoops.push_back(FxLoop(1, 3, 1, "John Woloschuk"));
//    myFxLoops.push_back(FxLoop(1, 2, 1, "Grady Leno"));

    // Output the contents of the vector.
    cout << endl << "NumberOfSteps and variable names:" << endl;
    for (theIterator = myFxLoops.begin(); theIterator != myFxLoops.end();
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


		//Object = firstThat(HasNotReachedUpperbound, MyFxVars);
		if (theIterator == myFxLoops.end() ) { 
			bFinished = true; 
		} else {
			bFinished = false;
		}


	} while ( !bFinished );  // Can handle any level of nesting


#endif


}
