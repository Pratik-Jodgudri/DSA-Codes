#include <stdio.h>
#include <stdlib.h>

static int prev;

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

void predInorder(struct Node *node, int key)
{
    if(node != NULL)
    {
        predInorder(node->left, key);
        if(node->data == key)
        {
            printf("%d", prev);
        }
        prev = node->data;
        predInorder(node->right, key);
    }
}

// void Insert(struct Node *root, struct Node *node)
// {
//     printf("%d", node->data);
//     printf("%d", root->data);

//     if (node->data < root->data)
//     {
//         Insert(root->left, node);
//     }
//     else if (node->data > root->data)
//     {
//         Insert(root->right, node);
//     }
//     else
//     {
//         root = node;
//     }
// }

void Insert(struct Node *root, int key)
{
    if(key < root->data)
    {
        //printf("%d < %d \n", key, root->data);
        if(root->left == NULL)
        {
            root->left = createNode(key);
        }
        else
            Insert(root->left, key);
    }
    else if(key > root->data)
    {
        //printf("%d > %d \n", key, root->data);
        if(root->right == NULL)
        {
            root->right = createNode(key);
        }
        else
            Insert(root->right, key);
    }
}

int main()
{
    struct Node *root = NULL;
    //struct Node *temp = root;
    int n = 11;
    int arr[n];
    int key;
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &key);
    
    root = createNode(arr[0]);
    //printf("%d ", root->data);
    for(int i=1; i<n; i++)
    {
        //printf("%d ", i);
        Insert(root, (arr[i]));
    }
    printf("The predecessor for the node 35 is ");
    predInorder(root, key);
    
    return 0;
}
