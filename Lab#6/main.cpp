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

    /*
     * inOrder
     * Does inOrder traversal
     * Returns: Nothing.
     */
    void inOrder(TreeNode *root) {
        if (root == nullptr) return ;
        inOrder(root->left);
        cout << root->data << endl;
        inOrder(root->right);
    }

    /*
     * visualize
     * Visualizes a BST with indentation
     * Returns: Nothing.
     */
    void visualize(TreeNode *root, int indentation, string prefix) {
        if (!root) return ;

        // print indentation
        for (int i = 0; i < indentation; i++) cout << " ";

        // print value
        cout << prefix << root->data << endl;

        visualize(root->left, indentation + 4, "L: ");
        visualize(root->right, indentation + 4, "R: ");
    }

    /*
     * minValueNode
     * Returns: Minimum value node in a given tree
     */
    TreeNode* minValueNode(TreeNode* root) {

        // base
        if (!root->left)
            return root;

        // keep going left
        return minValueNode(root->left);
    }

    /*
     * removeValue
     * Deletes a given value from the BST if found
     * Returns: pointer to root
     */
    TreeNode* removeValue(TreeNode* root, Item value) {

        // base
        if (!root) return nullptr;

        // if the value to be deleted is less than current value
        // we recursively go to the left
        if (value < root->data)
            root->left = removeValue(root->left, value);

        // if the value to be deleted is greater than current value
        // we recursively go to the right
        else if (value > root->data)
            root->right = removeValue(root->right, value);

        // here, check if the value is in our tree,
        // if not, return the tree without changes
        else if (root->data != value)
            return root;

        else {
            // here, we check if root has only one or no child

            // first, we check left subtree
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // then, we check right subtree
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // if we made it here, it means that root has two children

            // first, we need to find the value right next to root in inOrder traversal
            // it is the same as the minimum value in root's right subtree
            TreeNode* temp = minValueNode(root->right);

            // assign values
            root->data = temp->data;

            // recursively, delete the temp->value in root's right subtree
            root->right = removeValue(root->right, temp->data);
        }
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

    // calls a private function with the same name
    int removeValue(Item value) {
        removeValue(root, value);
    }

    // calls a private function with the same name
    void visualize() {
        visualize(root, 0, "");
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

    bst->visualize();

    cout << "Enter a character to delete: " << endl;
    cin >> inValue;

    bst->removeValue(inValue);
    bst->visualize();

    return 0;
}