#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

bool isMonotonic(vector<int> array) {
    // Write your code here.
    if (array.size() <= 1) {
        return true;
    }
    bool nonDecreasing = false;
    int id = 0;
    // Find the first consecutive non-equal elements
    while (id < array.size() - 1 && array[id] == array[id + 1]) {
        id++;
    }
    if (id == array.size() - 1) {
        return true;
    }

    // If the program got to this point array[id] and array[id + 1] cannnot be equal
    if (array[id] < array[id + 1]) {
        nonDecreasing = true;
    }

    for (int i = id; i < array.size() - 1; i++) {
        if (nonDecreasing == true) {
            if (array[i] > array[i + 1]) {
                return false;
            }
        } else {
            if (array[i] < array[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

void test_0(void) {
    vector<int> input = {-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
    bool expected = true;
    bool actual = isMonotonic(input);
    assert(expected == actual);
    printf("Done test 0!");
}

int main()
{
    test_0();
}