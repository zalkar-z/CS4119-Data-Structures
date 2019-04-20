//
// Created by zalkar on 2019-04-20.
//

#ifndef TASK_0_DOUBLYLINKEDLIST_H
#define TASK_0_DOUBLYLINKEDLIST_H

using namespace std;

/*
 * Our class implementation of doubly linked list
 */
template <class Item>
class DoublyLinkedList {
private:
    struct node {
        Item value;
        node *prev;
        node *next;
        node(Item x, node *p, node *n) {
            value = x;
            prev = p;
            next = n;
        }
    };

    node *head;

public:
    // constructor (called on "new")
    DoublyLinkedList() {
        head = NULL; // we have nothing in our doubly linked list, so it is empty (NULL)
    }

    // destructor (called on "delete")
    ~DoublyLinkedList() {
        cout << "Calling destructor" << endl;
    }
    void traverse();
//    void traverseReversed();
    void addAtBeginning(Item value);
//    void addAtEnd(Item value);
//    node* findByValue(Item value);
//    void removeAtBeginning();
//    void removeAtEnd();
//    int removeByValue(Item value);
//    Item getValueAtIndex(int index);
};


#endif //TASK_0_DOUBLYLINKEDLIST_H
