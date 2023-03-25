#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "queue.hpp"

using namespace std;

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

void queueTest(void) {
    MyQueue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout << "Queue Front : " << ((q.m_front != NULL) ? (q.m_front)->data : -1)<< endl;
    cout << "Queue Rear : " << ((q.m_rear != NULL) ? (q.m_rear)->data : -1);
}


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

void prioQueueTest(void) {
    // Create a Priority Queue
    // 7->4->5->6
    MyPrioQueue<int> myPrioQueue;
    myPrioQueue.enqueue(4, 1);
    myPrioQueue.enqueue(5, 2);
    myPrioQueue.enqueue(6, 3);
    myPrioQueue.enqueue(7, 0);
 
    while (!myPrioQueue.isEmpty()) {
        QNodePrio<int> *frontNode = myPrioQueue.top(); 
        cout << " " << frontNode->data;
        myPrioQueue.dequeue();
    }
}


// Driver code
int main()
{
    prioQueueTest();

    return 0;
}