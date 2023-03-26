#include <iostream>

using namespace std;

// 3) Deque using doubly linked list
// 0) A linked list node
template <typename T>
class DQNode {
    public:
        T data;
        DQNode *next;
        DQNode *prev;

        DQNode(void) {
            data = 0;
            next = NULL;
            prev = NULL;
        }

        DQNode(T f_data) {
            data = f_data;
            next = NULL;
            prev = NULL;
        }
}; // class DQNode

template <typename T>
class DQueue {
    private:
        DQNode<T> *m_front;
        DQNode<T> *m_back;
        uint32_t m_size;
    public:
        DQueue(void) {
            m_front = NULL;
            m_back = NULL;
            m_size = 0;
        }

        void push_front(T f_data) {
            DQNode<T> *tempNode = new DQNode<T>(f_data);

            if (m_size == 0) {
                m_front = tempNode;
                m_back = tempNode;
                m_size++;
            } else {
                // Set the prev/next pointers
                tempNode->prev = m_front->prev;
                m_front->prev = tempNode;
                tempNode->next = m_front;
                // Set the front node
                m_front = tempNode;
                // Increment size
                m_size++;
            }
        }

        void push_back(T f_data) {
            DQNode<T> *tempNode = new DQNode<T>(f_data);

            if (m_size == 0) {
                m_front = tempNode;
                m_back = tempNode;
                m_size++;
            } else {
                // Set the prev/next pointers
                tempNode->next = back->next;
                m_back->next = tempNode;
                tempNode->prev = m_back;
                // Set the back node
                m_back = tempNode;
                // Increment size
                m_size++;
            }
        }

        void pop_front(void) {
            DQNode<T> *tempNode = m_front;

            if (m_size >= 1) {
                m_front->prev = NULL;
                m_front = tempNode->next;
            } else {
                std::cout << "The DQueue is empty. Cannot pop front any elements!";
                return;
            }
            delete(tempNode);
            m_size--;
        }

        void pop_back(void) {
            DQNode<T> *tempNode = m_back;

            if (m_size >= 1) {
                m_back->next = NULL;
                m_back = tempNode->prev;
            } else {
                std::cout << "The DQueue is empty. Cannot pop back any elements!";
                return;
            }
            delete(tempNode);
            m_size--;
        }

        T front(void) {
            return m_front->data;
        }

        T back(void) {
            return m_back->data;
        }

        int empty(void) {
            return m_size == 0;
        }

        int size(void) {
            return m_size;
        }

}; // class DQueue