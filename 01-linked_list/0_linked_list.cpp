#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 0) A linked list node
class Node
{
    public:
        int data;
        Node *next;
};

// 1) Display elements of linked list
void display(Node *head)
{
   Node *curr = head;
   while(curr != NULL) {
       printf("%d ", curr->data);
       curr = curr->next;
   }
}

// 2.1) Insert element at the begining of the list
void push(Node** head_ref, int new_data)
{
    // Allocate memory for the new node
    Node *new_node = (Node*)malloc(sizeof(Node));
    
    // Set the data of the new node
    new_node->data = new_data;

    // Set the next reference of the new node as the head
    new_node->next = *head_ref;

    // Set the new node as head
    *head_ref = new_node;
}

// 2.2) Insert element after a known element in the list
void insertAfter(Node* prev_node, int new_data)
{
    // Check if the given previous node is NULL or not
    if (prev_node == NULL){
        printf("Prev node can not be NULL!\n");
        return;
    }

    // Allocate a new node
    Node *new_node = (Node*)malloc(sizeof(Node));

    // Assign the data to the new node
    new_node->data = new_data;

    // Make the next of new node as the next of previous node
    new_node->next = prev_node->next;

    // Finally, move the next of the previous node as a new node
    prev_node->next = new_node;
}

// Add an element at the end of the list
void append(Node** head_ref, int new_data)
{
    // Allocate a new node
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *last = *head_ref;

    // 2. Put in the data
    new_node->data = new_data;

    // 3. This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;

    // 4. If the Linked List is empty, then make the new node as head
    if (*head_ref == NULL){ 
        *head_ref = new_node; 
        return; 
    }

    // 5. Else find the last node
    while (last->next != NULL){
        last = last->next;
    }

    // Put the new node at the end of the list
    last->next = new_node;
}

// Driver code
int main()
{
   
    // Start with the empty list
    Node* head = NULL;
     
    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);
     
    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);
     
    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);
     
    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);
     
    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);
     
    cout<<"Created Linked list is: ";
    display(head);
     
    return 0;
}