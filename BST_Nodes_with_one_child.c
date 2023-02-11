#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNewNode(int data) 
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* Insert(struct Node *root, int data)
{
    struct Node *temp = root;
    if(temp == NULL)
            return createNewNode(data);
    else if(temp->data != data)
    {        
        if (data < temp->data) 
        {
            temp->left = Insert(temp->left, data);
        }
        else if (data > temp->data) 
        {
            temp->right = Insert(temp->right, data);
        }
    }
    return temp;
}

void Inorder(struct Node* root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        if(root->left == NULL && root->right != NULL)
            printf("%d ", root->data);
        else if(root->right == NULL && root->left != NULL)
            printf("%d ", root->data);
        Inorder(root->right);
    }
}

int main()
{
    int n = 15;
    int arr[n];
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    struct Node *root = createNewNode(arr[0]);
    
    for(int i=1; i<n; i++)
    {
        root = Insert(root, arr[i]);
    }
    
    Inorder(root);
}