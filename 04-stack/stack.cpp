#include <iostream>
#include <string>
#include <stack>

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

// Driver code
int main()
{
    stack<char>s;
    string str = "Test Bogdan";
    cout << "String is: " << str << std::endl;
    reverseString(str);
    cout << "Reversed string is : " << str << std::endl;
    return 0;
}