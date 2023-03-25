#include <iostream>

// 1) Implement a Queue using a Linked List
// 0) A queue node
template <typename T>
class QNode
{
    public:
        T data;
        QNode *next;

        QNode(void);
        QNode(T f_data);
}; // QNode

template <typename T>
class MyQueue
{
    public:
        QNode<T> *m_front;
        QNode<T> *m_rear;

        MyQueue(void);
        void enqueue(T f_data);
        void dequeue(void);
}; // class DoublyLinkedList