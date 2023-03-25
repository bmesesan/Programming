#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 0) A linked list node
class Node
{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(void) {
            data = 0;
            next = NULL;
            prev = NULL;
        }

        Node(int value) {
            data = value;
            next = NULL;
            prev = NULL;
        }
};


class DoublyLinkedList
{
    private:
        Node *m_head;
        int m_len = 0;
    
    public:
        DoublyLinkedList(void)
        {
            m_head = NULL;
        }

        DoublyLinkedList(Node *f_head)
        {
            m_head = f_head;
        }

        void setHead(Node *f_head)
        {
            m_head = f_head;
        }

        Node* getHead(void)
        {
            return m_head;   
        }

        Node* getLast(void)
        {
            Node* curr = m_head;
            while (curr && curr->next)
            {
                curr = curr->next;
            }
            return curr;
        }

        int getNodeIdx(Node* f_node)
        {
            Node* current = m_head;
            int idx = 0;
            while (current != f_node)
            {
                current = current->next;
                idx++;
            }
            return idx;
        }

        Node* getNodeAtIdx(int f_idx) {
            Node* ptr = m_head;
            for (int i = 0; i < f_idx; i++) {
                ptr = ptr->next;
            }
            return ptr;
        }

        // 1) Display elements of a doubly linked list
        void display(void)
        {
            Node *curr = m_head;
            while(curr != NULL) {
                printf("%d ", curr->data);
                curr = curr->next;
            }
        }

        // 2.1) Insert a new element at the Head of the DLL
        void push(int f_data)
        {
            Node* myNode = new Node(f_data);
            // Set the next ptr as the head ref
            // Prev is set to NULL
            myNode->next = m_head;
            myNode->prev = NULL;

            // If the head exists then set its prev as the new node
            if (m_head != NULL) {
                m_head->prev = myNode;
            }
            
            // Set the new head
            m_head = myNode;
        }

        // 2.2) Given a node as prev_node, insert a new node after the given node 
        void insertAfter(Node* f_prevNode, int f_data)
        {
            if (f_prevNode == NULL) {
                cout << "The given previous node cannot be NULL" << std::endl;
                return;
            }

            Node* myNode = new Node(f_data);
            Node* tempNext = f_prevNode->next;

            // Set prev and next for the new node
            myNode->prev = f_prevNode;
            myNode->next = tempNext;

            // Set the next for the old prev node
            f_prevNode->next = myNode;

            // Set the prev for the old next node
            tempNext->prev = myNode;
        }

        // 2.3) Append a new node in the DLL 
        void append(int f_data)
        {
            Node* temp = m_head;
            Node* myNode = new Node(f_data);

            if (m_head == NULL) {
                m_head = myNode;
                return;
            }

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = myNode;
            myNode->prev = temp;
        }

        // 2.3) Given a node as next_node, insert a new node after the given node 
        void insertBefore(Node* f_nextNode, int f_data)
        {
            if (f_nextNode == NULL) {
                cout << "The given next node cannot be NULL" << std::endl;
                return;
            }

            Node* myNode = new Node(f_data);
            Node* tempPrev = f_nextNode->prev;

            myNode->next = f_nextNode;
            myNode->prev = tempPrev;

            if (tempPrev == NULL) {
                m_head = myNode;
                return;
            }
            tempPrev->next = myNode;
            f_nextNode->prev = myNode;
        }

        // 3) Delete a node
        void deleteNode(Node* f_node)
        {
            if (f_node == NULL) {
                std::cout << "Cannot delete Null node!" << std::endl;
                return;
            }
            Node* prev = f_node->prev;
            Node* next = f_node->next;
            
            // Test for head
            if (m_head == f_node) {
                m_head = next;
            }

            // Handle prev
            if (prev != NULL) {
                prev->next = next;
            }
            
            // Handle next
            if (next != NULL){
                next->prev = prev;
            }
            
            // free memory
            free(f_node);
        }

        // 4) reverse DLL
        // Traverse the linked list using a pointer
        // Swap the prev and next pointers for all nodes
        // At last, change the head pointer of the doubly linked list
        void reverse(void)
        {
            Node* temp = m_head;

            while (temp->next != NULL) {
                Node* nextAux = temp->next;
                Node* prevAux = temp->prev;

                temp->prev = nextAux;
                temp->next = prevAux;

                temp = nextAux;
            }

            // Set the new head
            temp->next = temp->prev;
            temp->prev = NULL;
            m_head = temp;
        }

        // 5) Quicksort for DLL
        // We need the quicksort function and the partition function
        void swapValues(int* f_v1, int* f_v2)
        {
            int temp = *f_v1;
            *f_v1 = *f_v2;
            *f_v2 = temp;
        }

        Node* partition(Node* f_low, Node* f_high)
        {
            int pivot = f_high->data;
            Node* i = f_low->prev;

            for (Node* j = f_low; j != f_high; j = j->next) {
                if(j->data < pivot) {
                    i = (i == NULL) ? f_low : i->next;
                    swapValues(&(i->data), &(j->data));
                }
            }
            i = i->next;
            swapValues(&(i->data), &(f_high->data));
            return i;
        }

        void callQS(Node* f_low, Node* f_high)
        {
            if (!f_high || f_low == f_high || f_low == f_high->next) {
                return;
            }

            Node* p = partition(f_low, f_high);
            callQS(p->next, f_high);
            callQS(f_low, p->prev);
        }

        void quicksort(void)
        {
            callQS(m_head, getLast());
        }

        void frontBackSplit(DoublyLinkedList* f_frontList, DoublyLinkedList* f_backList)
        {
            Node* slow = m_head;
            Node* fast = slow->next;
            while (fast != NULL) {
                fast = fast->next;
                if (fast != NULL) {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            f_frontList->setHead(m_head);
            f_backList->setHead(slow->next);
            slow->next->prev = NULL;
            slow->next = NULL;
        }
};

// 6) Merge sort for DLL
// Merge two already sorted DLLs
DoublyLinkedList* sortedMerge(DoublyLinkedList* f_list_1, DoublyLinkedList* f_list_2)
{
    DoublyLinkedList* res = new DoublyLinkedList();

    Node* cnt_1 = f_list_1->getHead();
    Node* cnt_2 = f_list_2->getHead();
    while (cnt_1 || cnt_2) {
        if (!cnt_1 || !cnt_2) {
            if (!cnt_1) {
                res->append(cnt_2->data);
                cnt_2 = cnt_2->next;
            }
            if (!cnt_2) {
                res->append(cnt_1->data);
                cnt_1 = cnt_1->next;
            }
        }
        else {
            if (cnt_1->data < cnt_2->data){
                res->append(cnt_1->data);
                cnt_1 = cnt_1->next;
            } else {
                res->append(cnt_2->data);
                cnt_2 = cnt_2->next;
            }
        }
    }

    return res;
}

void mergeSort(DoublyLinkedList** f_dll)
{
    DoublyLinkedList* frontList = new DoublyLinkedList();
    DoublyLinkedList* backList = new DoublyLinkedList();
    Node* headRed = (*f_dll)->getHead();

    if (!headRed || !headRed->next) {
        return;
    }

    (*f_dll)->frontBackSplit(frontList, backList);
    mergeSort(&frontList);
    mergeSort(&backList);

    *f_dll = sortedMerge(frontList, backList);
    free(frontList);
    free(backList);
}


// Driver code
int main()
{
    DoublyLinkedList* dll = new DoublyLinkedList();

    dll->append(30);
    dll->append(20);
    dll->append(3);
    dll->append(5);
    dll->append(4);
 
    cout << "Created DLL is: ";
    dll->display();
    cout << std::endl;

    // dll->quicksort();
    mergeSort(&dll);

    cout << "Sorted DLL is: ";
    dll->display();
    cout << std::endl;

    return 0;
}