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

void addToEnd(node* startingPoint, node* newNode) {
    if (startingPoint->value == NULL) {
        startingPoint->value = newNode->value;
    } else {
        startingPoint->next = newNode;
    }
}

int main() {

    node* start = new node(1, NULL);

    addToEnd(start, new node(5, NULL));


    return 0;
}