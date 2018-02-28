#include <iostream>
#include <sstream>

using namespace std;

int main() {

    string string1 = "1 2 3 4";
    istringstream stream1(string1);
    int n;
    int prev = 0;
    bool con = true;

    do {
        stream1 >> n;

        if (n != prev)
        {
            cout << n;
            prev = n;
        } else
        {
            cout << "Bye!" << endl;
            con = false;
        }

    } while ( con );
}
