#include <stdio.h>
#include <stdlib.h>

static int count = 0;

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void leafNodes(struct node *node)
{
    if(node != NULL)
    {
        leafNodes(node->left);
        //printf("%d -> ", node->key);
        leafNodes(node->right);
    
        if(node->right == NULL && node->left == NULL)
        {
            printf("%d ", node->key);
            count++;
        }
    }
}

int main()
{
    struct node *root = NULL;

    int n;
    scanf("%d", &n);

    int data[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    root = insert(root, data[0]);
    for (int i = 1; i < n; i++)
    {
        insert(root, data[i]);
    }
    inorder(root);

    leafNodes(root);
    printf("No. of leaf nodes are: %d", count);

    return 0;
}

// Tries

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node* left;
//     struct Node *right;
// };

// struct Node* newNode(int item)
// {
//     struct Node* temp
//         = (struct Node*)malloc(sizeof(struct Node));
//     temp->data = item;
//     temp->left = temp->right = NULL;
// }

// struct Node* Insert(struct Node *node, int key)
// {
//     if (node == NULL)
//         return newNode(key);

//     if (key < node->data)
//         node->left = Insert(node->left, key);
//     else if (key > node->data)
//         node->right = Insert(node->right, key);
//     return node;
// }

// void Inorder(struct Node *root)
// {
//     if(root == NULL)
//         return;
//     Inorder(root->left);
//     printf("%d", root->data);
//     Inorder(root->right);
// }
// int main()
// {
//     struct Node *root = NULL;
//     struct Node *temp = root;

//     int n;
//     scanf("%d", &n);

//     int data[n];

//     for(int i=0; i<n; i++)
//     {
//         scanf("%d", &data[i]);
//         printf("%d\n", data[i]);
//         //Insert(temp, data);
//     }

//     root = Insert(root, data[0]);

//     for(int i=1; i<n; i++)
//     {
//         Insert(root, data[i]);
//     }

//     Inorder(temp);

//     return 0;
// }
