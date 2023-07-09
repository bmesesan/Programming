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

    Node(int value) {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
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
        Node* prev_ptr = node->prev;
        Node* next_ptr = node->next;
        if (prev_ptr != nullptr) {
            prev_ptr->next = next_ptr;
            if (this->tail == node) {
                this->tail = prev_ptr;
            }
        }
        if (next_ptr != nullptr) {
            next_ptr->prev = prev_ptr;
        }

        node->prev = nullptr;
        node->next = this->head;
        if (this->head != nullptr) {
            this->head->prev = node;
        }
        this->head = node;

        if (this->tail == nullptr && this->head->next == nullptr){
            this->tail = this->head;
        }
    }

    void setTail(Node *node) {
        Node* prev_ptr = node->prev;
        Node* next_ptr = node->next;
        if (prev_ptr != nullptr) {
            prev_ptr->next = next_ptr;
        }
        if (next_ptr != nullptr) {
            next_ptr->prev = prev_ptr;
            if (this->head == node) {
                this->head = next_ptr;
            }
        }

        node->prev = this->tail;
        node->next = nullptr;
        if (this->tail != nullptr) {
            this->tail->next = node;
        }
        this->tail = node;

        if (this->head == nullptr && this->tail->prev == nullptr){
            this->head = this->tail;
        }
    }

    void insertBefore(Node *node, Node *nodeToInsert) {
        Node *prev_ptr = node->prev;
        Node *old_prev = nodeToInsert->prev;
        Node *old_next = nodeToInsert->next;

        // Handle the case when nodeToInsert is already in the Linked List
        if (old_prev != nullptr) {
            old_prev->next = old_next;
            if (nodeToInsert == this->tail) {
                this->tail = old_prev;
            }
        }

        if (old_next != nullptr) {
            old_next->prev = old_prev;
            if (nodeToInsert == this->head) {
                this->head = old_next;
            }
        }
        
        if (prev_ptr != nullptr) {
            prev_ptr->next = nodeToInsert;
        }

        if (node != nullptr) {
            node->prev = nodeToInsert;
        }

        nodeToInsert->prev = prev_ptr;
        nodeToInsert->next = node;

        if (node == this->head) {
            this->head = nodeToInsert;
            this->head->prev = nullptr;
        }
    }

    void insertAfter(Node *node, Node *nodeToInsert) {
        Node *next_ptr = node->next;
        Node *old_prev = nodeToInsert->prev;
        Node *old_next = nodeToInsert->next;

        // Handle the case when nodeToInsert is already in the Linked List
        if (old_prev != nullptr) {
            old_prev->next = old_next;
            if (nodeToInsert == this->tail) {
                this->tail = old_prev;
            }
        }

        if (old_next != nullptr) {
            old_next->prev = old_prev;
            if (nodeToInsert == this->head) {
                this->head = old_next;
            }
        }

        if (node != nullptr) {
            node->next = nodeToInsert;
        }

        if (next_ptr != nullptr) {
            next_ptr->prev = nodeToInsert;
        }

        nodeToInsert->prev = node;
        nodeToInsert->next = next_ptr;

        if (node == this->tail) {
            this->tail = nodeToInsert;
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
            insertBefore(cursor, nodeToInsert);
        } else {
            setTail(nodeToInsert);
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
        Node* old_prev = node->prev;
        Node* old_next = node->next;

        if (old_prev != nullptr) {
            old_prev->next = old_next;
        }

        if (old_next != nullptr) {
            old_next->prev = old_prev;
        }

        if (node == this->head) {
            this->head = old_next;
        }

        if (node == this->tail) {
            this->tail = old_prev;
        }
    }

    bool containsNodeWithValue(int value) {
        Node* cursor = this->head;

        while (cursor != nullptr) {
            if (cursor->value == value) {
                return true;
            }
            cursor = cursor->next;
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
    DoublyLinkedList linkedList;
    Node one(1);
    Node two(2);
    Node three(3);
    Node four(4);
    Node five(5);
    Node six(6);
    Node seven(7);
    
    linkedList.setHead(&one);
    linkedList.insertAfter(&one, &two);
    linkedList.insertAfter(&two, &three);
    linkedList.insertAfter(&three, &four);
    linkedList.insertAfter(&four, &five);
    linkedList.insertAfter(&five, &six);
    linkedList.insertAfter(&six, &seven);

    linkedList.insertAtPosition(1, &one);
    linkedList.insertAtPosition(2, &one);
}

int main()
{
    std::cout << "Hello!" << std::endl;
    test_0();
}