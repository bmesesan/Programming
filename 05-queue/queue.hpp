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
}; // class MyQueue


// 2)  Priority Queue
template <typename T>
class QNodePrio {
    public:
        T data;
        QNodePrio *next;
        int prio;

        QNodePrio(void);
        QNodePrio(T f_data);
        QNodePrio(T f_data, int f_prio);
}; // QNode


template <typename T>
class MyPrioQueue
{
    public:
        QNodePrio<T> *m_front;
        QNodePrio<T> *m_rear;

        MyPrioQueue(void);
        void enqueue(T f_data, int f_prio);
        void dequeue(void);
        QNodePrio<T>* top(void);
        int isEmpty(void);
}; // class MyPrioQueue