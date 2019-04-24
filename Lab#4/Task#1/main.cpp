#include <iostream>
#include "stack.h"
#include "doublyLinkedList.h"

using namespace std;

int main() {

    // so let's create out first doubly linked list
    DoublyLinkedList<int> *dll = new DoublyLinkedList<int>();

    for (int i = 0; i < 100; i++) {
        dll->addAtEnd(i);
    }

    int traverse = dll->traverse();

    if (traverse == 1) {
        cout << "No errors were detected" << endl;
    } else if (traverse == 0) {
        cout << "Stack value and doubly linked list value don't match" << endl;
    } else {
        cout << "Stack length and doubly linked list length don't match" << endl;
    }


    return 0;
}