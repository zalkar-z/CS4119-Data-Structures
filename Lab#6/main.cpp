/*
 * Simple Binary Search Tree Implementation
 * Author: Andrew Cencini (acencini@bennington.edu)
 * Date: 4/30/2019
 */

#include <iostream>

using namespace std;

template <class Item>
class BinarySearchTree {
private:
    /*
     * Represents a node in our tree.  It's a binary search tree so we only have left and right subtrees.
    */
    struct TreeNode {
        Item data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(Item d, TreeNode* l, TreeNode* r) {
            data = d;
            left = l;
            right = r;
        }
    };

    TreeNode* root;     // the root of our binary search tree

    void inOrder(TreeNode *root) {
        if (root == nullptr) return ;
        inOrder(root->left);
        cout << root->data << endl;
        inOrder(root->right);
    }

public:
    BinarySearchTree() {
        // our constructor is pretty lamecore
        root = nullptr;
    }

    /*
     * findOrInsert
     * Takes a value to find or insert into the BST
     * Returns: 0 if the value was not found and was instead inserted.
     *          1 if the value was found!
     */
    int findOrInsert(Item value) {
        TreeNode* pTn = new TreeNode(value, nullptr, nullptr);

        if (root == nullptr) {
            root = pTn;     // there's nothing in the tree so set the root to this new node
            return 0;      // return that the value was not found and instead inserted
        }

        TreeNode* curr = root;
        while (value != curr->data) {
            if (value < curr->data) {   // try left
                if (curr->left == nullptr) {
                    curr->left = pTn;   // there was nothing there so this is the place to insert our value!
                    return 0;       // return that the value was not found and instead inserted (left subtree, here)
                }
                curr = curr->left;
            }
            else {                      // try right
                if (curr->right == nullptr) {
                    curr->right = pTn;  // there was nothing there so this is the place to insert our value!
                    return 0;       // return that the value was not found and instead inserted (right subtree, here)
                }
                curr = curr->right;
            }
        }
        // otherwise value = curr->data so the value was found so we return 1 indicating value is present!
        return 1;
    }

    // calls a private function with the same name
    void inOrder() {
        inOrder(root);
    }

    /*
     * removeValue
     * Deletes a given value from the BST if found
     * Returns: 0 if the value was not found and consequently wasn't deleted
     *          1 if the value was found and successfully deleted
     */
    int removeValue(Item value) {
        if (root == nullptr) {
            return 0;      // return that the value was not found
        }
        // searching for a value here
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        while (value != curr->data) {
            if (value < curr->data) {   // try left
                if (curr->left == nullptr) {
                    return 0;       // return that the value was not found
                }
                parent = curr; // remembering parent
                curr = curr->left;
            }
            else {                      // try right
                if (curr->right == nullptr) {
                    return 0;       // return that the value was not found
                }
                parent = curr; // remembering parent
                curr = curr->right;
            }
        }
        // if the function didn't return yet, then we have the value in our BST, and it is curr->data

        // Case#1 - current is a leaf
        if (curr->left == nullptr && curr->right == nullptr) {
            // check if it has a parent and delete the link accordingly
            if (parent && parent->left == curr) parent->left = nullptr;
            if (parent && parent->right == curr) parent->right = nullptr;
            // delete the node with a given value
            delete curr;
            // return 1, which means that the value was found and successfully deleted
            return 1;
        }

        // Case#2 - current has only left subtree
        if (curr->right == nullptr) {
            // check the side its parent comes from and skip the curr in the link chain
            if (parent && parent->left == curr) parent->left = curr->left;
            if (parent && parent->right == curr) parent->right = curr->left;
            // delete the node with a given value
            delete curr;
            // return 1, which means that the value was found and successfully deleted
            return 1;
        }

        // Case#3 - current has only right subtree
        if (curr->left == nullptr) {
            // check the side its parent comes from and skip the curr in the link chain
            if (parent && parent->left == curr) parent->left = curr->right;
            if (parent && parent->right == curr) parent->right = curr->right;
            // delete the node with a given value
            delete curr;
            // return 1, which means that the value was found and successfully deleted
            return 1;
        }

        // Case#4 - current has both subtrees
        // first, we should find a value right next to curr in inOrder sequence
        TreeNode* next = curr->right;
        // We'll also need next's parent
        TreeNode* parentOfNext = curr->right;
        // now we go left as much as possible
        while (next->left) {
            parentOfNext = next; // save parent value
            next = next->left; // proceed
        } // by the end of this loop, we will have a value which stands right next to curr in inOrder sequence

        // since "next" has no left subtree, we will set up its left link to the left subtree of "curr"
        next->left = curr->left;

        // here we set "parentOfNext"'s left pointer to "next"'s right node
        parentOfNext->left = next->right;

        // finally, we will set the right link of "next" to point to the right subtree of "curr"
        next->right = curr->right;

        // we set "parent" to point to "next" instead of "curr", we should consider the direction from which parent comes from
        if (parent && parent->left == curr) parent->left = next;
        if (parent && parent->right == curr) parent->right = next;

        // finally, we delete "curr"
        delete curr;
    }
};


int main() {
    BinarySearchTree<char> *bst = new BinarySearchTree<char>();

    char inValue;

    cout << "Enter a character to find or insert into the tree, or '@' to stop and do an inOrder traversal: " << endl;
    cin >> inValue;

    while (inValue != '@') {
        if (bst->findOrInsert(inValue)) {
            cout << "Value found in the BST already!" << endl;
        } else {
            cout << "Value added to the BST - thank you!" << endl;
        }

        cin >> inValue;
    }

    // uncomment this once you have an inOrder traversal in place.  behold the magic.
    bst->inOrder();

    cout << "Enter a character to delete: " << endl;
    cin >> inValue;

    cout << bst->removeValue(inValue) << endl;
    bst->inOrder();

    return 0;
}