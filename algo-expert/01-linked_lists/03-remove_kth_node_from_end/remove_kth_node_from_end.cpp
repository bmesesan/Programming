#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
    // Write your code here.
    LinkedList *cursor = head;
    LinkedList *k_cursor = head;
    LinkedList *k_cursor_prev = nullptr;
    int cnt = 1;

    while (cursor->next != nullptr) {
        if (cnt >= k) {
            k_cursor_prev = k_cursor;
            k_cursor = k_cursor->next;
        }
        cursor = cursor->next;
        cnt++;
    }

    if (k_cursor_prev == nullptr) {
        // This means that the head must be mutated in place
        LinkedList* k_cursor_next = k_cursor->next;
        if (k_cursor_next != nullptr) {
            k_cursor->value = k_cursor_next->value;
            k_cursor->next = k_cursor_next->next;
        } else {
            k_cursor = nullptr;
        }
    } else {
        k_cursor_prev->next = k_cursor->next;
    }

}


void test_0(void) {

}

int main()
{
    std::cout << "Hello!" << std::endl;
    test_0();
}