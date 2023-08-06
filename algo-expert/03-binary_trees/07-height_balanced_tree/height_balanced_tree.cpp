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

        BinaryTree(int value) { this->value = value; }
};

int getHeight(BinaryTree* tree) {
    if (tree == nullptr) {
        return 0;
    }

    return (1 + max(getHeight(tree->left), getHeight(tree->right)));
}


bool heightBalancedBinaryTree(BinaryTree* tree) {
    // Write your code here.
    if (tree == nullptr) {
        return true;
    }

    int heightL = getHeight(tree->left);
    int heightR = getHeight(tree->right);
    bool checkCondition = (abs(heightL - heightR) <= 1);
    
    return checkCondition & heightBalancedBinaryTree(tree->left) & heightBalancedBinaryTree(tree->right);
}


void test_0(void) {
    std::cout << "Hello!" << std::endl;

    auto root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    root->left->right->left = new BinaryTree(7);
    root->left->right->right = new BinaryTree(8);
    bool expected = true;
    auto actual = heightBalancedBinaryTree(root);
    assert(expected == actual);
}

int main()
{
    test_0();
}