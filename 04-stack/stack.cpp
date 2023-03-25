#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <stdlib.h>

using namespace std;

// 1) Reverse array
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

// 2) Eval expression
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

// 3) Reverse a stack using recursion
void insertAtBottom(stack<int> &s, int f_elem)
{
    if (s.empty()) {
        s.push(f_elem);
        return;
    }
    int currElem = s.top();
    s.pop();
    insertAtBottom(s, f_elem);
    s.push(currElem);
}

void reverseStack(stack<int> &s)
{
    if (s.size() > 0) {
        int topElem = s.top();
        s.pop();
        reverseStack(s);
        insertAtBottom(s, topElem);
    }
    return;
}

void testReverseStack(void)
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    reverseStack(s);
    while (!s.empty()) {
        cout << s.top() << std::endl;
        s.pop();
    }
}

// 4) Sort a stack using recursion
void insertElem(stack<int> &f_stack, int f_elem)
{
    if (f_stack.empty()) {
        f_stack.push(f_elem);
        return;
    } else if (f_elem > f_stack.top())
    {
        f_stack.push(f_elem);
        return;
    }
    int currTop = f_stack.top();
    f_stack.pop();
    insertElem(f_stack, f_elem);
    f_stack.push(currTop);
}

void sortStack(stack<int> &f_stack)
{
    if (!f_stack.empty()) {
        int currElem = f_stack.top();
        f_stack.pop();
        sortStack(f_stack);
        insertElem(f_stack, currElem);
    }
    return;
}

void testSortStack(void)
{
    stack<int> s;
    s.push(-3);
    s.push(14);
    s.push(18);
    s.push(-5);
    s.push(30);
    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << std::endl;
        s.pop();
    }
}

// 5) Stock span problem
// The stock span problem is a financial problem where we have a series of N daily price quotes for a
// stock and we need to calculate the span of the stock’s price for all N days.
// The span Si of the stock’s price on a given day i is defined as the maximum number of
// consecutive days just before the given day, for which the price of the stock on the
// current day is less than its price on the given day. 
int* genStockSpanArr(int *f_priceArr, int f_n)
{
    int *result = (int*)malloc(f_n * sizeof(int));
    stack<int> st;
    st.push(0);

    result[0] = 1;
    for (int i = 1; i < f_n; i++) {
        while (!st.empty() && f_priceArr[st.top()] <= f_priceArr[i]) {
            st.pop();
        }
        if (st.empty()) {
            result[i] = i + 1;
        } else {
            result[i] = i - st.top();
        }
        st.push(i);
    }
    return result;
}

void testStockSpanProblem(void)
{
    int n = 7;
    int price[] = {100, 80, 60, 70, 60, 75, 85};

    int *result = genStockSpanArr(&price[0], n);
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
}

// Driver code
int main()
{
    testStockSpanProblem();
    return 0;
}