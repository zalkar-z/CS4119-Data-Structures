/*
 * queue.cpp - linked-list backed queue
 * Author: Andrew Cencini (acencini@bennington.edu)
 * Date: 4/8/2019
 *
 * NOTE: This code was modified by Zalkar Ziiaidin uulu
 *       on 4/23/2019 for Lab#4-Task#2
 *
 */

#include <iostream>

using namespace std;

/*
 * our queue class implementation
 */
template <class Item>
class Queue {
private:
    struct node {
        Item item;
        node* next;
        node(Item x) {
            item = x;
            next = NULL;
        }
    };

    node *head, *tail;	// we track the front and rear of the FIFO queue
    int length = 0;

public:
    // constructor - sets up an empty queue
    Queue() {
        head = NULL;
        tail = NULL;
    }

    // is the queue empty?  return 1 (TRUE) otherwise 0 (FALSE)
    int empty() {
        return head == NULL;
    }

    // enqueue an item into the queue at the back of the line
    void put(Item x) {
        node *t = tail;
        tail = new node(x);
        // if we have an empty queue head is null
        if (head == NULL) {
            head = tail;
        }
            // otherwise have the previous tail (t) point to the new tail
        else {
            t->next = tail;
        }
        // increase the length counter
        length++;
    }

    // retrieve an item from the front of the queue - note this function could cause
    // problems with an empty queue............
    Item get() {

        if (!head) return NULL;

        // if there is at least one item, we can decrease the length
        length--;

        Item v = head->item;
        node *t = head->next;
        delete head;
        head = t;
        return v;
    }

    int getLength() {
        return length;
    }


};

int main() {
    // my goodness, it's a brand new queue!
    Queue<int> *q = new Queue<int>();

    cout << q->getLength() << endl;

    // let's enqueue some stuff into our queue
    for (int i = 0; i<10; i++) {
        q->put(i);
        cout << "Length = " << q->getLength() << endl;
    }

    // and then let's dequeue things from our queue
    while (!q->empty()) {
        cout << "Current length is - " << q->getLength() << ". Deleting - " << q->get() << endl;
    }
}