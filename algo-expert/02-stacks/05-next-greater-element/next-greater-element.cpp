#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;

int getNextGreater(int idx, stack<int> myStack, stack<int> copyStack) {
    int topElem = myStack.top();
    myStack.pop();
    while(!myStack.empty()) {
        if (myStack.top() > topElem) {
            return myStack.top();
        }
        myStack.pop();
    }

    for (int i = 0; i < idx; i++) {
        if (copyStack.top() > topElem) {
            return copyStack.top();
        }
        copyStack.pop();
    }

    return -1;
}

vector<int> nextGreaterElement(vector<int> array) {
    stack<int> myStack;
    stack<int> copyStack;
    vector<int> output;

    while(!array.empty()) {
        myStack.push(array.back());
        copyStack.push(array.back());
        array.pop_back();
    }

    int idx = 0;
    while (!myStack.empty()) {
        int nextGreater = getNextGreater(idx, myStack, copyStack);
        output.push_back(nextGreater);
        myStack.pop();
        idx++;
    }

    return output;
}



void test_0(void) {
    std::cout << "Hello!" << std::endl;

    vector<int> input = {2, 5, -3, -4, 6, 7, 2};
    vector<int> expected = {5, 6, 6, 6, 7, -1, 5};
    auto actual = nextGreaterElement(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}