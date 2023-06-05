#include <iostream>
#include <vector>
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] + array[j] == targetSum) {
                std::vector<int> result = {array[i], array[j]};
                return result;
            }
        }
    }
    return {};
}

void test_0(void) {
    // Test 1
    vector<int> array = {-1, 11};
    int targetSum = 10;
    vector<int> result = twoNumberSum(array, targetSum);
    printf("Done test 0!");
}

int main()
{
    // Test 1
    test_0();
}