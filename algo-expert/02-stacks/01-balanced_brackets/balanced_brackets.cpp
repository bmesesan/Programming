#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;

bool charIsValue(char f_char, const std::map<char, char>& f_map)
{
    for (auto iter = f_map.begin(); iter != f_map.end(); iter++) {
        char current = iter->second;
        if (f_char == iter->second) {
            return true;
        }
    }
    return false;
}

bool balancedBrackets(string str) {
    // Write your code here.
    std::map<char, char> bracketsMap = {{'{', '}'},
                                        {'[', ']'},
                                        {'(', ')'}};
    std::stack<char> myStack;                     
    for (auto &ch : str) {
        if (bracketsMap.count(ch) == 1) {
            // Opening bracket detected - push it on the stack
            myStack.push(ch);
        } else {
            if (charIsValue(ch, bracketsMap)) {
                // Closing bracket detected - check if the top of the stack corresponds to it
                if (myStack.size() == 0) {
                    return false;
                }
                char topElem = myStack.top();
                if (bracketsMap[topElem] != ch) {
                    return false;
                }
                myStack.pop();
            }
        }
    }       

    if (myStack.size() > 0) {
        return false;
    }

    return true;
}


void test_0(void) {
    std::cout << "Hello!" << std::endl;


    bool test_val = balancedBrackets(")[]}");
    // assert(balancedBrackets("(((((({{{{{[[[[[([)])]]]]]}}}}}))))))") == false);
    std::cout << "Hello!" << std::endl;
}

int main()
{
    test_0();
}