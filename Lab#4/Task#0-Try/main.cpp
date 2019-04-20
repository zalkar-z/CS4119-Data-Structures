#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main()
{

    DoublyLinkedList<int> *dll = new DoublyLinkedList<int>();

    //dll->addAtBeginning(5);
    dll->traverse();


    return 0;
}