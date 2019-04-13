/*
* doublyLinkedList.cpp - Lab4 - Class implementation of doubly linked list
* Author: Zak Ziiaidin uulu (zalkar@bennington.edu)
* Date: 4/12/2019
*/

#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main() {

    // so let's create out first doubly linked list
    DoublyLinkedList<int> *dll = new DoublyLinkedList<int>();

    // let's add some new nodes at the beginning
    dll->addAtBeginning(1);
    dll->addAtBeginning(1);
    dll->addAtBeginning(5);

    // let's add some new nodes at the end
    dll->addAtEnd(2);
    dll->addAtEnd(2);
    dll->addAtEnd(2);
    dll->addAtEnd(6);
    dll->addAtEnd(3);
    dll->addAtEnd(3);

    // let's get an address of the first instance of 1 in our linked list
    cout << dll->findByValue(1) << endl;

    // let's remove the first node in our list
    dll->removeAtBeginning();

    // let's remove the last node in our list
    dll->removeAtEnd();

    // let's remove all appearances of 2 in our linked list
    cout << dll->removeByValue(2) << endl;

    // let's find a value of an index #3
    cout << dll->getValueAtIndex(3) << endl;


    // let's see what we have in our doubly linked list
    dll->traverse();

    cout << "--------------" << endl;

    // let's see what we have in out doubly linked list if we reverse everything
    dll->traverseReversed();


    // bye dll!
    delete dll;




    return 0;
}