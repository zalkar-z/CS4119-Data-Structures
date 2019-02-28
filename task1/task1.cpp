/*
* task1.cpp - While loops - basic C++ program
* Author: Zalkar Ziiaidin uulu (zalkar@bennington.edu)
* Date: 2/26/2019
* (this is an example of a multi-line comment)
*
* TO COMPILE:  g++ task1.cpp -o task1
* then, TO RUN:  ./task1
*/

#include <iostream>

using namespace std;

void printHelloNTimes(int);

int main() {

    printHelloNTimes(2);
    cout << endl << endl;

    printHelloNTimes(3);
    cout << endl << endl;

    printHelloNTimes(6);
}


void printHelloNTimes(int numTimes) {

    int counter = 0;
    while (counter < numTimes) {
        cout << "Hello" << endl;
        counter++; // counter = counter + 1
    }
}
