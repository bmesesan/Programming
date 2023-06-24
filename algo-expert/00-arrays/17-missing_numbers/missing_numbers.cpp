#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

vector<int> missingNumbers(vector<int> nums) {
    // Write your code here.
    map<int, bool> appear;
    // O(n * log(n))
    // mergeSort(nums);
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        appear.insert({nums[i], true});
    }

    for (int i = 1; i <= nums.size() + 2; i++) {
        if (appear.count(i) == 0) {
            result.push_back(i);
        }
    }


    return result;
}



void test_0(void) {
    vector<int> input = {4, 5, 1, 3};
    vector<int> expected = {2, 6};
    auto actual = missingNumbers(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}