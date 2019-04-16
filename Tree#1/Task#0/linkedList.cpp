#include <iostream>
#include "linkedList.h"

using namespace std;

int main() {

    // Task 0: traverse a linked list
    cout << "TASK 0: Traverse Linked List" << endl;
    node *ll = new node(1, new node(2, new node(3, NULL)));
    traverse(ll);


    return 0;
}

/*
 * traverse - Task 0: traverse a linked list from beginning to end
 * The function is defensive for NULL parameters
 *
 * NOTE: This function is recursive
 *
 * start:  Pointer to the starting node.
 *
 * Returns: Nothing
 */
void traverse(node *start) {
    if (start == NULL) return ;

    cout << start->value << endl;
    traverse(start->next);
}