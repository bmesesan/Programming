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

LinkedList *middleNode(LinkedList *linkedList) {
    // Write your code here.
    LinkedList* fast = linkedList;
    LinkedList* slow = linkedList;
    if (linkedList->next == nullptr) {
        return linkedList;
    }
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}


LinkedList *addMany(LinkedList *linkedList, vector<int> values) {
    LinkedList *current = linkedList;
    while (current->next != nullptr) {
        current = current->next;
    }
    for (auto value : values) {
        current->next = new LinkedList(value);
        current = current->next;
    }
    return linkedList;
}

vector<int> getNodesInArray(LinkedList *linkedList) {
    vector<int> nodes;
    LinkedList *current = linkedList;
    while (current != nullptr) {
        nodes.push_back(current->value);
        current = current->next;
    }
    return nodes;
}

void test_0(void) {
    LinkedList *linkedList = new LinkedList(0);
    linkedList->next = new LinkedList(1);
    LinkedList *expected = new LinkedList(2);
    linkedList->next->next = expected;
    expected->next = new LinkedList(3);
    auto actual = middleNode(linkedList);
    assert(expected == actual);
}

int main()
{
    test_0();
}