#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
    std::vector<int> result;
    result.reserve(array.size());
    int curr_idx = 0;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == toMove) {
            result.push_back(array[i]);
        } else {
            result.insert(result.begin() + curr_idx, array[i]);
            curr_idx++;
        }
    }

    return result;
}

void test_0(void) {
    vector<int> array {2, 1, 2, 2, 2, 3, 4, 2};
    int toMove = 2;
    vector<int> expected {1, 3, 4, 2, 2, 2, 2, 2};
    assert(moveElementToEnd(array, toMove) == expected);
    printf("Done test 0!");
}

int main()
{
    test_0();
}