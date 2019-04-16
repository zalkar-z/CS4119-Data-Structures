/*
* main.cpp - Tree#1 - Task#1-3
* Author: Zak Ziiaidin uulu (zalkar@bennington.edu)
* Date: 4/16/2019
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int factorial(int);

int main() {

    cout << factorial(4) << endl;

    return 0;
}

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}