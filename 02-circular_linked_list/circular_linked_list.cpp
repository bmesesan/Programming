#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 0) A linked list node
class Node
{
    public:
        int data;
        Node *next;

        Node(void) {
            data = 0;
            next = NULL;
        }

        Node(int value) {
            data = value;
            next = NULL;
        }
};
