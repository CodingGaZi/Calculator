#include <iostream>
#include "Integer.h"

using namespace std;

int main() {
    Integer a;
    Integer b;
    a.Read();
    b.Read();
    cout << (a + b) << endl;
    cout << (a - b) << endl;
    cout << (a * b) << endl;
    cout << (a / b) << endl;
    cout << (a % b) << endl;
    cout << (a ^ b) << endl;
    cout << ((a < b) ? "True" : "False") << endl;
    cout << ((a > b) ? "True" : "False") << endl;
    cout << ((a <= b) ? "True" : "False") << endl;
    cout << ((a >= b) ? "True" : "False") << endl;
    cout << ((a == b) ? "True" : "False") << endl;
    cout << ((a != b) ? "True" : "False") << endl;
    cout << (a++) << endl;
    cout << (++a) << endl;
    cout << (b--) << endl;
    cout << (--b) << endl;
    return 0; 
}