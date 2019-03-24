/*
* linkedList.cpp - Lab3 - Singularly linked lists
* Author: Zalkar Ziiaidin uulu (zalkar@bennington.edu)
* Date: 3/5/2019
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
void addToEnd(node **, node *);
void addToBeginning(node **, node *);
void addAtIndex(node *, node *, int);
int removeByValue(node **, int);
void removeAtStart(node **);
void removeAtEnd(node *);
node* findByValue(node *, int);
int listSize(node *);


int main() {

    // Task 0: traverse a linked list
    cout << "TASK 0: Traverse Linked List" << endl;
    node *ll = new node(1, new node(3, new node(2, NULL)));
    printList(ll);

    // Task 1: Add a node to the end of a linked list
    cout << "TASK 1: Add to End of Linked List" << endl;
    node *newNode = new node(5, NULL);
    addToEnd(&ll, newNode);
    printList(ll);

    // Task 2: Add a node to the beginning of a linked list
    cout << "TASK 2: Add to Start of Linked List Using **" << endl;
    newNode = new node(1, NULL);
    addToBeginning(&ll, newNode);   // here we are passing in the address of our starting point, as we will change it
    printList(ll);                  // we see here that the new first element in the list is newNode, followed by ll

    // Task 3: Add a node after a given 0-based index
    cout << "TASK 3 : Add at a given index" << endl;
    newNode = new node(4, NULL);
    addAtIndex(ll, newNode, 0);      // add after the first index
    newNode = new node(200, NULL);
    addAtIndex(ll, newNode, 100);    // index is out of range
    printList(ll);

    // Task 4: Remove by value
    cout << "TASK 4 : Remove by a given value" << endl;
    int numRemoved = removeByValue(&ll, 2);
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
    cout << "TASK 7 : Find node by value" << endl;
    node* node2 = findByValue(ll, 2);        // should be a valid node
    node* nodeX = findByValue(ll, 100);      // should be NULL
    cout << "Found node with value " << node2->value << " at " << node2 << endl;
    cout << "Did not find node with value 100 " << " at " << nodeX << endl;
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

    while(current != NULL) {
        cout << "List item #" << index << " = " << current->value << endl;
        current = current->next;
        index++;
    }
}

/*
 * addToEnd - Task 1: add a node to the end of an existing linked list
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

        while (current->next != NULL) {
            current = current->next;
        }
        // at this point, we are at the end of the list, so we append a newNode
        current->next = newNode;
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
    // handles infinite cyclic cases
    if (newNode == *start) return;

    newNode->next = *start;
    *start = newNode;
}

/*
 * addAtIndex - Task 3: add a node after an arbitrary index.  Note: indexes start at 0.
 *
 * start:  Pointer to the starting node.
 * nextNode:  Pointer to the node to add.
 * index: The 0-based index at which to add the node.  If > total number of items in the list, we return error.
 *
 * Returns: Nothing
 */
void addAtIndex(node *start, node *newNode, int index) {
    int i = 0;
    node* curr = start;
    int size = listSize(curr);

    // returns nothing if newNode is NULL
    if (newNode == NULL) return;

    // stops function is the index is out of range
    if (index < 0 || index >= size) return;

    // work our way to either the desired index or the end of the list
    while (i < index && curr->next != NULL) {
        i++;
        curr = curr->next;
    }

    // either way we are either at the index we wish to insert at, or the end of the list
    newNode->next = curr->next;     // set the newNode to point to the next pointer from where we stopped
    curr->next = newNode;           // now set the next pointer on the node we stopped at to our newNode
}

/*
 * removeByValue - Task 4: removes all nodes with the given value, including the first node
 *
 * start:  Pointer to the starting node.
 * value: If a node has this value, it is to be removed from the list.
 *
 * Returns: Number of nodes removed.
 */
int removeByValue(node **start, int value) {

    int numRemoved = 0;

    node *curr = *start;

    while (curr->value == value && curr != NULL) {
        node *next = curr->next;
        delete curr;
        curr = next;
        numRemoved++;
    }

    if (curr == NULL) return numRemoved;

    *start = curr;
    node *tempStart = curr;
    curr = curr->next;

    while (curr != NULL) {
        if (curr->value == value) {
            numRemoved++;
            node *next = curr->next;
            delete curr;
            curr = next;
        } else {
            node *nextNode = curr->next;
            tempStart->next = curr;
            tempStart = tempStart->next;
            curr = nextNode;
        }
    }
    tempStart->next = curr;

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
    if (start != NULL && *start != NULL) {
        *start = (*start)->next;
    }
}

/*
 * removeAtEnd - Task 6: removes the node at the end of the list
 *
 * start:  Pointer to the starting node.
 *
 * Returns: Nothing.
 */
void removeAtEnd(node *start) {
    node* curr = start;
    node* prev = start;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;      // remove the last element by unhooking it from the list.  could use delete to free the mem
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
    while (start != NULL && start->value != value) {
        start = start->next;
    }
    return start;           // either has the first instance of the value, or not found
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

    while(current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

