#include <assert.h>
#include <iostream>
using namespace std;

#include "DerivedFunctionStream.h"



DerivedFunctionStream& EXECUTE(DerivedFunctionStream& dfs) {
    return dfs.EXECUTE(dfs);
};


int main() {

    DerivedFunctionStream f;
//#define EXECUTE DerivedFunctionStream::EXECUTE
    f << 8.0 << 7 << EXECUTE;

    int fuel = 0;
    //f >> fuel;  // TODO:  Fix this.

    cout << "Fuel: " << fuel << endl;

    return 0;
};
