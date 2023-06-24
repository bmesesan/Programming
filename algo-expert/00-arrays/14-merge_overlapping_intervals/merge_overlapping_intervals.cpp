#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

vector<vector<int>> sortedMerge(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> result;
    int cnt1 = 0;
    int cnt2 = 0;
    while (cnt1 < arr1.size() || cnt2 < arr2.size()) {
        if (cnt1 < arr1.size() && cnt2 < arr2.size()) {
            if (arr1[cnt1][0] < arr2[cnt2][0]) {
                result.push_back(arr1[cnt1]);
                cnt1++;
            } else {
                result.push_back(arr2[cnt2]);
                cnt2++;
            }
        } else {
            if (cnt1 < arr1.size()) {
                result.push_back(arr1[cnt1]);
                cnt1++;
            } else {
                result.push_back(arr2[cnt2]);
                cnt2++;
            }
        }
    }
    return result;
}

void mergeSort(vector<vector<int>>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    vector<vector<int>> arr_left;
    vector<vector<int>> arr_right;
    for (int i = 0; i < arr.size() / 2; i++) {
        arr_left.push_back(arr[i]);
    }
    for (int i = arr.size() / 2; i < arr.size(); i++) {
        arr_right.push_back(arr[i]);
    }

    mergeSort(arr_left);
    mergeSort(arr_right);
    arr = sortedMerge(arr_left, arr_right);

    arr_left.clear();
    arr_left.shrink_to_fit();
    arr_right.clear();
    arr_right.shrink_to_fit();
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
    vector<vector<int>> result;
    
    if (intervals.size() <= 1) {
        return intervals;
    }
    
    mergeSort(intervals);

    int newLeft = intervals[0][0];
    int newRight = intervals[0][1];
    int i = 1;
    while (i < intervals.size()) {
        
        int candLeft = intervals[i][0];
        int candRight = intervals[i][1];
        
        if (candLeft <= newRight) {
            newRight = max(candRight, newRight);
        } else {
            result.push_back({newLeft, newRight});
            newLeft = candLeft;
            newRight = candRight;
        }
        i++;
    }
    result.push_back({newLeft, newRight});

    return result;
}

void test_0(void) {
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {4, 7}, {6, 8}, {9, 10}};
    vector<vector<int>> expected = {{1, 2}, {3, 8}, {9, 10}};
    auto actual = mergeOverlappingIntervals(intervals);
    assert(expected == actual);
}

void test_1(void) {
    vector<vector<int>> intervals = {
        {43, 49},
        {9, 12},
        {12, 54},
        {45, 90},
        {91, 93}
    };
    vector<vector<int>> expected = {{9, 90}, {91, 93}};
    auto actual = mergeOverlappingIntervals(intervals);
    assert(expected == actual);
}

void test_2(void) {
    vector<vector<int>> intervals = {
        {100, 105},
        {1, 104}
    };
    vector<vector<int>> expected = {{1, 105}};
    auto actual = mergeOverlappingIntervals(intervals);
    assert(expected == actual);
}

int main()
{
    // test_0();
    // test_1();
    test_2();
}