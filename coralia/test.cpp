#include <iostream>
#include <vector>
#include <string>

using namespace std;

void littleNumbers(int val) {
    val = val +1;
}

void f2(int *val) {
    *val = *val + 1;
}

int main()
{
    int myVal = 1;
    littleNumbers(myVal);
    cout << myVal << std::endl;
    f2(&myVal);
    cout << myVal << std::endl;
}