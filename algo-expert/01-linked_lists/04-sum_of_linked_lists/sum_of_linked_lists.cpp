#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
    // Write your code here.
    LinkedList *cursorOne = linkedListOne;
    LinkedList *cursorTwo = linkedListTwo;
    LinkedList *result = new LinkedList(0);
    LinkedList *cursorResult = result;
    LinkedList *cursorResultPrev = nullptr;
    int sum = 0;
    int carry = 0;

    while (cursorOne != nullptr || cursorTwo != nullptr) {
        sum = 0;
        if (cursorResult == nullptr) {
            cursorResult = new LinkedList(0);
            cursorResultPrev->next = cursorResult;
        }
        if (cursorOne != nullptr && cursorTwo != nullptr) {
            sum = cursorOne->value + cursorTwo->value;

            cursorOne = cursorOne->next;
            cursorTwo = cursorTwo->next;
        } else {
            if (cursorOne != nullptr) {
                sum = cursorOne->value;
                cursorOne = cursorOne->next;
            } else {
                sum = cursorTwo->value;
                cursorTwo = cursorTwo->next;
            }
        }

        cursorResult->value = sum % 10 + carry;
        cursorResultPrev = cursorResult;
        cursorResult = cursorResult->next;
        if (sum >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
    }

    if (carry == 1) {
        cursorResult = new LinkedList(1);
        cursorResultPrev->next = cursorResult;
    }

    return result;
}

LinkedList *addMany(LinkedList *linkedList, vector<int> values) {
    auto current = linkedList;
    while (current->next != nullptr) {
        current = current->next;
    }
    for (int value : values) {
        current->next = new LinkedList(value);
        current = current->next;
    }
    return linkedList;
}

vector<int> getNodesInArray(LinkedList *linkedList) {
    vector<int> nodes;
    auto current = linkedList;
    while (current != nullptr) {
        nodes.push_back(current->value);
        current = current->next;
    }
    return nodes;
}


void test_0(void) {
    auto ll1 = addMany(new LinkedList(2), {4, 7, 1});
    auto ll2 = addMany(new LinkedList(9), {4, 5});
    auto expected = addMany(new LinkedList(1), {9, 2, 2});
    auto actual = sumOfLinkedLists(ll1, ll2);
    assert(getNodesInArray(actual) == getNodesInArray(expected));
}

int main()
{
    test_0();
}