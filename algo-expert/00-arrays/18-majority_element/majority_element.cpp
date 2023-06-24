#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> array) {
    // Write your code here.
    map<int, int> appear;
    for (int i = 0; i < array.size(); i++) {
        if (appear.count(array[i]) == 0) {
            appear.insert({array[i], 1});
        } else {
            appear[array[i]]++;
        }
    }

    map<int, int>::iterator it;
    int maxAppearences = 0;
    int maxElem;
    for (it = appear.begin(); it != appear.end(); it++)
    {
        if (it->second > maxAppearences) {
            maxElem = it->first;
            maxAppearences = it->second; 
        }
    }

    return maxElem;
}



void test_0(void) {
    vector<int> input = {1, 2, 3, 2, 2, 1, 2};
    auto expected = 2;
    auto actual = majorityElement(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}