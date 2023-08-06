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

        BinaryTree(int value);
        void insert(vector<int> values, int i = 0);
        void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree* tree) {
    // Case in which the node is null
    if (tree == nullptr) {
        return;
    }

    // Case in which the node is a leaf
    if (tree->right == nullptr && tree->left == nullptr) {
        return;
    }

    BinaryTree* aux = tree->left;
    tree->left = tree->right;
    tree->right = aux;

    invertBinaryTree(tree->left);
    invertBinaryTree(tree->right);
}

BinaryTree::BinaryTree(int value) {
  this->value = value;
  this->left = nullptr;
  this->right = nullptr;
}

void BinaryTree::insert(vector<int> values, int i) {
    if (i >= values.size()) {
        return;
    }
    deque<BinaryTree*> queue;
    queue.push_back(this);
    while (queue.size() > 0) {
        BinaryTree* current = queue.front();
        queue.pop_front();
        if (current->left == nullptr) {
        current->left = new BinaryTree(values[i]);
        break;
        }
        queue.push_back(current->left);
        if (current->right == nullptr) {
        current->right = new BinaryTree(values[i]);
        break;
        }
        queue.push_back(current->right);
    }
    this->insert(values, i + 1);
}

void BinaryTree::invertedInsert(vector<int> values, int i) {
    if (i >= values.size()) {
        return;
    }
    deque<BinaryTree*> queue;
    queue.push_back(this);
    while (queue.size() > 0) {
        BinaryTree* current = queue.front();
        queue.pop_front();
        if (current->right == nullptr) {
        current->right = new BinaryTree(values[i]);
        break;
        }
        queue.push_back(current->right);
        if (current->left == nullptr) {
        current->left = new BinaryTree(values[i]);
        break;
        }
        queue.push_back(current->left);
    }
    this->invertedInsert(values, i + 1);
}

bool compareBT(BinaryTree* a, BinaryTree* b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }
    if (a != nullptr && b != nullptr) {
        return a->value == b->value && compareBT(a->left, b->left) &&
            compareBT(a->right, b->right);
    }
    return false;
}

void test_0(void) {
    std::cout << "Hello!" << std::endl;

    BinaryTree tree(1);
    tree.insert({2, 3, 4, 5, 6, 7, 8, 9});
    invertBinaryTree(&tree);
    BinaryTree invertedTree(1);
    invertedTree.invertedInsert({2, 3, 4, 5, 6, 7, 8, 9});
    assert(compareBT(&tree, &invertedTree) == 1);
}

int main()
{
    test_0();
}