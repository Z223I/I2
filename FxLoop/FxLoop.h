#include <string>
using namespace std;  // std c++ libs implemented in std

//#if _MSC_VER > 1020   // if VC++ version is > 4.2
//   using namespace std;  // std c++ libs implemented in std
//#endif



// The FxLoop class is used for 
class FxLoop
{
public:
    string Name;
	int iStart, iStep, iStop;
	int iCurrentValue;
    int NumberOfSteps;

#ifdef INCLUDE_FULL_CODE
	bool bVariable;
	bool bValid;
#endif

    // Default constructor
	FxLoop();

	// Constructor
	FxLoop(int _iStart, int _iStop, int _iStep, string _sVariableName);
	
	// Copy constructor
	FxLoop(const FxLoop& lhs);

#ifdef INCLUDE_FULL_CODE
	int Next();
#endif

	// Returns the name of the loop.
	string GetName() { return Name; };
	// Calculates the number of steps in the loop.
	int GetNumberOfSteps() {return (iStop - iStart + 1) / iStep;};
	// Returns the current value of the loop.
	int GetValue() {return iCurrentValue;};
	// Returns true or false depending on if the loop has reached its upper bound.
	bool HasNotReachedUpperbound();

};
