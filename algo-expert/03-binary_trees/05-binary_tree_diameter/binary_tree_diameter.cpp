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
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

int getMaxLength(BinaryTree* node) {
    if (node == nullptr) {
        return 0;
    }

    return (1 + max(getMaxLength(node->left), getMaxLength(node->right)));
}

void computeDiameterVector(BinaryTree* tree, vector<int>& diamVector) {
    if (tree == nullptr) {
        return;
    }
    
    int lengthLeft = getMaxLength(tree->left);
    int lengthRight = getMaxLength(tree->right);
    int nodeDiam = lengthLeft + lengthRight; 
    diamVector.push_back(nodeDiam);

    computeDiameterVector(tree->left, diamVector);
    computeDiameterVector(tree->right, diamVector);
}

int binaryTreeDiameter(BinaryTree* tree) {
    // Write your code here.
    vector<int> diamVector;

    computeDiameterVector(tree, diamVector);
    int maxDiam = diamVector[0];
    if (diamVector.size() > 1) {
        for (int i = 1; i < diamVector.size(); i++) {
            if (diamVector[i] > maxDiam) {
                maxDiam = diamVector[i];
            }
        }
    }
    
    return maxDiam;
}

void test_0(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(3);
    root->left->left = new BinaryTree(7);
    root->left->left->left = new BinaryTree(8);
    root->left->left->left->left = new BinaryTree(9);
    root->left->right = new BinaryTree(4);
    root->left->right->right = new BinaryTree(5);
    root->left->right->right->right = new BinaryTree(6);
    root->right = new BinaryTree(2);
    int expected = 6;
    int actual = binaryTreeDiameter(root);
    assert(expected == actual);
}

int main()
{
    test_0();
}