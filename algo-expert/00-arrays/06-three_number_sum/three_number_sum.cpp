#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

std::vector<int> sortedMerge(std::vector<int> arr_1, std::vector<int> arr_2) {
    std::vector<int> result;
    result.reserve(arr_1.size() + arr_2.size());
    int cnt_1 = 0;
    int cnt_2 = 0;
    while (cnt_1 < arr_1.size() || cnt_2 < arr_2.size()) {
        if (cnt_1 < arr_1.size() && cnt_2 < arr_2.size()) {
            if (arr_1[cnt_1] < arr_2[cnt_2]) {
                result.push_back(arr_1[cnt_1]);
                cnt_1++;
            } else {
                result.push_back(arr_2[cnt_2]);
                cnt_2++;
            }
        } else {
            if (cnt_1 >= arr_1.size()) {
                result.push_back(arr_2[cnt_2]);
                cnt_2++;
            } else {
                result.push_back(arr_1[cnt_1]);
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

    std::vector<int> arr_front(arr.begin(), arr.begin() + arr.size() / 2);
    std::vector<int> arr_back(arr.begin() + arr.size() / 2, arr.end());

    mergeSort(arr_front);
    mergeSort(arr_back);

    arr = sortedMerge(arr_front, arr_back);

    arr_front.clear();
    arr_front.shrink_to_fit();

    arr_back.clear();
    arr_back.shrink_to_fit();
}


vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    // Write your code here.
    vector<vector<int>> result;

    // n * log(n)
    mergeSort(array);


    for (int i = 0; i < array.size() - 2; i++) {
        int right = i + 1;
        int end = array.size() - 1;
        int currSum = array[i] + array[right] + array[end];
        while (right < end) {
            if (currSum != targetSum) {
                if (currSum > targetSum) {
                    end--;
                } else {
                    right++;
                }
                currSum = array[i] + array[right] + array[end];
            }
            
            if (currSum == targetSum && end != right){
                result.push_back(vector<int> {array[i], array[right], array[end]});
                if (right < end) {
                    right++;
                    currSum = array[i] + array[right] + array[end];
                }
            }
        }
    }

    return result;
}


void test_0(void) {
    vector<vector<int>> expected{{1, 2, 3}};
    assert(threeNumberSum({1, 2, 3}, 6) == expected);
    printf("Done test 0!");
}

int main()
{
    test_0();
}