// Find the nth smallest node in binary tree

#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node *left, *right;
};

void NthNode(int n, Node *node)
{
    static int count = 0;
    
    if(node == NULL)
        return;
    if(count <= n)
    {
        NthNode(n, node->left);
        
        count++;
        
        if(count == n)
        {
            cout << node->data << endl;
        }

        NthNode(n, node->right);
    }
}

int main()
{

    return 0;
}