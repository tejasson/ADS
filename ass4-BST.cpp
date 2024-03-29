// Write a menu driven C++ program to construct a binary search tree by inserting the values in the order give, considering at the beginning with an empty binary search tree, After constructing a binary tree- 
// i. Insert new node, 
// ii. Find number of nodes in longest path from newNode, 
// iii. Minimum value value found in the tree 
// iv. Search a value 
// v. Print values in ascending and descending order

#include<iostream>
#include<stack>
using namespace std;

class Node {
    public:
        int value;
        Node *right;
        Node *left;
};

class BST {
    stack<Node*> stk;
    Node *root = new Node;
    Node *temp;
    public:
        void getRoot(int data) {
            root->value = data;
            cout << "root is set to " << data << endl;
        }

        void insert(int data) {
            temp = root;
            Node *newNode = new Node;
            while (true) {
                if (data < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        newNode->value = data;
                        break;
                    }
                    else {
                        temp = temp->left;
                    }
                }
                else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        newNode->value = data;
                        break;
                    }
                    else {
                        temp = temp->right;
                    }
                }
            }
        }

        void minValue() {
            temp = root;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            cout << "Minimum value: " << temp->value << endl;
        }

        void inorder() {
            Node *poppedNode;
            stk.push(root);
            while(!stk.empty()) {
                poppedNode = stk.top();
                stk.pop();
                cout<<poppedNode->value;
                
                stk.push(poppedNode->right);
                stk.push(poppedNode->left);
            }
        }
};

int main() {
    BST obj;
    obj.getRoot(38);

    obj.insert(45);
    obj.insert(36);
    obj.insert(67);

    obj.minValue();

    obj.inorder();

    return 0;
}
