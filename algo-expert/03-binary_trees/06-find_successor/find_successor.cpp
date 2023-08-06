#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stack>
#include<string>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
    public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;
    BinaryTree* parent = nullptr;

    BinaryTree(int value) { this->value = value; }
};


void inOrderTraversal(BinaryTree* tree, vector<BinaryTree*>& myList) {
    if (tree == nullptr) {
        return;
    }

    inOrderTraversal(tree->left, myList);

    std::cout << tree->value << std::endl;
    myList.push_back(tree);

    inOrderTraversal(tree->right, myList);
}


BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node) {
    // Write your code here.
    vector<BinaryTree*> myVector;

    inOrderTraversal(tree, myVector);

    for (int i = 0; i < myVector.size(); i++) {
        if (myVector[i] == node) {
            if (i == myVector.size() - 1) { 
                return nullptr;
            } else {
                return myVector[i + 1];
            }
        }
    }

    return nullptr;
}

void test_0(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->parent = root;
    root->right = new BinaryTree(3);
    root->right->parent = root;
    root->left->left = new BinaryTree(4);
    root->left->left->parent = root->left;
    root->left->right = new BinaryTree(5);
    root->left->right->parent = root->left;
    root->left->left->left = new BinaryTree(6);
    root->left->left->left->parent = root->left->left;
    auto node = root->left->right;
    auto expected = root;
    auto actual = findSuccessor(root, node);
    assert(expected == actual);
}

int main()
{
    test_0();
}