//
// Created by zalkar on 2019-04-13.
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

    /*
     * traverse - traverse the linked list from beginning to end.
     * The function is defensive for empty linked lists
     *
     * Returns: Nothing
     */
    void traverse() {
        node *current = head;

        while(current != NULL) {
            cout << current->value << endl;
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

    /*
     * findByValue - find first instance of node with given value
     *
     * Value:  the value to look for.
     *
     * Returns: Pointer to the first node with that value.
     */
    node* findByValue(Item value) {
        node *current = head;

        while(current != NULL && current->value != value) {
            current = current->next;
        }
        return current;
    }

    /*
     * removeAtBeginning - removes the node from the start of the list
     *
     * Returns: Nothing.
     */
    void removeAtBeginning() {
        node *second = NULL;
        if (head) second = head->next;
        if (second) second->prev = NULL;
        delete head;
        head = second;
    }

    /*
     * removeAtEnd - removes the node from the end of the list
     *
     * Returns: Nothing.
     */
    void removeAtEnd() {
        // if head is NULL stop here
        if (!head) return ;

        // if head is the only node in the list
        if (!head->next) {
            head = NULL;
            return ;
        }

        node* current = head;
        node* prev = head;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        delete prev->next;
        prev->next = NULL;
    }

    /*
     * removeByValue - removes all nodes with the given value, including the first node
     *
     * value: If a node has this value, it is to be removed from the list.
     *
     * Returns: Number of nodes removed.
     *
     */
    int removeByValue(Item value) {
        int numRemoved = 0;

        node *current = head;

        // removes all appearances of provided value in the beginning of list
        while (current != NULL && current->value == value) {
            node *next = current->next;
            delete current;
            current = next;
            numRemoved++;
        }

        head = current;
        // finishes the function if the list is already empty
        if (current == NULL) return numRemoved;

        current->prev = NULL;

        node *tempStart = current;
        current = current->next;

        while (current != NULL) {
            if (current->value == value) {
                numRemoved++;
                node *next = current->next;
                delete current;
                current = next;
            } else {
                node *nextNode = current->next;
                tempStart->next = current;
                current->prev = tempStart;
                tempStart = tempStart->next;
                current = nextNode;
            }
        }
        tempStart->next = current;

        return numRemoved;
    }

    /*
     * getValueAtIndex - returns a value at a given index
     *
     * index: index of the value we're looking for.
     *
     * Returns: an item at a given index.
     *
     */
    Item getValueAtIndex(int index) {
        node *current = head;
        int currentIndex = 0;

        while(currentIndex < index && current != NULL) {
            current = current->next;
            currentIndex++;
        }

        if (!current) return -1;
        return current->value;
    }
};


#endif //TASK_0_DOUBLYLINKEDLIST_H