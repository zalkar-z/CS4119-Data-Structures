//
// Created by User on 4/16/2019.
//

#ifndef TASK_0_LINKEDLIST_H
#define TASK_0_LINKEDLIST_H

using namespace std;

struct node {
    int value;
    node *next;
    node(int v, node *n) {
        value = v;
        next = n;
    }
};

void traverse(node *);

#endif //TASK_0_LINKEDLIST_H
