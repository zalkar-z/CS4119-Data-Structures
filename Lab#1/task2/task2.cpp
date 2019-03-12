/*
* task2.cpp - Conditionals and Returns - basic C++ program
* Author: Zalkar Ziiaidin uulu (zalkar@bennington.edu)
* Date: 2/26/2019
* (this is an example of a multi-line comment)
*
* TO COMPILE:  g++ task2.cpp -o task2
* then, TO RUN:  ./task2
*/

#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

int getRandomInt();
int evenOddOrZero(int);

int main() {

    srand(time(NULL));

    for (int c = 0; c < 10; c++) {

        int current_number = getRandomInt();
        int result = evenOddOrZero(current_number);
        string result_text;

        if (result == 1) {
            result_text = "even";
        } else if (result == 0) {
            result_text = "odd";
        } else {
            result_text = "zero";
        }

        cout << current_number << " is " << result_text << endl;
    }

    return 0;
}


int getRandomInt() {
    return rand() % 100;
}

int evenOddOrZero(int number) {
    if (number % 2 == 0) {
        return 1;
    } else if (number % 2 == 1) {
        return 0;
    } else {
        return -1;
    }
}