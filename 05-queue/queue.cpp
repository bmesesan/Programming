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


// Driver code
int main()
{
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

    return 0;
}