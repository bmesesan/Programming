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

        Node(int value) {
            data = value;
            next = NULL;
        }
};

class LinkedList
{
    private:
        Node *m_head;
        int m_len = 0;
    
    public:
        LinkedList(void)
        {
            m_head = NULL;
        }

        LinkedList(Node *f_head)
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

        Node* getNodeAtIdx(int f_idx) {
            Node* ptr = m_head;
            for (int i = 0; i < f_idx; i++) {
                ptr = ptr->next;
            }
            return ptr;
        }

        // 1) Display elements of linked list
        void display(void)
        {
            Node *curr = m_head;
            while(curr != NULL) {
                printf("%d ", curr->data);
                curr = curr->next;
            }
        }

        // 2.1) Insert element at the begining of the list
        void insertAtHead(int new_data)
        {
            // Allocate memory for the new node
            Node *new_node = new Node(new_data);

            // Set the next reference of the new node as the head
            new_node->next = m_head;

            // Set the new node as head
            m_head = new_node;

            m_len += 1;
        }

        // 2.2) Insert element after a known element in the list
        void insertAfter(Node* prev_node, int new_data)
        {
            // Check if the given previous node is NULL or not
            if (prev_node == NULL) {
                printf("Prev node can not be NULL!\n");
                return;
            }

            // Allocate a new node
            Node *new_node = new Node(new_data);

            // Make the next of new node as the next of previous node
            new_node->next = prev_node->next;

            // Finally, move the next of the previous node as a new node
            prev_node->next = new_node;

            m_len += 1;
        }

        // 2.3) Add an element at the end of the list
        void append(int new_data)
        {
            // Allocate a new node
            Node *new_node = (Node*)malloc(sizeof(Node));
            Node *last = m_head;

            // Increment the list size
            m_len += 1;

            // 2. Put in the data
            new_node->data = new_data;

            // 3. This new node is going to be the last node, so make next of it as NULL
            new_node->next = NULL;

            // 4. If the Linked List is empty, then make the new node as head
            if (m_head == NULL) { 
                m_head = new_node; 
                return; 
            }

            // 5. Else find the last node
            while (last->next != NULL){
                last = last->next;
            }

            // Put the new node at the end of the list
            last->next = new_node;
        }

        // 3.1) Delete from Beginning
        void deleteFirst(void)
        {
            Node *temp = m_head;

            if(m_len == 0) {
                printf("List is empty!\n");
                return;
            }

            m_head = m_head->next;
            free(temp);

            m_len -= 1;
        }

        // 3.2) Delete from End
        void deleteLast(void)
        {
            Node *end = m_head;
            Node *prev = NULL;

            if(m_len == 0) {
                printf("List is empty!\n");
                return;
            }

            // Set the last node and the previous to last node
            while(end->next) {
                prev = end;
                end = end->next;
            }
            // Set the previous to last to be the end node
            prev->next = NULL;

            // Free unused memory
            free(end);

            m_len -= 1;
        }

        // 3.2) Delete from a given position
        void deletePosition(int f_position)
        {
            Node *node = m_head;
            Node *prev = NULL;

            if(m_len == 0) {
                printf("List is empty!\n");
                return;
            }

            if(f_position >= m_len) {
                printf("Position to delete: %d is greater than the length of list: %d\n", f_position, m_len);
                return;
            }

            if (f_position == 0) {
                deleteFirst();
                return;
            }

            for(int i = 0; i < f_position; i++) {
                prev = node;
                node = node->next;
            }

            prev->next = node->next;
            free(node);
            m_len -= 1;
        }

        void swap(Node** a, Node** b)
        {
            Node *aux = *a;
            *a = *b;
            *b = aux;
        }

        // 4.1) Swap 2 keys, given that each node has a unique key
        void swapNodes(int f_key_1, int f_key_2)
        {
            Node **headref = &m_head;
            Node **n1 = NULL;
            Node **n2 = NULL;

            while(*headref) {
                if ((*headref)->data == f_key_1) {
                    n1 = headref;
                }
                else if ((*headref)->data == f_key_2) {
                    n2 = headref;
                }
                headref = &((*headref)->next);
            }

            if (n1 && n2) {
                swap(n1, n2);
                swap(&(*n1)->next, &(*n2)->next);
            }
        }

        // 4.2) Reverse a linked list
        void reverse(void)
        {
            Node *curr = m_head;
            Node *next = NULL;
            Node *prev = NULL;
            while (curr) {
                // Store next
                next = curr->next;
                // Reverse current node's pointer  
                curr->next = prev;
                // Move pointers one position ahead.
                prev = curr;
                curr = next;
            }
            m_head = prev;
        }

        // 7) Reverse a Linked List in groups of given size
        void reverseSubList(int f_size)
        {
            int count = 0;
            Node *headRef = m_head;
            Node *curr = NULL;
            Node *next = NULL;
            Node *prev = NULL;

            // Return if the size of the sublist is smaller or equal to 1
            if (f_size <= 1) {
                return;
            }

            // Start withe the head iterate through the sublist
            curr = headRef;
            while (count < f_size && curr != NULL) {
                // Each current node will set the next one as the previous node
                next = curr->next;
                curr->next = prev;
                // The new previous node will be the current node
                // The new current node will be the next
                // Increment the counter
                prev = curr;
                curr = next;
                count++;
            }

            // The last node of the reversed sub-list will be the start node == headRef
            // When we are finished, the last node of the reversed sub-list will point to NULL
            // Make the last node in the sublist point to the next node of the iteration
            // Change the head ref to be the last node which changed its next reference
            headRef->next = next;
            m_head = prev;
        }

        // 8.1) Detect a loop within a linked list
        // Return true if a loop is detected in the linked list
        bool detectLoop(void)
        {
            std::unordered_set<Node*> my_set;
            Node* curr = m_head;
            
            while(curr != NULL) {
                if(my_set.find(curr) != my_set.end()) {
                    return true;
                }
                my_set.insert(curr);
                curr = curr->next;
            }

            return false;
        }

        // 8.2) Detect loop in a linked list using Floyd’s Cycle-Finding Algorithm
        // Traverse linked list using two pointers.
        // Move one pointer(slow_p) by one and another pointer(fast_p) by two.
        // If these pointers meet at the same node then there is a loop.
        // If pointers do not meet then the linked list doesn’t have a loop.
        bool detectLoopFloyd(void)
        {
            Node* fast = m_head;
            Node* slow = m_head;

            while(fast != NULL) {
                fast = fast->next;
                if (fast == slow) {
                    return true;
                }
                if (fast != NULL) {
                    fast = fast->next;
                    slow = slow->next;
                    if (fast == slow) {
                        return true;
                    }
                }
            }

            return false;
        }
        
        // 8.3) Function to remove loop.
        // loop_node --> Pointer to one of the loop nodes
        void removeLoop(Node* f_loop_node)
        {
            Node* ptr1 = f_loop_node;
            Node* ptr2 = f_loop_node;

            // Count the number of nodes in the loop
            unsigned int k = 1, i;
            while (ptr1->next != ptr2) {
                ptr1 = ptr1->next;
                k++;
            }

            // Set pointer 1 to the head
            ptr1 = m_head;

            // Set ptr2 K nodes after the head
            ptr2 = m_head;
            for(i = 0; i < k; i++) {
                ptr2 = ptr2 -> next;
            }

            // In order to find the start of the loop, move ptr1 and ptr2 until they are equal
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }

            // Get a pointer to the last node of the loop
            while (ptr2->next != ptr1) {
                ptr2 = ptr2->next;
            }

            // Set the next pointer of the last loop node to NULL
            ptr2->next = NULL;

        }

        // 8.3) Detect the loop usign Floyd algorithm and remove it
        bool detectAndRemoveLoop(void)
        {
            Node* slow = m_head;
            Node* fast = m_head;

            while (fast != NULL) {
                fast = fast->next;
                if (fast == slow) {
                    removeLoop(slow);
                    return true;
                }
                if (fast != NULL) {
                    fast = fast->next;
                    slow = slow->next;
                    if (fast == slow) {
                        removeLoop(slow);
                        return true;
                    }
                }
                
            }

            return false;
        }
};

// 5) Sorted mergew of two linked lists
LinkedList* sortedMerge(LinkedList f_l1, LinkedList f_l2)
{
    LinkedList *new_list = new LinkedList();

    Node *node_1 = f_l1.getHead();
    Node *node_2 = f_l2.getHead();

    while(node_1 || node_2) {
        if (node_1 && node_2) {
            if (node_1->data < node_2->data) {
                new_list->append(node_1->data);
                node_1 = node_1->next;
            } else {
                new_list->append(node_2->data);
                node_2 = node_2->next;
            }
        } else {
            if (node_1) {
                new_list->append(node_1->data);
                node_1 = node_1->next;
            } else if (node_2) {
                new_list->append(node_2->data);
                node_2 = node_2->next;
            }
        }
    }

    return new_list;
}

// 6) Utility funciton: splits the source list into front and back lists
void frontBackSplit(LinkedList* f_sourceList, LinkedList* f_frontList, LinkedList* f_backList)
{
    Node* sourceHead = f_sourceList->getHead();
    Node* fast;
    Node* slow;
    slow = sourceHead;
    fast = sourceHead->next;
 
    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    // 'slow' is before the midpoint in the list, so split it in two at that point.
    f_frontList->setHead(sourceHead);
    f_backList->setHead(slow->next);
    slow->next = NULL;
}

// 6) Merge sort of a linked list
void mergeSort(LinkedList **f_list)
{
    Node *headRef = (*f_list)->getHead();
    LinkedList *frontList = new LinkedList();
    LinkedList *backList = new LinkedList();

    // 1) Test if the list is empty or if the length of the list is 1
    if (!headRef || !headRef->next) {
        return;
    }

    // 2) Split the source list into front and back lists
    frontBackSplit(*f_list, frontList, backList);

    // 3) Recursively sort the sublists
    mergeSort(&frontList);
    mergeSort(&backList);

    // 4) Merge the two sorted lists together
    *f_list = sortedMerge(*frontList, *backList);
    free(frontList);
    free(backList);
}

// Driver code
int main()
{
    // Start with the empty list
    LinkedList *my_list_1 = new LinkedList();

    my_list_1->append(1);
    my_list_1->append(2);
    my_list_1->append(3);
    my_list_1->append(4);
    my_list_1->append(5);
    my_list_1->append(6);
    my_list_1->append(7);

    Node* ptr = my_list_1->getNodeAtIdx(6);
    ptr->next = my_list_1->getNodeAtIdx(3);

    
    Node* head = my_list_1->getHead();
    // head->next->next->next->next = head;
    if(my_list_1->detectLoop())
        std::cout << "Loop Found" << std::endl;
    else
        std::cout << "No Loop" << std::endl;
    
    if(my_list_1->detectLoopFloyd())
        std::cout << "Floyd: Loop Found" << std::endl;
    else
        std::cout << "Floyd: No Loop" << std::endl;

    my_list_1->detectAndRemoveLoop();
    std::cout << "Created Linked list is: " << std::endl;
    my_list_1->display();
    std::cout << std::endl;

    free(my_list_1);
    return 0;
}