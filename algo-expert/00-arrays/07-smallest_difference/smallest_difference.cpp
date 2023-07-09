#include <iostream>
#include <vector>
#include <map>
#include <cassert>
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

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    std::vector<int> result;
    result.reserve(2);

    // O(n * log(n) + m * log(m))
    mergeSort(arrayOne);
    mergeSort(arrayTwo);
    
    // Write your code here.
    int idx_1 = 0;
    int idx_2 = 0;
    int minDiff = abs(arrayOne[idx_1] - arrayTwo[idx_2]);
    result =  {arrayOne[idx_1], arrayTwo[idx_2]};

    // O(n + m)
    while (idx_1 < arrayOne.size() && idx_2 < arrayTwo.size()) {
        // Check better candidate
        int currDiff = abs(arrayOne[idx_1] - arrayTwo[idx_2]);
        if (currDiff == 0) {
            return {arrayOne[idx_1], arrayTwo[idx_2]};
        }
        if (currDiff < minDiff) {
            result = {arrayOne[idx_1], arrayTwo[idx_2]};
            minDiff = currDiff;
        }
        if (arrayOne[idx_1] < arrayTwo[idx_2]) {
            idx_1++;
        } else {
            idx_2++;
        }
    }

    return result;
}


void test_0(void) {
    vector<int> expected{25, 1005};
    assert(smallestDifference({10, 0, 20, 25},
                              {1005, 1006, 1014, 1032, 1031}) == expected);
    printf("Done test 0!");
}

int main()
{
    test_0();
}