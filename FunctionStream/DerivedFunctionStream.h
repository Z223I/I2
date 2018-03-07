#include <assert.h>
#include <iostream>
using namespace std;

#include "FunctionStream.h"

class DerivedFunctionStream : FunctionStream {
private:
    float param_weight;
    float param_weight_start;
    float param_weight_stop;
    float param_weight_step;
    int param_planet;
    int param_planet_start;
    int param_planet_stop;
    int param_planet_step;
    int fFuelRequired;
public:
    DerivedFunctionStream();
    ~DerivedFunctionStream();
    DerivedFunctionStream& operator<<(int i);
    DerivedFunctionStream& operator<<(double f);
    DerivedFunctionStream& operator>>(float &f);
    DerivedFunctionStream& EXECUTE(DerivedFunctionStream& dfs);
    DerivedFunctionStream& operator<<(DerivedFunctionStream& (*m)(DerivedFunctionStream&));
    float PARALLEL_EXECUTE();
    void prompts();
};
