#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>

#define testMinMaxPeek(min, max, peekValue, stack)                             \
  {                                                                            \
    assert(stack.getMin() == min);                                             \
    assert(stack.getMax() == max);                                             \
    assert(stack.peek() == peekValue);                                         \
  }

using namespace std;

class Node {
    public:
        int value;
        int minValue = -1;
        int maxValue = -1;
        Node* next = nullptr;
        
        Node (int value) {
            this->value = value;
        }
};

// Feel free to add new properties and methods to the class.
class MinMaxStack {
private:
    Node* head = nullptr;
    int nrElems = 0;

public:
    MinMaxStack (void) {
        this->head = nullptr;
    }

    int peek() {
        if (this->nrElems > 0) {
            return this->head->value;
        }
        return -1;
    }

    int pop() {
        if (this->nrElems > 0) {
            Node* prev_head = this->head;
            int prev_head_value = prev_head->value;

            this->head = prev_head->next;
            this->nrElems--;
            free(prev_head);

            return prev_head_value;
        }

        return -1;
    }

    void push(int number) {
        Node* new_node = new Node(number);
        if (this->nrElems == 0) {
            this->head = new_node;
            this->head->minValue = number;
            this->head->maxValue = number;
        } else {
            Node* prev_head = this->head;
            new_node->next = prev_head;
            this->head = new_node;
            
            // Fix the min Value of the new head
            if (number < prev_head->minValue) {
                this->head->minValue = number;
            } else {
                this->head->minValue = prev_head->minValue;
            }

            // Fix the max value of the new head
            if (number > prev_head->maxValue) {
                this->head->maxValue = number;
            } else {
                this->head->maxValue = prev_head->maxValue;
            }
        }
        this->nrElems++;
    }

    int getMin() {
        if (this->nrElems > 0) {
            return this->head->minValue;
        }
        return -1;
    }

    int getMax() {
        if (this->nrElems > 0) {
            return this->head->maxValue;
        }
        return -1;
    }
};


void test_0(void) {
    std::cout << "Hello!" << std::endl;

    MinMaxStack stack;
    stack.push(5);
    testMinMaxPeek(5, 5, 5, stack);
    stack.push(7);
    testMinMaxPeek(5, 7, 7, stack);
    stack.push(2);
    testMinMaxPeek(2, 7, 2, stack);
    assert(stack.pop() == 2);
    assert(stack.pop() == 7);
    testMinMaxPeek(5, 5, 5, stack);
}

int main()
{
    test_0();
}