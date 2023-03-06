#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <stdlib.h>

using namespace std;

void reverseString(string &f_str)
{
    stack<char>s;

    for(auto it:f_str) s.push(it);
    f_str.clear();
    while(!s.empty()) {
        f_str.push_back(s.top());
        s.pop();
    }
}

void testReverseString(void)
{
    string str = "Test Bogdan";
    cout << "String is: " << str << std::endl;
    reverseString(str);
    cout << "Reversed string is : " << str << std::endl;
}

bool charIsKey(char f_char, const std::map<char, char>& f_map)
{
    for (auto iter = f_map.begin(); iter != f_map.end(); iter++) {
        char current = iter->first;
        if (f_char == iter->first) {
            return true;
        }
    }
    return false;
}

bool evalExpression(string &f_expr)
{
    stack<char> s;
    std::map<char, char> m{{'{', '}'}, {'[', ']'}, {'(', ')'}};

    for (int i = 0; i < f_expr.length(); i++) {
        if (charIsKey(f_expr[i], m)) {
            s.push(f_expr[i]);
        } else {
            char topChr = s.top();
            if (m[topChr] != f_expr[i]) {
                return false;
            }
            s.pop();
        }
    }
    return true;
}

void testEvalExpression(void)
{
    string expr = "[()]{}{[()()]()}";
    bool isBalanced = evalExpression(expr);
    if (isBalanced) {
        std::cout << "Balanced" << std::endl;
    } else {
        std::cout << "Not Balanced " << std::endl;
    }

    expr = "[(])";
    isBalanced = evalExpression(expr);
    if (isBalanced) {
        std::cout << "Balanced" << std::endl;
    } else {
        std::cout << "Not Balanced " << std::endl;
    }
}

// Driver code
int main()
{
    testEvalExpression();
    return 0;
}