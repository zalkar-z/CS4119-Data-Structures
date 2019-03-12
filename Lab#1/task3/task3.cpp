/*
* task3.cpp - User input & Switch statements - basic C++ program
* Author: Zalkar Ziiaidin uulu (zalkar@bennington.edu)
* Date: 2/28/2019
* (this is an example of a multi-line comment)
*
* TO COMPILE:  g++ task3.cpp -o task3
* then, TO RUN:  ./task3
*/

#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

int getInt();
string getString();
int getRandomInt();
void whatNumberIsIt(int);

int main() {

    srand(time(NULL));


    for (int c = 0; c < 20; c++) {
        whatNumberIsIt(getRandomInt());
    }

    whatNumberIsIt(10);

    return 0;
}

int getInt() {

    int numIn;
    cout << "Pleae enter an integer: ";
    cin >> numIn;
    return numIn;
}

string getString() {

    string stringIn;
    cout << "Please enter a string: ";
    cin >> stringIn;
    return stringIn;
}

int getRandomInt() {
    return rand() % 6;
}

void whatNumberIsIt(int number) {

    switch (number) {
        case 0: {
            cout << "ZERO" << endl;
            break;
        }
        case 1: {
            cout << "ONE" << endl;
            break;
        }
        case 2: {
            cout << "TWO" << endl;
            break;
        }
        case 3: {
            cout << "THREE" << endl;
            break;
        }
        case 4: {
            cout << "FOUR" << endl;
            break;
        }
        case 5: {
            cout << "FIVE" << endl;
            break;
        }
        default: {
            cout << "OUT OF RANGE" << endl;
            break;
        }
    }
}