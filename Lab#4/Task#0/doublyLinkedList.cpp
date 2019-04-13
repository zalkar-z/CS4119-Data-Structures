/*
* doublyLinkedList.cpp - Lab4 - Class implementation of doubly linked list
* Author: Zak Ziiaidin uulu (zalkar@bennington.edu)
* Date: 4/12/2019
*/

#include <iostream>

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

    /*
     * traverse - traverse the linked list from beginning to end.
     * The function is defensive for empty linked lists
     *
     * Returns: Nothing
     */
    void traverse() {
        node *current = head;

        while(current != NULL) {
            cout << current->value  << endl;
            current = current->next;
        }
    }

    /*
     * traverseReversed - traverse the linked list from end to beginning.
     * The function is defensive for empty linked lists
     *
     * Returns: Nothing
     */
    void traverseReversed() {
        node *current = head;

        while(current->next != NULL) {
            current = current->next;
        }

        while(current != NULL) {
            cout << current->value  << endl;
            current = current->prev;
        }
    }

    /*
     * addAtBeginning - add a node to the start of an existing linked list
     * The function is defensive for empty linked lists
     *
     * Value: the value of a new node being add to the beginning
     *
     * Returns: Nothing
     */
    void addAtBeginning(Item value) {
        head = new node(value, NULL, head);
        if (head->next) head->next->prev = head;
    }

    /*
     * addAtBeginning - add a node to the start of an existing linked list
     * The function is defensive for empty linked lists
     *
     * Value: the value of a new node being add to the beginning
     *
     * Returns: Nothing
     */
    void addAtEnd(Item value) {
        if (!head) {
            head = new node(value, NULL, NULL);
        } else {
            node *current = head;

            while (current->next != NULL) {
                current = current->next;
            }
            node *newEnd = new node(value, current, NULL);
            current->next = newEnd;
        }
    }
};

int main() {

    // so let's create out first doubly linked list
    DoublyLinkedList<int> *dll = new DoublyLinkedList<int>();

    // let's add a new node at the beginning
    dll->addAtBeginning(1);

    // let's add a new node at the end
    dll->addAtEnd(2);





    // let's see what we have in our doubly linked list
    dll->traverse();

    cout << "--------------" << endl;

    // let's see what we have in out doubly linked list if we reverse everything
    dll->traverseReversed();




    return 0;
}