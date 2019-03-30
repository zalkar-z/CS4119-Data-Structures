//
// Created by zalkar on 2019-03-30.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

using namespace std;

struct node {
    int value;
    node *prev;
    node *next;
    node(int v, node *p, node *n) {
        value = v;
        prev = p;
        next = n;
    }
};

void printList(node *);
void printReversedList(node *);
void addToEnd(node **, node *);
void addToBeginning(node **, node *);
void addAtIndex(node *, node *, int);
int removeByValue(node **, int);
void removeAtStart(node **);
void removeAtEnd(node *);
node* findByValue(node *, int);
int listSize(node *);

#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
