#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stack>
#include<string>

using namespace std;

int reversePolishNotation(vector<string> tokens) {
    // Write your code here.
    stack<int> myStack;

    string pluStr = string("+");
    string minusStr = string("-");
    string divStr = string("/");
    string mulStr = string("*");

    map<string, bool> opsMap = {
        {pluStr, true},
        {minusStr, true},
        {divStr, true},
        {mulStr, true}, 
    };

    for (int i = 0; i < tokens.size(); i++) {
        if (opsMap.count(tokens[i]) == 0) {
            int integerElem = stoi(tokens[i]);
            myStack.push(integerElem);
        } else {
            int elem_1 = myStack.top();
            myStack.pop();
            int elem_2 = myStack.top();
            myStack.pop();

            int result;
            if (tokens[i] == pluStr) {
                result = elem_2 + elem_1;
            } else if (tokens[i] == minusStr) {
                result = elem_2 - elem_1;
            } else if (tokens[i] == divStr) {
                result = elem_2 / elem_1;
            } else if (tokens[i] == mulStr) {
                result = elem_2 * elem_1;
            }

            myStack.push(result);
        }
    }

    return myStack.top();
}




void test_0(void) {
    std::cout << "Hello!" << std::endl;

    vector<string> input = {"3", "2", "+", "7", "*"};
    int expected = 35;
    auto actual = reversePolishNotation(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}