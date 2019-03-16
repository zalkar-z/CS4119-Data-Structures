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
#include <typeinfo>

using namespace std;

struct node {
    int value;
    node *next;
    node(int v, node *n) {
        value = v;
        next = n;
    }
};

void listPrint(node *start);
void addToEnd(node *currentPoint, node *newNode);
void addToBeginning(node *startingPoint, node *newNode);
void addAtIndex(node *startingPoint, int index, node *nodeToAdd);
int getListSize(node *start);

int main() {

    node *start = new node(1, NULL); // creates an initial point of the list

     addToEnd(start, new node(2, NULL));
     addToEnd(start, new node(3, NULL));
     addToEnd(start, new node(4, NULL));
     addToEnd(start, new node(5, NULL));

     node *newStart = new node(0, NULL);
     addToBeginning(start, newStart);

     start = newStart;


     listPrint(start);

     cout << getListSize(start) << endl;


    return 0;
}

// prints a linked list with an appropriate index information
void listPrint(node *startPoint) {
    int index = 0;

    while(true) {
        cout << "List item #" << index << " = " << startPoint->value << endl;
        if (startPoint->next == NULL) break; // checks the variable for NULL before assigning it to the current variable
        startPoint = startPoint->next;
        index++;
    }
}


// return the size of a linked list
int getListSize(node *startPoint) {
    int size = 0;

    while(true) {
        size++;
        if (startPoint->next == NULL) break;
        startPoint = startPoint->next;
    }

    return size;
}


// adds newNode to the end of current linked list
void addToEnd(node *currentPoint, node *newNode) {

    if (currentPoint == NULL) {
        currentPoint = new node(newNode->value, NULL);
    } else {
        while(true) {
            if (currentPoint->next == NULL) {
                currentPoint->next = newNode;
                break;
            }
            currentPoint = currentPoint->next;
        }
    }
}


// adds newNode to the beginning of the linked list [before startingPoint]
void addToBeginning(node *startingPoint, node *newNode) {
    newNode->next = startingPoint;
}


// adds newNode to a particular index in an existing linked list
void addAtIndex(node *startingPoint, int index, node *nodeToAdd) {
    int listSize = getListSize(startingPoint);

    // if the index is out of list's range return "-1" as an error
    if (index < 0 || index >= listSize) return;

    int currentIndex = 0;

    while(true) {
        if (currentIndex == index) {
            nodeToAdd->next = startingPoint->next;
            startingPoint->next = nodeToAdd;
        }
        if (startingPoint->next == NULL) break;

        startingPoint = startingPoint->next;
        currentIndex++;
    }


}