/*
* task4.cpp - Structs - basic C++ program
* Author: Zalkar Ziiaidin uulu (zalkar@bennington.edu)
* Date: 2/28/2019
* (this is an example of a multi-line comment)
*
* TO COMPILE:  g++ task4.cpp -o task4
* then, TO RUN:  ./task4
*/

#include <iostream>

using namespace std;

struct person {
    string name = "";
    int age = 0;
};

person getPerson();
void changePerson(person);


int main() {

    person resultPerson = getPerson();
    cout << resultPerson.name << " " << resultPerson.age << endl;

    changePerson(resultPerson);
    cout << resultPerson.name << " " << resultPerson.age << endl;

    return 0;
}

person getPerson() {
    person newPerson;
    cout << "Enter new person's name: " << endl;
    cin >> newPerson.name;
    cout << "Enter new person's age: " << endl;
    cin >> newPerson.age;

    return newPerson;
}

void changePerson(person currentPerson) {
    currentPerson.name = "Andrew Cencini";
    currentPerson.age = 100;
    cout << currentPerson.name << " " << currentPerson.age << endl;
}