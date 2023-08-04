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


void computeVals(BinaryTree* root, int currentSum, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }

    computeVals(root->left, currentSum + root->value, arr);

    computeVals(root->right, currentSum + root->value, arr);

    // When we get to this point we are on a leaf
    // A new element can be added
    if (root->left == nullptr && root->right == nullptr) {
        arr.push_back(currentSum + root->value);
    }
}


vector<int> branchSums(BinaryTree* root) {
    vector<int> outputVector;
    
    // Write your code here.
    if (root == nullptr) {
        return {};
    }
    
    computeVals(root, 0, outputVector);

    return outputVector;
}


class TestBinaryTree : public BinaryTree {
    public:
        TestBinaryTree(int value) : BinaryTree(value){};

        BinaryTree* insert(vector<int> values, int i = 0) {
            if (i >= values.size()) return nullptr;
            vector<BinaryTree*> queue = {this};
            while (queue.size() > 0) {
            BinaryTree* current = queue[0];
            queue.erase(queue.begin());
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
            insert(values, i + 1);
            return this;
        }
};


void test_0(void) {
    std::cout << "Hello!" << std::endl;

    TestBinaryTree* tree = new TestBinaryTree(1);
    tree->insert({2, 3, 4, 5, 6, 7, 8, 9, 10});
    vector<int> expected = {15, 16, 18, 10, 11};
    assert(branchSums(tree) == expected);
}

int main()
{
    test_0();
}