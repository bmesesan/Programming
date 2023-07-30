#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stack>
#include<string>

using namespace std;

vector<int> collidingAsteroids(vector<int> asteroids) {
    // Write your code here.
    stack<int> myStack;

    for (int i = 0; i < asteroids.size(); i++) {
        if (myStack.empty()) {
            myStack.push(asteroids[i]);
        } else {
            int topElem = myStack.top();
            bool isBroken = false;
            if (asteroids[i] < 0 && topElem > 0) {
                while (topElem > 0 && !myStack.empty()) {
                    int valNew = abs(asteroids[i]);
                    int valTop = abs(topElem);
                    if (valNew > valTop) {
                        myStack.pop();
                        if (!myStack.empty()) {
                            topElem = myStack.top();
                        }
                    } else if (valNew == valTop) {
                        isBroken = true;
                        myStack.pop();
                        break;
                    } else if (valNew < valTop) {
                        isBroken = true;
                        break;
                    }
                }
            }

            if (!isBroken) {
                myStack.push(asteroids[i]);
            }
        }
    }

    // Reconstruct array from the stack
    int* end = &myStack.top() + 1;
    int *begin = end - myStack.size();
    vector<int> stack_contents = vector<int>(begin, begin + myStack.size());

    return stack_contents;
}


void test_0(void) {
    std::cout << "Hello!" << std::endl;

    vector<int> input = {-3, 5, -8, 6, 7, -4, -7};
    vector<int> expected = {-3, -8, 6};
    auto actual = collidingAsteroids(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}