#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
    std::vector<int> result;
    result.reserve(array.size());

    int start = 0;
    int end = array.size() - 1;
    while (end >= start) {
        if (abs(array[start]) > abs(array[end])) {
            result.insert(result.begin(), pow(array[start], 2));
            start++;
        } else {
            result.insert(result.begin(), pow(array[end], 2));
            end--;
        }
    }

    return result;
}


void test_0(void) {
    // Test 1
    vector<int> array = {1, 2, 3, 5, 6, 8, 9};
    vector<int> result = sortedSquaredArray(array);
    printf("Done test 0!");
}

int main()
{
    // Test 1
    test_0();
}