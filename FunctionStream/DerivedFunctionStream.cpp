#include <assert.h>
#include <iostream>
#include <array>
using namespace std;

#include "DerivedFunctionStream.h"
#include "FxLoop.h"

DerivedFunctionStream::DerivedFunctionStream() : FunctionStream() {
}


DerivedFunctionStream::~DerivedFunctionStream() {
}

DerivedFunctionStream& DerivedFunctionStream::operator<<(int i) {
    iParameterCounter = iParameterCounter + 1;
    switch (iParameterCounter) {
        case 2:
            param_planet = i;
            break;
        default:
            assert(false);
    }

    return *this;
};

DerivedFunctionStream& DerivedFunctionStream::operator<<(double f) {
    iParameterCounter = iParameterCounter + 1;
    switch (iParameterCounter) {
        case 1:
            param_weight = f;
            break;
        default:
            assert(false);
    }
    return *this;
};

DerivedFunctionStream& DerivedFunctionStream::operator>>(float &f) {
    f = fFuelRequired;
    return *this;
};

void f(int param_weight, int param_planet, int &fuel_required) {
    fuel_required = param_weight * param_planet;
    cout << "Hello World!" << endl;
}

DerivedFunctionStream& DerivedFunctionStream::EXECUTE(DerivedFunctionStream& dfs) {

// Check if weight and planet have not been initialized.
if ( not(this->bBeenInitialized) ) {
    bParallelExecution = false;
    prompts();
};

    //float fFuelRequired;

    f(param_weight, param_planet, fFuelRequired);
//fFuelRequired = param_weight * param_planet;

return dfs;
};

DerivedFunctionStream& DerivedFunctionStream::operator<<(DerivedFunctionStream& (*m)(DerivedFunctionStream&)) {
    return  (*m)(*this);
};

float DerivedFunctionStream::PARALLEL_EXECUTE() {

// Check if weight and planet have not been initialized.
if ( not(bBeenInitialized) ) {
     bParallelExecution = true;
    prompts();
};

FxLoop weight(param_weight_start, param_weight_stop,
                  param_weight_step, "weight");
FxLoop planet(param_planet_start, param_planet_stop,
                  param_planet_step, "planet" );
//Array MyFxLoops(1, 0);
array<FxLoop, 2> MyFxLoops;

MyFxLoops[0] = weight;
MyFxLoops[1] = planet;
FxLoop Object;

//#ifdef USE_ME
bool bFinished = false;
do {

    //spawn(f, MyFxLoops, fFuelRequiredArray);
    Object = firstThat(HasNotReachedUpperbound, MyFxLoops);

        if (Object == null ) { bFinished = true; }

} while ( !bFinished );
#ifdef USE_ME

#endif

float fFuelRequiredArray = 0;
return fFuelRequiredArray;
};

void DerivedFunctionStream::prompts() {
    //ostream os;
    //istream is;
#define os cout
#define is cin

    if (bParallelExecution == true) {
        os << endl << "Enter mission weight";
        os << endl << "Start";
        is >> param_weight_start;
        os << endl << "Stop";
        is >> param_weight_stop;
        os << endl << "Increment";
        is >> param_weight_step;

        os << endl << "Enter destination planet";
        os << endl << "Start";
        is >> param_planet_start;
        os << endl << "Stop";
        is >> param_planet_stop;
        os << endl << "Increment";
        is >> param_planet_step;
    } else {
        os << endl << "Enter mission weight: ";
        is >> param_weight;
        os << endl << "Enter destination planet: ";
        is >> param_planet;
     }
};
