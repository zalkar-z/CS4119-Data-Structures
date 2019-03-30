/*
* circularLinkedList.cpp - Lab3 - Circular linked lists
* Author: Zak Ziiaidin uulu (zalkar@bennington.edu)
* Date: 3/5/2019
*/

#include <iostream>
#include "circularLinkedList.h"

using namespace std;


int main() {

    // Task 0: traverse a linked list
    cout << "TASK 0: Traverse Linked List" << endl;

    node *first = new node(1, NULL);
    node *second = new node(2, NULL);
    node *third = new node(3, NULL);

    first->next = second;
    second->next = third;
    third->next = first;

    // pointer to the end of list
    node *ll = third;

    printList(ll);

    // Task 1: Add a node to the end of a linked list
    cout << "TASK 1: Add 4 to the end of Linked List" << endl;
    node *newNode = new node(4, NULL);
    addToEnd(&ll, newNode);
    printList(ll);

    // Task 2: Add a node to the beginning of a linked list
    cout << "TASK 2: Add -1 to the start of Linked List Using **" << endl;
    newNode = new node(-1, NULL);
    addToBeginning(&ll, newNode);
    printList(ll);

    // Task 3: Add a node after a given 0-based index
    cout << "TASK 3 : Add 0 after index #5" << endl;
    newNode = new node(0, NULL);
    addAtIndex(ll, newNode, 5);
    printList(ll);

    // Task 4: Remove by value
    cout << "TASK 4 : Remove all appearances of 4" << endl;
    int numRemoved = removeByValue(&ll, 4);
    cout << numRemoved << endl;
    printList(ll);

    // Task 5 (alternate using pointers to pointers): Remove at start
    cout << "TASK 5 (alternate) : Remove item at start of list using pointers to pointers" << endl;
    removeAtStart(&ll);
    printList(ll);

    // Task 6: Remove at end
    cout << "TASK 6 : Remove item at end of list" << endl;
    removeAtEnd(ll);
    printList(ll);

    // Task 7: Find by value
    cout << "TASK 7 : Find the first position of 1 and return the address" << endl;
    node* node1 = findByValue(ll, 1);
    cout << node1 << endl;
    printList(ll);

    return 0;
}

/*
 * printList - Task 0: traverse a linked list from beginning to end printing values and indexes as we go.
 * The function is defensive for NULL parameters
 *
 * start:  Pointer to the starting node.
 *
 * Returns: Nothing
 */
void printList(node *start) {
    node *current = start;
    int index = 0;

    while(true) {
        cout << "List item #" << index << " = " << current->value << endl;
        current = current->next;
        if (current == start) break;
        index++;
    }
}

/*
 * addToEnd - Task 1: add a node to the end of an existing linked list (uses pointers to pointer)
 * The function is defensive for NULL parameters
 *
 * start:  Pointer to pointer to the starting node.
 * newNode:  Pointer to the node to add.
 *
 * Returns: Nothing
 */
void addToEnd(node **start, node *newNode) {
    // stops function if newNode is NULL
    if (newNode == NULL) return;


    // checks if the start is NULL
    if (*start == NULL) {
        *start = newNode;
    } else {
        node *current = *start;
        newNode->next = current->next;
        current->next = newNode;
        *start = newNode;
    }
}

/*
 * addToBeginning - Task 2: add a node to the start of an existing linked list (uses pointers to pointers)
 * The function is defensive for NULL parameters and cyclic inputs
 *
 * start:  Pointer to pointer to the starting node.
 * newNode:  Pointer to the node to add.
 *
 * Returns: Nothing
 */
void addToBeginning(node **start, node *newNode) {
    // returns nothing if newNode is NULL
    if (newNode == NULL) return;

    if (*start == NULL) {
        *start = newNode;
        return;
    }

    newNode->next = (*start)->next;
    (*start)->next = newNode;
}

/*
 * addAtIndex - Task 3: add a node after an arbitrary index.
 * Note: indexes are counted regarding the starting point passed
 *
 * start:  Pointer to the starting node.
 * nextNode:  Pointer to the node to add.
 * index: Position for nextNode to be added. Note: Indexes bigger than list size can be handled, since it is a circular list.
 *
 * Returns: Nothing
 */
void addAtIndex(node *start, node *newNode, int index) {
    int i = 0;
    node* current = start;
    int size = listSize(current);

    // returns nothing if newNode is NULL
    if (newNode == NULL) return;

    // stops function if the index is negative
    if (index < 0) return;

    // handling indexes bigger than list's size
    index = index % size;

    while(i < index) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

/*
 * removeByValue - Task 4: removes all nodes with the given value, including the first node
 *                 Note: Fully circular link list adapted function
 *
 * start:  Pointer to the starting node.
 * value: If a node has this value, it is to be removed from the list.
 *
 * Returns: Number of nodes removed.
 * 
 * Comment: Original code provided in class's website doesn't handle several removals in a row. 
 *          Issue is fixed here by utilizing a different algorithm. 
 */
int removeByValue(node **start, int value) {

    int numRemoved = 0;
    int numChecked = 0;
    int size = listSize(*start);

    node *current = *start;

    // removes all apperances of provided value in the beginning of list regarding the starting point
    while (current->value == value && numChecked < size) {
        node *next = current->next;
        delete current;
        current = next;

        numRemoved++;
        numChecked++;
    }

    // finishes the function if all nodes were deleted
    if (numChecked == size)  {
        *start = NULL;
        return numRemoved;
    }

    *start = current;
    node *tempStart = current;
    numChecked++;
    current = current->next;

    while (numChecked < size) {
        numChecked++;
        if (current->value == value) {
            numRemoved++;
            node *next = current->next;
            delete current;
            current = next;
        } else {
            node *nextNode = current->next;
            tempStart->next = current;
            tempStart = tempStart->next;
            current = nextNode;
        }
    }
    tempStart->next = *start;

    return numRemoved;
}

/*
 * removeAtStart - Task 5: removes the node from the start of the list by using pointers to pointers
 *
 * start:  Pointer to the starting node.
 *
 * Returns: Nothing.
 */
void removeAtStart(node **start) {

    // NULL handling
    if (start == NULL || *start == NULL) return;

    node *current = *start;
    node *prev = *start;

    while (true) {
        prev = prev->next;
        if (prev->next == current) break;
    }

    prev->next = current->next;
    *start = prev->next;
    delete current;
}

/*
 * removeAtEnd - Task 6: removes the node at the end of the list
 *
 * start:  Pointer to the starting node.
 *
 * Returns: Nothing.
 */
void removeAtEnd(node *start) {
    node* current = start;
    node* prev = start;
    while (current->next != start) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    delete current;
}

/*
 * findByValue - Task 7: find first instance of node with given value
 *
 * start:  Pointer to the starting node.
 * value:  The value to look for.
 *
 * Returns: Pointer to the first node with that value.
 */
node* findByValue(node *start, int value) {
    int size = listSize(start);
    int numChecked = 0;

    while (numChecked < size && start->value != value) {
        start = start->next;
        numChecked++;
    }
    if (start->value != value) return NULL;
    return start;
}


/*
 * listSize - defines a size of a linked list
 * The function is defensive for NULL parameters and cyclic inputs
 *
 * start:  Pointer to the starting node.
 *
 * Returns: size of a list
 */
int listSize(node *start) {
    node *current = start;
    int size = 0;

    while(true) {
        size++;
        current = current->next;
        if (current == start) break;
    }
    return size;
}

