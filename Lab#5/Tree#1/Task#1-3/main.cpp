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
void readFile(string);

int main() {

    cout << factorial(4) << endl;

    string filePath = "C:\\Users\\User\\Desktop\\Bennington College\\term2\\Data_Structures_C++\\Tree#1\\Task#1-3\\test.txt";
    readFile(filePath);

    return 0;
}

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

void readFile(string fileName) {
    ifstream myFile(fileName);
    string word;

    while(myFile>>word) {
        // the whole word
        cout << word << endl;
        // the first char of string
        cout << word.at(0) << endl;
    }
    myFile.close();
}