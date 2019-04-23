#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 * Our class implementation of Binary Tree
 */
template <class Item>
class BinaryTree {
private:
    struct TreeNode {
        Item data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(Item d, TreeNode *l, TreeNode *r) {
            data = d;
            left = l;
            right = r;
        }
    };

    TreeNode *root;

    TreeNode *buildTree(ifstream& myFile) {
        Item data;
        myFile >> data;

        // if '@' then stop recursion
        if (data == '@') return nullptr;

        // create a new instance of TreeNode and proceed with recursion
        auto *node = new TreeNode(data, nullptr, nullptr);
        node->left = buildTree(myFile);
        node->right = buildTree(myFile);

        return node;
    }

    void inOrder(TreeNode *head) {
        if (head == nullptr) return ;
        inOrder(head->left);
        cout << head->data << endl;
        inOrder(head->right);
    }

    void preOrder(TreeNode *head) {
        if (head == nullptr) return ;
        cout << head->data << endl;
        preOrder(head->left);
        preOrder(head->right);
    }

    void postOrder(TreeNode *head) {
        if (head == nullptr) return ;
        postOrder(head->left);
        postOrder(head->right);
        cout << head->data << endl;
    }

public:
    // constructor (called on "new")
    BinaryTree(string filename) {
        ifstream myFile(filename);
        root = buildTree(myFile);
        myFile.close(); // don't forget to close the file, once done :)
    }

    void inOrder() {
        inOrder(root);
    }

    void preOrder() {
        preOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }
};

int main() {
    // full path to the file we want to read from
    string filename = "C:\\Users\\User\\Desktop\\Bennington College\\term2\\Data_Structures_C++\\MyGit\\Lab#5\\Tree#2\\test.txt";
    // char type since the .txt file consist of characters, instead of words
    BinaryTree<char> *myTree = new BinaryTree<char>(filename);

    // here, calling three different traversal functions of binary tree
    myTree->preOrder();
    cout << "--------" << endl;
    myTree->inOrder();
    cout << "--------" << endl;
    myTree->postOrder();


    return 0;
}