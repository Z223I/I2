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
//#pragma warning(disable:4786)


FxLoop::FxLoop() : 
		Name(""), 
		iStart(0),
		iStep(0),
		iStop(0),

#ifdef INCLUDE_FULL_CODE
		bVariable(false),
		bValid(true),
#endif

		NumberOfSteps(0)
{
};

FxLoop::FxLoop(int _iStart, int _iStop, int _iStep, string _sVariableName) 
	: iStart(_iStart), iStop(_iStop), iStep(_iStep), Name(_sVariableName), iCurrentValue(_iStart)
{
	
	iCurrentValue = iStart;
	
	NumberOfSteps = GetNumberOfSteps();

#ifdef INCLUDE_FULL_CODE
	if (iStart == iStop) {
		bVariable = false;
	}
	else
	{
		bVariable = true;
	}
	bValid = true;
#endif

};


	
FxLoop::FxLoop(const FxLoop& lhs) 
	{
		
		iCurrentValue = lhs.iCurrentValue;
		iStart        = lhs.iStart;
		iStep         = lhs.iStep;
		iStop         = lhs.iStop;
		NumberOfSteps = lhs.NumberOfSteps;

#ifdef INCLUDE_FULL_CODE
		bVariable     = lhs.bVariable;
		bValid        = lhs.bValid;
#endif

	};


bool FxLoop::HasNotReachedUpperbound() { 
	if (iCurrentValue + iStep <= iStop) {
		iCurrentValue += iStep;
		return true;
	} else {
		iCurrentValue = iStart;
		return false;
	}
}




#ifdef INCLUDE_FULL_CODE
int FxLoop::Next() {
		if (iCurrentValue + iStep <= iStop) {
			iCurrentValue += iStep;
		}
		return iCurrentValue;
	};
#endif

