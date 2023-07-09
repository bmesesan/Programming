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

LinkedList* getKthNode(LinkedList* linkedList, int k) {
    LinkedList* cursor = linkedList;
    LinkedList* cursorK = linkedList;
    int cnt = 1;

    while (cursor->next != nullptr) {
        if (cnt >= k) {
            cursorK = cursorK->next;
        }
        
        cursor = cursor->next;
        cnt++;
    }

    if (cnt < k) {
        return nullptr;
    }

    return cursorK;
}


LinkedList* mergingLinkedLists(LinkedList* linkedListOne, LinkedList* linkedListTwo) {
    int cnt = 1;

    LinkedList* nodeOne = getKthNode(linkedListOne, cnt);
    LinkedList* nodeTwo = getKthNode(linkedListTwo, cnt);

    if (nodeOne != nodeTwo) {
        return nullptr;
    }

    LinkedList* mergeNode = nodeOne;

    while (nodeOne == nodeTwo && nodeOne != nullptr && nodeTwo != nullptr) {
        mergeNode = nodeOne;

        nodeOne = getKthNode(linkedListOne, cnt);
        nodeTwo = getKthNode(linkedListTwo, cnt);
        cnt++;
    }

    return mergeNode;
}


void test_0(void) {
    LinkedList* l1 = new LinkedList(1);
    l1->next = new LinkedList(2);
    LinkedList* l2 = new LinkedList(3);
    l2->next = l1->next;
    LinkedList* expected = l1->next;
    auto actual = mergingLinkedLists(l1, l2);
    assert(expected == actual);
}

int main()
{
    test_0();
}