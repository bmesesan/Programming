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

int getSubtreeSum(BinaryTree* tree) {
    if (tree == nullptr) {
        return 0;
    }
    
    // Case in which the current node is a leaf
    if (tree->left == nullptr && tree->right == nullptr) {
        return tree->value;
    }

    int returnSum = tree->value;
    if (tree->left != nullptr) {
        returnSum += getSubtreeSum(tree->left);
    }

    if (tree->right != nullptr) {
        returnSum += getSubtreeSum(tree->right);
    }

    return returnSum;
}

int splitBinaryTreeRunner(BinaryTree* tree, int trailingSum) {
    if (tree == nullptr) {
        return 0;
    }

    // Case in which the current node is a leaf
    if (tree->left == nullptr && tree->right == nullptr) {
        return 0;
    }

    int sumLeft = getSubtreeSum(tree->left);
    int sumRight = getSubtreeSum(tree->right);

    // Check whether the sum of the current value + the sum of the left subtree is equal to the sum of the right subrtree
    int sumCurrLeft = tree->value + sumLeft + trailingSum;
    if (sumCurrLeft == sumRight && tree->right != nullptr) {
        return sumCurrLeft;
    }

    // Check whether the sum of the current value + the sum of the right subtree is equal to the sum of the left subrtree
    int sumCurrRight = tree->value + sumRight + trailingSum;
    if (sumLeft == sumCurrRight && tree->left != nullptr) {
        return sumCurrRight;
    }

    // Add the current node value to the trailing sum value
    trailingSum += tree->value;

    // Recursively run this function with the left subtree
    int leftSubVal = splitBinaryTreeRunner(tree->left, trailingSum + sumRight);
    // If the left subtree yields a non-zero result, then return it
    if (leftSubVal != 0) {
        return leftSubVal;
    }

    // Recursively run this function with the right subtree
    int rightSubVal = splitBinaryTreeRunner(tree->right, trailingSum + sumLeft);
    // If the right subtree yields a non-zero result, then return it
    if (rightSubVal != 0) {
        return rightSubVal;
    }

    // If none yield a non-zero result, then return 0
    return 0;
}

int splitBinaryTree(BinaryTree* tree) {
    return splitBinaryTreeRunner(tree, 0);
}


void test_0(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree* tree = new BinaryTree(2);
    tree->left = new BinaryTree(4);
    tree->left->left = new BinaryTree(4);
    tree->left->right = new BinaryTree(6);
    tree->right = new BinaryTree(10);
    tree->right->left = new BinaryTree(3);
    tree->right->right = new BinaryTree(3);
    int expected = 16;
    auto actual = splitBinaryTree(tree);
    assert(expected == actual);
}

void test_14(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree* tree = new BinaryTree(1);
    tree->left = new BinaryTree(6);
    tree->left->left = new BinaryTree(6);
    tree->right = new BinaryTree(3);
    tree->right->right = new BinaryTree(4);
    int expected = 0;
    auto actual = splitBinaryTree(tree);
    assert(expected == actual);
}

int main()
{
    test_14();
}