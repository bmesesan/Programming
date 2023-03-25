#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;

// 0) A linked list node
class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(void) {
            data = 0;
            left = NULL;
            right = NULL;
        }

        Node(int value) {
            data = value;
            left = NULL;
            right = NULL;
        }
};

class BinaryTree {
    private:
        Node* m_root;
    
    public:
        BinaryTree() {
            m_root = NULL;
        }

        Node* getRoot(void) {
            return m_root;
        }

        // 1) Add new node in binary search tree
        void addNode(int f_data) {
            Node* newNode = new Node(f_data);

            if (m_root == NULL ){
                m_root = newNode;
            } else {
                Node* focusNode = m_root;
                Node* parent;
                while (true) {
                    parent = focusNode;

                    if (f_data < focusNode->data) {
                        focusNode = focusNode->left;
                        if (focusNode == NULL) {
                            parent->left = newNode;
                            return;
                        }
                    } else {
                        focusNode = focusNode->right;
                        if (focusNode == NULL) {
                            parent->right = newNode;
                            return;
                        }
                    }
                }
            }
        }

        // 2.1) Traverse tree in order
        void inOrderTransversal(Node* f_focusNode) {
            if (f_focusNode != NULL) {
                inOrderTransversal(f_focusNode->left);
                std::cout << f_focusNode->data << " ";
                inOrderTransversal(f_focusNode->right);
            }
        }

        // 2.2) Traverse tree pre order
        void preOrderTransversal(Node* f_focusNode) {
            if (f_focusNode != NULL) {
                std::cout << f_focusNode->data << " ";
                preOrderTransversal(f_focusNode->left);
                preOrderTransversal(f_focusNode->right);
            }
        }

        // 2.3) Traverse tree post order
        void postOrderTransversal(Node* f_focusNode) {
            if (f_focusNode != NULL) {
                postOrderTransversal(f_focusNode->left);
                postOrderTransversal(f_focusNode->right);
                std::cout << f_focusNode->data << " ";
            }
        }

        // 3) Level Order Binary Tree Traversal
        static int getHeight(Node* f_node) {
            if (f_node == NULL) {
                return 0;
            } else {
                int lHeight = getHeight(f_node->left);
                int rHeight = getHeight(f_node->right);
                if (lHeight > rHeight) {
                    return lHeight + 1;
                } else {
                    return rHeight + 1;
                }
            }
        }

        // Print current level
        static void printCurrentLevel(Node* f_startNode, int f_level)
        {
            if (f_startNode == NULL) {
                return;
            } else {
                if (f_level == 1) {
                    std::cout << f_startNode->data << " ";
                } else {
                    printCurrentLevel(f_startNode->left, f_level - 1);
                    printCurrentLevel(f_startNode->right, f_level - 1);
                }
            }
        }
        
        // Use BFS to traverse the graph and print the nodes by their level
        void printLevelOrder(void)
        {
            int level = 1;
            int treeHeight = getHeight(m_root);
            std::cout << std::endl; 
            for (int i = 1; i <= treeHeight; i++) {
                printCurrentLevel(m_root, i);
                std::cout << std::endl;
            }
        }
        
        // Create an empty queue q and push root in q.
        // Run While loop until q is not empty. 
        // Initialize temp_node = q.front() and print temp_node->data.
        // Push temp_node’s children i.e. temp_node -> left then temp_node -> right to q
        // Pop front node from q.
        void printLevelOrderV2(void)
        {
            queue<Node*> myQueue;
            myQueue.push(m_root);
            
            while (!myQueue.empty()) {
                Node* tempNode = myQueue.front();
                std::cout << tempNode->data << " ";

                if (tempNode->left) {
                    myQueue.push(tempNode->left);
                }
                if (tempNode->right) {
                    myQueue.push(tempNode->right);
                }
                myQueue.pop();
            }
        }

        // 4) Diameter of a binary tree
        // Approach: The diameter of a tree T is the largest of the following quantities:
        // the diameter of T’s left subtree.
        // the diameter of T’s right subtree.
        // Height of left subtree + height of right subtree + 1
        int getDiameter(Node* f_node)
        {
            if (!f_node) {
                return 0;
            }

            int lHeight = getHeight(f_node->left);
            int rHeight = getHeight(f_node->right);
            int lDiameter = getDiameter(f_node->left);
            int rDiameter = getDiameter(f_node->right);

            return max(max(lDiameter, rDiameter), (lHeight + rHeight + 1));
        }

        // 1) Create an empty stack S.
        // 2) Initialize current node as root
        // 3) Push the current node to S and set current = current->left until current is NULL
        // 4) If current is NULL and stack is not empty then 
        //     a) Pop the top item from stack.
        //     b) Print the popped item, set current = popped_item->right 
        //     c) Go to step 3.
        // 5) If current is NULL and stack is empty then we are done.
        void inOrderTraversalV2(void)
        {
            Node* current = m_root;
            stack<Node*> myStack;

            do {
                while (current) {
                    stack.push(current);
                    current = current->left;
                }
                if (current == NULL )
            } while (!stack.empty());
        }
        
};

void testBuildGraph(void)
{
    BinaryTree *tree = new BinaryTree();
 
    tree->addNode(50);
    tree->addNode(25);
    tree->addNode(75);
    tree->addNode(12);
    tree->addNode(37);
    tree->addNode(43);
    tree->addNode(30);
    
    Node* root = tree->getRoot();
    
    std::cout << "DFS: Inorder traversal: ";
    tree->inOrderTransversal(root);
    std::cout << std::endl;

    std::cout << "DFS: Preorder traversal: "; 
    tree->preOrderTransversal(root);
    std::cout << std::endl;

    std::cout << "DFS: Post traversal: "; 
    tree->postOrderTransversal(root);
    std::cout << std::endl;

    std::cout << "BFS: Print level order: ";
    tree->printLevelOrder();
    std::cout << std::endl;

    std::cout << "BFS: Print level order V2: ";
    tree->printLevelOrderV2();
    std::cout << std::endl;

    int diameter = tree->getDiameter(root);
    std::cout << "Diameter of Binary tree: " << diameter; 
    free(tree);
}

// Driver code
int main()
{
    testBuildGraph();
    return 0;
}