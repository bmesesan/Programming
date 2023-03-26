#include <iostream>

using namespace std;

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

// 1) Priority Queue – Linked List Implementation
template <typename T>
QNodePrio<T>::QNodePrio(void) {
    data = 0;
    prio = -1;
    next = NULL;
}

template <typename T>
QNodePrio<T>::QNodePrio(T f_data) {
    data = f_data;
    prio = -1;
    next = NULL;
}

template <typename T>
QNodePrio<T>::QNodePrio(T f_data, int f_prio) {
    data = f_data;
    prio = f_prio;
    next = NULL;
}

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

template <typename T>
MyPrioQueue<T>::MyPrioQueue(void) {
    m_front = NULL;
    m_rear = NULL;
}

template <typename T>
void MyPrioQueue<T>::enqueue(T f_data, int f_prio) {
    QNodePrio<T> *tempNode = new QNodePrio<T>(f_data, f_prio);
    if (m_rear == NULL) {
        m_rear = tempNode;
        m_front = tempNode;
        return;
    }

    if (m_front->prio < f_prio) {
        tempNode->next = m_front;
        m_front = tempNode;
    }
    else {
        QNodePrio<T> *startNode = m_rear;
        while (startNode->next != NULL && startNode->next->prio > tempNode->prio) {
            startNode = startNode->next;
        }
        tempNode->next = startNode->next;
        startNode->next = tempNode;
    }
}

template <typename T>
void MyPrioQueue<T>::dequeue(void) {
    if (m_front == NULL) {
        return;
    }

    QNodePrio<T> *tempNode = m_front;
    m_front = tempNode->next;
    if (m_front == NULL) {
        m_rear = NULL;
    }
    delete(tempNode);
}

template <typename T>
QNodePrio<T>* MyPrioQueue<T>::top(void) {
    return m_front;
}

template <typename T>
int MyPrioQueue<T>::isEmpty(void) {
    return (m_front == NULL);
}