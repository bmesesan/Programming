#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

bool zeroSumSubarray(vector<int> nums) {
    map<int, bool> sumVector;

    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += nums[j];
        }
        if (sum == 0) {
            return true;
        }
        if (sumVector.count(sum) == 1) {
            return true;
        }
        sumVector.insert({sum, true});
    }


    return false;
}


void test_0(void) {
    auto input = {4, 2, -1, -1, 3};
    auto expected = true;
    auto actual = zeroSumSubarray(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}