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

int evaluateExpressionTree(BinaryTree* tree) {
    // Write your code here.
    if (tree->left == nullptr && tree->right == nullptr) {
        return tree->value;
    } else if (tree->value == -1) {
        return evaluateExpressionTree(tree->left) + evaluateExpressionTree(tree->right);
    } else if (tree->value == -2) {
        return evaluateExpressionTree(tree->left) - evaluateExpressionTree(tree->right);
    } else if (tree->value == -3) {
        return evaluateExpressionTree(tree->left) / evaluateExpressionTree(tree->right);
    } else if (tree->value == -4) {
        return evaluateExpressionTree(tree->left) * evaluateExpressionTree(tree->right);
    }
}

void test_0(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree* tree = new BinaryTree(-1);
    tree->left = new BinaryTree(2);
    tree->right = new BinaryTree(-2);
    tree->right->left = new BinaryTree(5);
    tree->right->right = new BinaryTree(1);
    int expected = 6;
    auto actual = evaluateExpressionTree(tree);
    assert(expected == actual);
}

int main()
{
    test_0();
}