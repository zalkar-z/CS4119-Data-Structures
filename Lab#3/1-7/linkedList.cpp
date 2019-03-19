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

void printList(node *);
int getListSize(node *);
void addToEnd(node **, node *);
void addToBeginning(node **, node *);
void addAtIndex(node *, node *, int);


int main() {

    node *start = new node(1, new node(2, new node(3, NULL))); // creates an initial point of the list

    addToEnd(&start, new node(4, NULL));
    addToBeginning(&start, new node(0, NULL));

    printList(start);
    cout << getListSize(start) << endl;

    return 0;
}

// prints the provided linked list with indexes
// defensive for NULL parameter
void printList(node *start) {
    node *current = start;
    int index = 0;

    while(current != NULL) {
        cout << "List item #" << index << " = " << current->value << endl;
        current = current->next;
        index++;
    }
}

// returns the size of provided linked list
// defensive for NULL parameter
int getListSize(node *start) {
    node *current = start;
    int size = 0;

    while(current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

// adds a provided node to the end of the provided list
// defensive for both parameters in case of NULL
void addToEnd(node **start, node *newNode) {
    // returns nothing if newNode is NULL
    if (newNode == NULL) return;

    // checks if the start is NULL
    if (*start == NULL) {
        *start = newNode;
    } else {
        node *current = *start;

        while (current->next != NULL) {
            current = current->next;
        }
        // at this point, we are at the end of the list, so we append a newNode
        current->next = newNode;
    }
}

// adds a provided node to the beginning of the provided list
// defensive for both parameters in case of NULL
void addToBeginning(node **start, node *newNode) {
    // returns nothing if newNode is NULL
    if (newNode == NULL) return;

    newNode->next = *start;
    *start = newNode;
}


