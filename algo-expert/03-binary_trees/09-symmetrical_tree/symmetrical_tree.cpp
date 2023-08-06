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

bool symmetricalTree(BinaryTree* tree) {
    // Write your code here.
    return false;
}


void test_0(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree* tree1 = new BinaryTree(1);
    tree1->left = new BinaryTree(3);
    tree1->left->left = new BinaryTree(7);
    tree1->left->right = new BinaryTree(4);
    tree1->right = new BinaryTree(2);

    BinaryTree* tree2 = new BinaryTree(1);
    tree2->left = new BinaryTree(5);
    tree2->left->left = new BinaryTree(2);
    tree2->right = new BinaryTree(9);
    tree2->right->left = new BinaryTree(7);
    tree2->right->right = new BinaryTree(6);

    auto actual = mergeBinaryTrees(tree1, tree2);
    assert(actual->value == 2);
    assert(actual->left->value == 8);
    assert(actual->left->left->value == 9);
    assert(actual->left->right->value == 4);
    assert(actual->right->value == 11);
    assert(actual->right->left->value == 7);
    assert(actual->right->right->value == 6);
}

int main()
{
    test_0();
}