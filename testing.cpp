#include "Donkey.h"
#include "Tail.h"
#include <ctime>
#include <iostream>
using namespace std;

bool testDonkey();
bool testTail();

int main2() {
    srand(time(NULL));
    if (testDonkey() == true) {
        cout << "Passed all Donkey test cases" << endl;
    }
    if (testTail() == true) {
        cout << "Passed all Tail test cases" << endl;
    }
    return 0;
}

bool testDonkey() {
    bool passed = true;
    Donkey d;
    if (d.getX()<0) {
        passed = false;
        cout << "FAILED default constructor case" << endl;
    }
    return passed;
}

bool testTail() {
    bool passed = true;
    Tail t;
    if (t.getX()<0) {
        passed = false;
        cout << "FAILED default constructor case" << endl;
    }
    return passed;
}