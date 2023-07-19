#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;

string bestDigits(string number, int numDigits) {
    // Write your code here.
    stack<char> myStack;
    for (int i = 0; i < number.length(); i++) {
        std::cout << "Hello! " << i << std::endl;
        // Create myStack
        if (myStack.empty()) {
            myStack.push(number[i]);
        } else {
            char topElem = myStack.top();
            while (topElem < number[i] && numDigits > 0 && !myStack.empty()) {
                myStack.pop();
                numDigits--;
                if (!myStack.empty()) {
                    topElem = myStack.top();
                }
            }
            myStack.push(number[i]);
        }
    }

    // Remove trailing elements
    while (numDigits > 0) {
        myStack.pop();
        numDigits--;
    }

    // Reconstruct number from the stack
    char* end = &myStack.top() + 1;
    char *begin = end - myStack.size();
    string stack_contents = string(begin, myStack.size());

    return stack_contents;
}


void test_0(void) {
    std::cout << "Hello!" << std::endl;

    string number = "11111111119999999999";
    int numDigits = 10;
    string expected = "2";
    auto actual = bestDigits(number, numDigits);
    assert(expected == actual);
}

int main()
{
    test_0();
}