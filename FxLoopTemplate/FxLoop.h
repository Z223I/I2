#include <string>
using namespace std;  // std c++ libs implemented in std

//#if _MSC_VER > 1020   // if VC++ version is > 4.2
//   using namespace std;  // std c++ libs implemented in std
//#endif



// To be able to use this class simulataneously with various types:
//       Create a base class:  EnumTypes
//       create subclasses:    ETInt
//								ETFloat
//								ETFxLoop
// etc.



// The FxLoop class is used for 
template <class T>
class FxLoop
{
public:
    string Name;
	T iStart, iStep, iStop;
	T iCurrentValue;
    int NumberOfSteps;

#ifdef INCLUDE_FULL_CODE
	bool bVariable;
	bool bValid;
#endif

    // Default constructor
	FxLoop() : 
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

	
	// Constructor


	FxLoop(T _iStart, T _iStop, T _iStep, string _sVariableName) 
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


	
	// Copy constructor
	//FxLoop(const FxLoop& lhs);

	FxLoop(const FxLoop& lhs) 
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


//	T Next();

	T Next() {
		if (iCurrentValue + iStep <= iStop) {
			iCurrentValue += iStep;
		}
		return iCurrentValue;
	};

#ifdef INCLUDE_FULL_CODE
#endif

	// Returns the name of the loop.
	string GetName() { return Name; };
	// Calculates the number of steps in the loop.
	int GetNumberOfSteps() {return (iStop - iStart + 1) / iStep;};
	// Returns the current value of the loop.
	T GetValue() {return iCurrentValue;};
	// Returns true or false depending on if the loop has reached its upper bound.
//	bool HasNotReachedUpperbound();

bool HasNotReachedUpperbound() { 
	if (iCurrentValue + iStep <= iStop) {
		iCurrentValue += iStep;
		return true;
	} else {
		iCurrentValue = iStart;
		return false;
	}
}


};
