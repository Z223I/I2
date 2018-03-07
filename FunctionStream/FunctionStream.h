#include <assert.h>
#include <iostream>
using namespace std;


class FunctionStream {
protected:
    int       iParameterCounter;
    bool      bBeenInitialized;    // Parameters been initialized?
    bool      bParallelExecution;  // Execute in Parallel?
    const char*    param_s;             // Default string parameter;
    long int  param_dw;            // Default long integer parameter;
    short int param_w;             // Default short integer parameter;
    double    param_d;             // Default double parameter;
    float     param_f;             // Default float parameter;

public:
    FunctionStream();
    ~FunctionStream();

    //virtual FunctionStream& operator<<(const char* s);
    //virtual FunctionStream& operator<<(long int dw);
    //virtual FunctionStream& operator<<(short int w);
    //virtual FunctionStream& operator<<(double d);
    //virtual FunctionStream& operator<<(float f);

    //virtual FunctionStream& EXECUTE(FunctionStream&) = 0;
};
