/*
* linkedList.cpp - Lab2 (task 1-7) - basic C++ program
* Author: Zalkar Ziiaidin uulu (zalkar@bennington.edu)
* Date: 3/5/2019
* (this is an example of a multi-line comment)
*
* TO COMPILE:  g++ linkedList.cpp -o linkedList
* then, TO RUN:  ./linkedList
*/

#include <iostream>

using namespace std;

struct node {
    int value;
    node *next;
    node(int v, node *n) {
        value = v;
        next = n;
    }
};

void listGenerate(node *start);
void listPrint(node *start);
void addToEnd(node **startingPoint, node *newNode);

int main() {

    node *start = new node(1, NULL); // creates an initial point of the list

//    listGenerate(start); // generates a basic linked list
//    listPrint(start); // prints all items in a list

    node *test = NULL;
    addToEnd(&test, new node(939, NULL));

    cout << "YAY" << test->value << endl;




    return 0;
}

void listGenerate(node *start) { // generates a linked list [1, 2, 3, 4, 5] for a convenience of tasks in this Lab
    node *current = start;

    for (int c = 2; c <= 5; c++) {
        current->next = new node(c, NULL);
        current = current->next;
    }
}

void listPrint(node *start) {
    node *current = start;
    int index = 0;

    while(true) {
        cout << "List item #" << index << " = " << current->value << endl;
        if (current->next == NULL) break; // checks the variable for NULL before assigning it to the current variable
        current = current->next;
        index++;
    }
}

// use pointers to pointers
void addToEnd(node **startingPoint, node *newNode) {
    node **current = startingPoint;

    if (*current == NULL) {
        *current = new node(newNode->value, NULL);
    } else {
        while(true) {
            if (*current->next == NULL) {
                *current->next = newNode;
                break;
            }
            current = current->next;
        }
    }
}