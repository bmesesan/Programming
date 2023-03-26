#include <iostream>

using namespace std;

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

// 0) Queue – Linked List Implementation
template <typename T>
QNode<T>::QNode(void) {
    data = 0;
    next = NULL;
}

template <typename T>
QNode<T>::QNode(T f_data) {
    data = f_data;
    next = NULL;
}


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

template <typename T>
MyQueue<T>::MyQueue(void) {
    m_front = NULL;
    m_rear = NULL;
}

template <typename T>
void MyQueue<T>::enqueue(T f_data) {
    QNode<T> *tempNode = new QNode<T>(f_data);

    if (m_rear == NULL) {
        m_rear = tempNode;
        m_front = tempNode;
    } else {
        m_rear->next = tempNode;
        m_rear = tempNode;
    }
}

template <typename T>
void MyQueue<T>::dequeue(void) {
    if (m_front == NULL) {
        return;
    }

    QNode<T> *tempNode = m_front;
    m_front = tempNode->next;
    if (m_front == NULL) {
        m_rear = NULL;
    }
    delete(tempNode);
}
