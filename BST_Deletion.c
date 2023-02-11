#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Inorder(struct Node *node)
{
    if(node != NULL)
    {
        Inorder(node->left);
        
        printf("%d ", node->data);
        
        Inorder(node->right);
    }
}

void Insert(struct Node *root, int key)
{
    if(key < root->data)
    {
        if(root->left == NULL)
        {
            root->left = createNode(key);
        }
        else
            Insert(root->left, key);
    }
    else if(key > root->data)
    {
        if(root->right == NULL)
        {
            root->right = createNode(key);
        }
        else
            Insert(root->right, key);
    }
}

struct Node* predInorder(struct Node *node)
{
    struct Node *temp = node->left;
    while (temp && temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

struct Node* deleteNode(struct Node *node, int key)
{
    if(node != NULL)
    {
        if(key < node->data)
        {
            node->left = deleteNode(node->left, key);
        }
        else if(key > node->data)
        {
            node->right = deleteNode(node->right, key);
        }
        else if(key == node->data)
        {
            if(node->left == NULL)
            {
                struct Node *temp = node->right;
                free(node);
                return temp;
            }
            else if(node->right == NULL)
            {
                struct Node *temp = node->left;
                free(node);
                return temp;
            }
            else 
            {
                struct Node *temp = predInorder(node);
                node->data = temp->data;
                node->left = deleteNode(node->left, temp->data);
            }
        }
    }
    return node;
}

int main()
{
    struct Node *root = NULL;
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    root = createNode(arr[0]);
    Inorder(root);
    printf("\n");
    for(int i=1; i<n; i++)
    {
        Insert(root, arr[i]);
    }
    Inorder(root);
    printf("\n");

    root = deleteNode(root, arr[0]);
    Inorder(root);
    printf("\n");
    return 0;
}