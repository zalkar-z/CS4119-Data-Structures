/*
* task0.cpp - Hello World - basic C++ program
* Author: Andrew Cencini (acencini@bennington.edu)
* Date: 2/19/2019
* (this is an example of a multi-line comment)
*
* TO COMPILE:  g++ task0.cpp -o task0
* then, TO RUN:  ./task0
*/

#include <iostream>    // used to do input/output stream operations

using namespace std;   // our I/O operations live in the std namespace

// Function declaration for printIntHellos
// Prints "hello" once per line for the number of times specified.
// Only parameter is an int, and this function does not return anything
// (thus the "void" return type).
void printIntHellos(int);

int main() {
    cout << "Hello world!" << endl;
    printIntHellos(10);
    return 0;  // program completed successfully (can be omitted)
}

void printIntHellos(int numTimes) {
    // example of a for loop - we initialize our counter (i)
    // to zero, and as long as i is less than numTimes (the parameter passed
    // in to this function), we output "hello!" to the console, incrementing
    // i (via i++) after each iteration.
    for (int i=0; i<numTimes; i++) {
        cout << "hello!" << endl;
    }
}
