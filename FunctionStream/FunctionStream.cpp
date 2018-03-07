#include <assert.h>
#include <iostream>
using namespace std;

#include "FunctionStream.h"


FunctionStream::FunctionStream() {
    iParameterCounter = 0;
}


FunctionStream::~FunctionStream() {
}


/*
FunctionStream& FunctionStream::operator<<(const char* s) {
    iParameterCounter = iParameterCounter + 1;
    param_s = s;
    return *this;
};


FunctionStream& FunctionStream::operator<<(long int dw) {
    iParameterCounter = iParameterCounter + 1;
    param_dw = dw;
    return *this;
};


FunctionStream& FunctionStream::operator<<(short int w) {
    iParameterCounter = iParameterCounter + 1;
    param_w = w;
    return *this;
};


FunctionStream& FunctionStream::operator<<(double d) {
    iParameterCounter = iParameterCounter + 1;
    param_d = d;
    return *this;
};


FunctionStream& FunctionStream::operator<<(float f) {
    iParameterCounter = iParameterCounter + 1;
    param_f = f;
    return *this;
};
*/

