#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

vector<int> sortedMerge(vector<int> arr1, vector<int> arr2) {
    vector<int> result;
    result.reserve(arr1.size() + arr2.size());
    int cnt1 = 0;
    int cnt2 = 0;
    while (cnt1 < arr1.size() || cnt2 < arr2.size()) {
        if (cnt1 < arr1.size() && cnt2 < arr2.size()) {
            if (arr1[cnt1] < arr2[cnt2]) {
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

void mergeSort(vector<int> &arr) {
    if (arr.size() <= 1) {
        return;
    }

    vector<int> arr_front(arr.begin(), arr.begin() + arr.size() / 2); 
    vector<int> arr_back(arr.begin() + arr.size() / 2, arr.end());

    mergeSort(arr_front);
    mergeSort(arr_back);
    arr = sortedMerge(arr_front, arr_back);

    arr_front.clear();
    arr_front.shrink_to_fit();
    arr_back.clear();
    arr_back.shrink_to_fit();
}


int firstDuplicateValue(vector<int> array) {
    if (array.size() <= 1) {
        return -1;
    }
    std::map<int, bool> myMap; 


    int minIdx = -1;
    for (int i = 0; i < array.size(); i++) {
        if (myMap.count(array[i]) == 1) {
            return array[i];
        } else {
            myMap.insert({array[i], true});
        }
    }

    return -1;
}


void test_0(void) {
    vector<int> input = {2, 1, 5, 2, 3, 3, 4};
    int expected = 2;
    int actual = firstDuplicateValue(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}