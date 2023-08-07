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

void computeLeftSub(BinaryTree* tree, vector<int>& leftSub) {
    if (tree == nullptr) {
        return;
    }

    leftSub.push_back(tree->value);

    computeLeftSub(tree->left, leftSub);

    computeLeftSub(tree->right, leftSub); 
}

void computeRightSub(BinaryTree* tree, vector<int>& rightSub) {
    if (tree == nullptr) {
        return;
    }

    rightSub.push_back(tree->value);

    computeRightSub(tree->right, rightSub);

    computeRightSub(tree->left, rightSub); 
}

bool symmetricalTree(BinaryTree* tree) {
    // Write your code here.
    vector<int> leftSub;
    vector<int> rightSub;

    computeLeftSub(tree->left, leftSub);
    computeRightSub(tree->right, rightSub);

    if (leftSub.size() != rightSub.size()) {
        return false;
    }

    for (int i = 0; i < leftSub.size(); i++) {
        if (leftSub[i] != rightSub[i]) {
            return false;
        }
    }

    return true;
}


void test_0(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree* tree = new BinaryTree(10);
    tree->left = new BinaryTree(5);
    tree->right = new BinaryTree(5);
    tree->left->left = new BinaryTree(7);
    tree->left->right = new BinaryTree(9);
    tree->right->left = new BinaryTree(9);
    tree->right->right = new BinaryTree(7);
    auto expected = true;
    auto actual = symmetricalTree(tree);
    assert(expected == actual);
}

void test_13(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree* tree = new BinaryTree(1);
    tree->left = new BinaryTree(2);
    tree->right = new BinaryTree(2);
    tree->left->left = new BinaryTree(3);
    tree->left->right = new BinaryTree(4);
    tree->left->right->left = new BinaryTree(5);
    tree->right->left = new BinaryTree(4);
    tree->right->right = new BinaryTree(3);
    tree->right->left->right = new BinaryTree(5);
    auto expected = true;
    auto actual = symmetricalTree(tree);
    assert(expected == actual);
}

int main()
{
    test_13();
}