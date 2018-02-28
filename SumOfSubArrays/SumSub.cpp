#include <iostream>
#include <sstream>
#include <array>
#include <assert.h>
//#define NDEBUG  // Turns of asserts for production code.

using namespace std;

struct values {
    int start;
    int stop;
};

const int MAX_INTS = 100;
typedef array<int, MAX_INTS> MyArray;

class Process {
    /* Process class documentation */

public:
    Process() {
        /* Initializer does nothing. */
        return;
    };

    values run(int n, int sum, MyArray ints) {
        /* 
        run searches through the array searching for consecutive numbers
        which at to sum.
        */

        int iStart;
        int iStop;

        // Index through the array.
        for (int i=0; i<n; i++) {
                int count;
                //cout << "index: " << i << endl;

                count = 0;
                iStart = i;
                iStop = i;

                // Step through subarray.
                for (int j=i; j<n && count != sum; j++) {
                    // Add to count.
                    count += ints[j];

                    // Does count equal sum?
                    if (count == sum) {
                        // Store start and stop in vals.
                        iStop = j;
                        break;
                    };
                };
            if (count == sum) {
                break;
            };
        };

        values vals;

        // The answer requires the array index to start from 1.
        vals.start = iStart + 1;
        vals.stop  = iStop + 1;
        return vals;
    };


};

bool Test1() {
    Process myProcess = Process();

    int N = 5;
    int S = 12;
    MyArray inArray = {1, 2, 3, 7, 5};

    values theVals;
    theVals = myProcess.run(N, S, inArray);

    assert( theVals.start == 2 );
    assert( theVals.stop == 4 );

    return true;
}

bool Test2() {
    Process myProcess = Process();

    int N = 10;
    int S = 15;
    MyArray inArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    values theVals;
    theVals = myProcess.run(N, S, inArray);

    assert( theVals.start == 1 );
    assert( theVals.stop == 5 );

    return true;
}

int main ()
{

#define MY_TEST_MODE 1

#if MY_TEST_MODE == 1
    cout << "Begin Test Mode..." << endl;

    bool test1_result;
    test1_result = Test1();
    if (test1_result) { cout << "."; } else { cout << "F"; }

    bool test2_result;
    test2_result = Test2();
    if (test2_result) { cout << "."; } else { cout << "F"; }

    cout << endl;
#else
    Process myProcess = Process();

    int T;
    cout << "Please enter T: ";
    cin >> T;

    // Read T tests.
    for (int i=1; i<=T; i++) {
        int N;
        int S;

        // Read number of ints and sum.
        cout << "Please enter N and S: ";
        cin >> N >> S;

        MyArray inArray;

        // Enter N positive integers.
        for (int j=1; j<=N; j++) {
            cout << "Enter number: ";
            int val;
            cin >> val;
            inArray[j - 1] = val;
            cout << endl;
        }

        cout << endl;
        cout << "[";
        for (int j=1; j<=N; j++) {
            cout << inArray[j - 1];

            if (j < N) {
                cout << ", ";
            } else {
                cout << "]";
                cout << endl;
            }
        }

        values theVals;
        theVals = myProcess.run(N, S, inArray);
        cout << "Start: " << theVals.start 
             << ", Stop: " << theVals.stop
             << endl;

    }
#endif

        return 0;
};