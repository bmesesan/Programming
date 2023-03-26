#include <iostream>
#include "headers/queue.hpp"
#include "headers/prio_queue.hpp"
#include "headers/dequeue.hpp"

using namespace std;

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

void dequeueTest(void) {
    DQueue<int> myDQueue;

    // 1) Test Queue functionality
    myDQueue.push_front(1);
    myDQueue.push_front(2);
    myDQueue.push_front(3);

    while (!myDQueue.empty()) {
        int frontVal = myDQueue.back();
        cout << " " << frontVal;
        myDQueue.pop_back();
    }
    std::cout << std::endl;

    // 1) Test Stack functionality
    myDQueue.push_front(1);
    myDQueue.push_front(2);
    myDQueue.push_front(3);

    while (!myDQueue.empty()) {
        int frontVal = myDQueue.front();
        cout << " " << frontVal;
        myDQueue.pop_front();
    }
    std::cout << std::endl;
}


// Driver code
int main()
{
    dequeueTest();

    return 0;
}