#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

std::vector<int> sortedMerge(vector<int> arrayOne, vector<int> arrayTwo) {
    std::vector<int> result;
    result.reserve(arrayOne.size() + arrayTwo.size());
    int cnt_1 = 0;
    int cnt_2 = 0;
    while (cnt_1 < arrayOne.size() || cnt_2 < arrayTwo.size()) {
        if (cnt_1 < arrayOne.size() && cnt_2 < arrayTwo.size()) {
            if (arrayOne[cnt_1] < arrayTwo[cnt_2]) {
                result.push_back(arrayOne[cnt_1]);
                cnt_1++;
            } else {
                result.push_back(arrayTwo[cnt_2]);
                cnt_2++;
            }
        } else {
            if (cnt_1 >= arrayOne.size()) {
                result.push_back(arrayTwo[cnt_2]);
                cnt_2++;
            } else {
                result.push_back(arrayOne[cnt_1]);
                cnt_1++;
            }
        }
    }
    return result;
}

void mergeSort(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    std::vector<int> arr_half_1(arr.begin(), arr.begin() + arr.size() / 2);
    std::vector<int> arr_half_2(arr.begin() + arr.size() / 2, arr.end());

    mergeSort(arr_half_1);
    mergeSort(arr_half_2);

    arr = sortedMerge(arr_half_1, arr_half_2);

    arr_half_1.clear();
    arr_half_1.shrink_to_fit();
    arr_half_2.clear();
    arr_half_2.shrink_to_fit();
}


vector<int> sweetAndSavory(vector<int> dishes, int target) {
    // Write your code here.
    vector<int> result{0, 0};

    if (dishes.size() <= 1) {
        return result;
    }
    
    mergeSort(dishes);
    int l = 0;
    int r = dishes.size() - 1;

    if (dishes[l] > 0 || dishes[r] < 0) {
        return result;
    }

    // Find the biggest negative value
    while (dishes[l] < 0) {
        l++;
    }
    l -= 1;

    // Find the smallest positive value
    while (dishes[r] > 0) {
        r--;
    }
    r += 1;

    int minSum;
    bool minSumSet = false;

    while (l > -1 && r < dishes.size()) {
        int sum = dishes[l] + dishes[r];
        if (sum <= target && !minSumSet) {
            minSumSet = true;
            minSum = sum;
            result[0] = dishes[l];
            result[1] = dishes[r];
        } else if (sum <= target && sum > minSum){
            minSum = sum;
            result[0] = dishes[l];
            result[1] = dishes[r];
        }
        if (sum <= target) {
            r++;
        } else {
            l--;
        }
    
    }
    
    return result;
}




void test_0(void) {
    vector<int> dishes = {2, 5, -4, -7, 12, 100, -25};
    int target = -5;
    vector<int> expected = {-7, 2};
    auto actual = sweetAndSavory(dishes, target);
    assert(expected == actual);
}

int main()
{
    test_0();
}