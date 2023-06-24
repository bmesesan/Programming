#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

int bestSeat(vector<int> seats) {
    // Write your code here.
    vector<int> occupiedIdx;
    for (int i = 0; i < seats.size(); i++) {
        if (seats[i] == 1) {
            occupiedIdx.push_back(i);
        }
    }

    int maxDiff = 1;
    int idL = -1;
    int idR = -1;
    for (int i = 0; i < occupiedIdx.size() - 1; i++) {
        int j = i + 1;
        int diff = occupiedIdx[j] - occupiedIdx[i];
        if (diff > maxDiff) {
            maxDiff = diff;
            idL = occupiedIdx[i];
            idR = occupiedIdx[j];  
        }
    }

    if (maxDiff != 1) {
        return (idL + (idR - idL) / 2);
    }

    return -1;
}


void test_0(void) {
    vector<int> input = {1, 0, 1, 0, 0, 0, 1};
    auto expected = 4;
    auto actual = bestSeat(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}