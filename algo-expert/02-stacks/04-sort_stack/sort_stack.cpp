#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> sortStack(vector<int>& stack) {
    // Write your code here
    if (!stack.empty()) {
        int lastElem = stack.back();
        stack.pop_back();
        stack = sortStack(stack);
        if (stack.empty()) {
            stack.push_back(lastElem);
        } else {
            int lastElemSorted = stack.back();
            vector<int> auxStack;
            while (lastElem < lastElemSorted && !stack.empty()) {
                auxStack.push_back(lastElemSorted);
                stack.pop_back();
                if (!stack.empty()) {
                    lastElemSorted = stack.back();
                }
            }
            stack.push_back(lastElem);
            while (!auxStack.empty()) {
                stack.push_back(auxStack.back());
                auxStack.pop_back();
            }
        }
    }
    return stack;
}


void test_0(void) {
    std::cout << "Hello!" << std::endl;

    vector<int> input = {-5, 2, -2, 4, 3, 1};
    vector<int> expected = {-5, -2, 1, 2, 3, 4};
    auto actual = sortStack(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}