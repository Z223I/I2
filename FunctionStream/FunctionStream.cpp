#include <iostream>
using namespace std;


class FunctionStream {
private:
    int    iParameterCounter;
    bool bBEENInitialized;  // Parameters been initialized?
    bool bParallelExecution;   // Execute in Parallel?
    string    param_psz; // Default string parameter;
    long int     param_dw; // Default long integer parameter;
    short int param_w; // Default short integer parameter;
    double    param_d; // Default double parameter;
    float    param_f; // Default float parameter;
public:
    virtual FunctionStream& operator<<(string psz);
    virtual FunctionStream& operator<<(long int dw);
    virtual FunctionStream& operator<<(short int w);
    virtual FunctionStream& operator<<(double d);
    virtual FunctionStream& operator<<(float f);
};


FunctionStream& FunctionStream::operator<<(float f) {
    iParameterCounter = iParameterCounter + 1;
    param_f = f;
    return *this;
};

#ifdef USE_ME

class DerivedFunctionStream {
private:
    float param_weight;
    float param_weight_start;
    float param_weight_stop;
    float param_weight_step;
    int param_planet;
    int param_planet_start;
    int param_planet_stop;
    int param_planet_step;
    float fFuelRequired;
public:
    DerivedFunctionStream();
    ~DerivedFunctionStream();
    DerivedFunctionStream& operator<<(int i);
    DerivedFunctionStream& operator<<(float f);
    DerivedFunctionStream& operator>>(float &f);
    float EXECUTE();
    float PARALLEL_EXECUTE();
    void prompts();
}

DerivedFunctionStream::operator<<(int i) {
    iParameterCounter = iParameterCounter + 1;
    switch (iParameterCounter) {
        case 2:
            param_planet = i;
            return *this;
            break;
        default:
            assert(FALSE);
    }
}

DerivedFunctionStream& DerivedFunctionStream::operator<<(float f) {
    iParameterCounter = iParameterCounter + 1;
    switch (iParameterCounter) {
        case 1:
            param_weight = f;
            return *this;
            break;
        default:
            assert(FALSE);
    }
}

DerivedFunctionStream& DerivedFunctionStream::operator>>(float &f) {
    f = fFuelRequired;
}

float DerivedFunctionStream:EXECUTE() {

// Check if weight and planet have not been initialized.
if ( not(bBeenInitialized) ) {
     bParallelExecution = false;
    prompts();
}

f(param_weight, param_planet, &fuel_required);

return fFuelRequired;
}

float DerivedFunctionStream:PARALLEL_EXECUTE() {

// Check if weight and planet have not been initialized.
if ( not(bBeenInitialized) ) {
     bParallelExecution = true;
    prompts();
}
FxVariable weight(param_weight_start, param_weight_stop,
                  param_weight_step);
FxVariable planet(param_planet_start, param_planet_stop,
                  param_planet_step );
Array MyFxVars(1, 0);

MyFxVars.add(weight);
MyFxVars.add(planet);

BOOL bFinished = FALSE;
do {

     spawn(f, MyFxVars, fFuelRequiredArray);
    Object = firstThat(HasNotReachedUpperbound, MyFxVars);

     if (Object == null ) { bFinished = TRUE; }

} while ( !bFinished );

return fFuelRequiredArray;
}

void DerivedFunctionStream::prompts() {
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
        os << endl << "Enter mission weight:";
        is >> param_weight;
        os << endl << "Enter destination planet:";
        is >> param_planet;
     }
}
#endif

int main() {

    float    weight = 0;
    int      planet = 0;
//    DerivedFuntionStream f;

//    f << EXECUTE;

    cout << weight << planet;

    return 0;
}