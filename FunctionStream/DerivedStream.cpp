//#include <assert.h>
//#include <iostream>
//using namespace std;



class DerivedFunctionStream {
    int   param_planet;
    float param_weight;

public:
    DerivedFunctionStream();
    ~DerivedFunctionStream();
    DerivedFunctionStream& operator<<(int i);
    DerivedFunctionStream& operator<<(double f);
//    DerivedFunctionStream& operator>>(float &f);
//    DerivedFunctionStream& EXECUTE(DerivedFunctionStream& dfs);
//    void prompts();
};


DerivedFunctionStream::DerivedFunctionStream() {
    param_planet = 0;
    param_weight = 0;
}


DerivedFunctionStream::~DerivedFunctionStream() {
}

DerivedFunctionStream& DerivedFunctionStream::operator<<(int i) {
    param_planet = i;
    return *this;
};

DerivedFunctionStream& DerivedFunctionStream::operator<<(double f) {
    param_weight = f;
    return *this;
};

#ifdef LSDKFJISEFPEISHJ
DerivedFunctionStream& DerivedFunctionStream::operator>>(float &f) {
    f = fFuelRequired;
    return *this;
};

DerivedFunctionStream& DerivedFunctionStream::EXECUTE(DerivedFunctionStream& dfs) {

// Check if weight and planet have not been initialized.
if ( not(this->bBeenInitialized) ) {
    bParallelExecution = false;
    //prompts();
};

//float fFuelRequired;

//f(param_weight, param_planet, &fuel_required);
//fFuelRequired = param_weight * param_planet;

return dfs;
};


#endif


int main() {
    DerivedFunctionStream f;
    f << 8.0 << 7;
    return 0;
};
