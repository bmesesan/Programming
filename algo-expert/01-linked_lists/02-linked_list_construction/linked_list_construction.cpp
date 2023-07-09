#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

class Node {
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void setHead(Node *node) {
        this->head = node;
        node->prev = nullptr;
    }

    void setTail(Node *node) {
        this->tail = node;
        node->next = nullptr;
    }

    void insertBefore(Node *node, Node *nodeToInsert) {
        Node* cursor = this->head;
        while (cursor != node) {
            cursor = cursor->next;
        }
        nodeToInsert->prev = cursor->prev;
        cursor->prev = nodeToInsert;
        nodeToInsert->next = cursor;
        
        if (node = this->head) {
            setHead(nodeToInsert);
        }
    }

    void insertAfter(Node *node, Node *nodeToInsert) {
        // Write your code here.
        Node* cursor = this->tail;
        while (cursor != node) {
            cursor = cursor->prev;
        }
        nodeToInsert->next = cursor->next;
        cursor->next = nodeToInsert;
        nodeToInsert->prev = cursor;

        if (node = this->tail) {
            setTail(nodeToInsert);
        }
    }

    void insertAtPosition(int position, Node *nodeToInsert) {
        // Write your code here.
        Node* cursor = this->head;
        int cnt = 1;
        
        while (cnt < position && cursor != nullptr) {
            cursor = cursor->next;
            cnt++;
        }

        if (cursor != nullptr) {
            nodeToInsert->prev = cursor->prev;
            nodeToInsert->next = cursor;
            cursor->prev = nodeToInsert;
        } else {
            nodeToInsert->prev = this->tail;
            nodeToInsert->next = nullptr;
            setTail(nodeToInsert);
        }
        if (position == 1) {
            setHead(nodeToInsert);
        }
    }

    void removeNodesWithValue(int value) {
        Node* cursor = this->head;
        Node* nodeToRemove;
        while (cursor != nullptr) {
            if (cursor->value == value) {
                nodeToRemove = cursor;
                cursor = cursor->next;
                remove(nodeToRemove);
            } else {
                cursor = cursor->next;
            }
        }
    }

    void remove(Node *node) {
        if (node == this->head) {
            setHead(node->next);
        } else if (node == this->tail) {
            setTail(node->prev);
        } else {
            Node* tmp_next = node->next;
            Node* tmp_prev = node->prev;
            tmp_prev->next = tmp_next;
            tmp_next->prev = tmp_prev;
        }

        free(node);
    }

    bool containsNodeWithValue(int value) {
        Node* cursor = this->head;

        while (cursor != nullptr) {
            if (cursor->value == value) {
                return true;
            }
        }
        
        return false;
    }
};

vector<int> getNodeValuesHeadToTail(DoublyLinkedList linkedList) {
    vector<int> values = {};
    Node *node = linkedList.head;
    while (node != nullptr) {
        values.push_back(node->value);
        node = node->next;
    }
    return values;
}

vector<int> getNodeValuesTailToHead(DoublyLinkedList linkedList) {
    vector<int> values = {};
    Node *node = linkedList.tail;
    while (node != nullptr) {
        values.push_back(node->value);
        node = node->prev;
    }
    return values;
}

void bindNodes(Node *nodeOne, Node *nodeTwo) {
    nodeOne->next = nodeTwo;
    nodeTwo->prev = nodeOne;
}


void test_0(void) {
    ;
}

int main()
{
    test_0();
}