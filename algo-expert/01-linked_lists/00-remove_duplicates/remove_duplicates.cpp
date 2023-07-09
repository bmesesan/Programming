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

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
    // Write your code here.
    map<int, bool> appear;
    LinkedList* result = new LinkedList(linkedList->value);
    LinkedList* head = result;
    appear.insert({linkedList->value, true});
    linkedList = linkedList->next;
    while (linkedList != nullptr) {
        if (appear.count(linkedList->value) == 0) {
            appear.insert({linkedList->value, true});
            result->next = new LinkedList(linkedList->value);
            result = result->next;
        }
        linkedList = linkedList->next;
    }


    return head;
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
    auto input =
          addMany(new LinkedList(1), vector<int>{1, 3, 4, 4, 4, 5, 6, 6});
    auto expected = addMany(new LinkedList(1), vector<int>{3, 4, 5, 6});
    auto actual = removeDuplicatesFromLinkedList(input);
    assert(getNodesInArray(actual) == getNodesInArray(expected));
}

int main()
{
    test_0();
}