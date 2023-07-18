#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
    stack<int> idxStack;
    int start;
    int stop;
    int toAdd = 1;
    if (direction == "EAST") {
        start = 0;
        stop = buildings.size();
        toAdd = 1;
    } else if (direction == "WEST") {
        start = buildings.size() - 1;
        stop = -1;
        toAdd = -1;
    }
    for (int i = start; i != stop; i+=toAdd) {
        if (idxStack.empty()) {
            idxStack.push(i);
        } else {
            if (buildings[i] < buildings[idxStack.top()]) {
                idxStack.push(i);
            } else {
                int top_idx = idxStack.top();
                while (buildings[i] >= buildings[top_idx] && !idxStack.empty()) {
                    idxStack.pop();
                    if (!idxStack.empty()) {
                        top_idx = idxStack.top();
                    }
                }
                idxStack.push(i);
            }
        }
    }

    int* end;
    int* begin;
    // end = &idxStack.top() + 1;
    // begin = end - idxStack.size();
    vector<int> stack_contents;
    if (direction == "EAST") {
        end = &idxStack.top() + 1;
        begin = end - idxStack.size();
        stack_contents = vector<int>(begin, end);
    } else if (direction == "WEST") {
        while (!idxStack.empty()){
            int elem = idxStack.top();
            idxStack.pop();
            stack_contents.push_back(elem);
        }
    }
    return stack_contents;
}


void test_0(void) {
    std::cout << "Hello!" << std::endl;


    vector<int> buildings = {3, 5, 4, 4, 3, 1, 3, 2};
    string direction = "EAST";
    vector<int> expected = {1, 3, 6, 7};
    vector<int> actual = sunsetViews(buildings, direction);
    assert(expected == actual);
}

int main()
{
    test_0();
}