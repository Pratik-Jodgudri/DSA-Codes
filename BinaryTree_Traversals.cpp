#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node *left;
        Node *right;
};

void Inorder(Node *root);
{
    if(root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node *root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node *root)
{
    if(root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

Node* newNode(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    return 0;
}