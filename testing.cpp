#include "Donkey.h"
#include "Tail.h"
#include <iostream>
using namespace std;

//declaring test functions
bool testDonkey();
bool testTail();

//main program to call test functions and print results
int main2() {
    if (testDonkey() == true) {
        cout << "Passed all Donkey test cases" << endl;
    }
    if (testTail() == true) {
        cout << "Passed all Tail test cases" << endl;
    }
    return 0;
}

//Donkey test function, tests constructors and move function
bool testDonkey() {
    bool passed = true;
    Donkey d;
    //default coordinates are (100,100)
    if (d.getX()!= 100 || d.getY()!=100) {
        passed = false;
        cout << "FAILED default constructor case" << endl;
    }
    Donkey d2(3,225,225);
    if (d2.getX()!= 225 || d2.getY()!=225) {
        passed = false;
        cout << "FAILED constructor case" << endl;
    }
    //new coordinates should be the ones passed into the function
    d.move(150,150);
    if (d.getX()!= 150 || d.getY()!=150) {
        passed = false;
        cout << "FAILED donkey move case" << endl;
    }
    return passed;
}

//Tail test function, tests constructors and move function
bool testTail() {
    bool passed = true;
    Tail t;
    //default coordinates are (100,100)
    if (t.getX()!= 100 || t.getY()!=100) {
        passed = false;
        cout << "FAILED default constructor case" << endl;
    }
    Tail t2(3,225,225);
    if (t2.getX()!= 225 || t2.getY()!=225) {
        passed = false;
        cout << "FAILED constructor case" << endl;
    }
    t.move(150,150);
    //new coordinates should be the ones passed into the function
    if (t.getX()!= 150 || t.getY()!=150) {
        passed = false;
        cout << "FAILED donkey move case" << endl;
    }
    return passed;
}

