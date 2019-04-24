//
// Created by zalkar on 2019-04-23.
//

#ifndef TASK_1_STACK_H
#define TASK_1_STACK_H

using namespace std;

/*
 *
 * our stack class implementation from
 * Data Structure in C++ with Andrew Cencini
 *
 */
template <class Item>
class Stack {
private:
    struct node {
        Item item;
        node* next;
        node(Item x, node* t) {
            item = x;
            next = t;
        }
    };

    node *head;

public:
    // constructor (called on new)
    Stack() {
        head = NULL;	// we have nothing in our new stack, so set head to null
    }

    // destructor (called on delete)
    ~Stack() {
        cout << "Calling destructor" << endl;
    }

    // is the list empty?  if empty, return 1 (TRUE), else 0 (FALSE)
    int empty() const {
        return head == NULL;	// if head is NULL the list is empty
    }

    // push an item to the top of the stack
    // x is the item to push onto the stack
    void push(Item x) {
        head = new node(x, head);	// we create a new node in our linked list
        // and make it the head, and the former head that node's
        // next pointer
    }

    // pop an item off of the stack - the item is returned from this function
    Item pop() {
        Item v = head->item;	// this is the item to return
        node *t = head->next;	// get pointer to the next item in the stack
        delete head;		// delete the existing head node
        head = t;		// set the new head to the next item on the stack
        return v;		// returnt the item belonging to the node we removed
    }
};


#endif //TASK_1_STACK_H
