#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stack>
#include<string>

using namespace std;

// This is the class of the input root. Do not edit it.
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

void setNodeDepth(BinaryTree* root, int currDepth, int *resNodeDepth) {
    if (root == nullptr) {
        return;
    } else {
        *resNodeDepth += currDepth;
        setNodeDepth(root->left, currDepth + 1, resNodeDepth);
        setNodeDepth(root->right, currDepth + 1, resNodeDepth);
    }
}

int nodeDepths(BinaryTree* root) {
    // Write your code here.
    if (root == nullptr) {
        return 0;
    }

    int depth = 0;
    setNodeDepth(root, 0, &depth);

    return depth;
}

void test_0(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->left = new BinaryTree(4);
    root->left->left->left = new BinaryTree(8);
    root->left->left->right = new BinaryTree(9);
    root->left->right = new BinaryTree(5);
    root->right = new BinaryTree(3);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    int actual = nodeDepths(root);
    assert(actual == 16);
}

int main()
{
    test_0();
}