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

struct Node* succInorder(struct Node *node)
{
    struct Node *temp = node;
    
    while(temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

struct Node* deleteNode(struct Node *root, int key)
{
    if(root != NULL)
    {
        struct Node *node = root;
        if(key < node->data)
        {
            node->left = deleteNode(node->left, key);
        }
        else if(key > node->data)
        {
            node->right = deleteNode(node->right, key);
        }
        else if(node->data == key)
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
                //printf("node->right: %d", temp->data);
                free(node);
                return temp;
            }
            else 
            {
                struct Node *temp = succInorder(node->right);
                //printf("temp->data = %d\n", temp->data);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    int n = 6;
    int arr[n];
    //int llimit, ulimit;
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // scanf("%d", &llimit);
    // scanf("%d", &ulimit);
    
    root = createNode(arr[0]);
    for(int i=1; i<n; i++)
    {
        Insert(root, (arr[i]));
    }
    
    //Inorder(root);
    
    // for(int i=0; i<n; i++)
    // {
    //     if(arr[i] >= llimit && arr[i] <= ulimit)
    //     {
    //         //printf("%d \n", arr[i]);
    //         root = deleteNode(root, arr[i]);
    //         //Inorder(root);
    //         //printf("\n");
    //     }
    // }
    
    Inorder(root);
    printf("\n");

    root = deleteNode(root, arr[2]);

    Inorder(root);
    
    return 0;
}
