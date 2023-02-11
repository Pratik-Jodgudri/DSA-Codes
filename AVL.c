#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
    int height;
};

int max(int a, int b)
{
    return (a > b)? a : b;
}

struct Node* createNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->height = 0;
    return temp;
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

// Right Rotate Subtree rooted with y
struct Node* rightRotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T = x->right;

    x->right = y;
    y->left = T;

    y->height = height(y);
    x->height = height(x);

    return x;
}

// Left Rotation Subtree rooted with x
struct Node* leftRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T = y->left;

    y->left = x;
    x->right = T;

    x->height = height(x);
    y->height = height(y);

    return y;
}

int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node *Insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = Insert(root->left, data);
    else if (data > root->data)
        root->right = Insert(root->right, data);
    else
        return root;

    root->height = height(root);

    int balance = getBalance(root);

    if(balance > 1 && data < root->left->data)
        return rightRotation(root);
    if(balance < -1 && data > root->right->data)
        return leftRotation(root);
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }   

    return root;
}

struct Node* successor(struct Node *node)
{
    struct Node *temp = node->right;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

struct Node* Delete(struct Node* root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else 
    {
        if(root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else 
        {
            struct Node *temp = successor(root);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }

    if (root == NULL) //if tree had only one child return root
        return root;
    root->height = height(root);

    int balance = getBalance(root);

    if(balance > 1 && getBalance(root->left) >= 0)
        return rightRotation(root);
    if(balance < -1 && getBalance(root->right) <= 0)
        return leftRotation(root);
    if(balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if(balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void Inorder(struct Node *root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

void Preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main()
{
    // int n = 9;
    // int arr[n];
    // for(int i = 0; i<n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    //struct Node *root = createNode(arr[0]);
    
    // for(int i = 1; i<n; i++)
    // {
    //     root = Insert(root, arr[i]);
    // }

    char arr[100];
    scanf("%[^\n]s", arr);
    struct Node *root = createNode(35);
    root = Insert(root, 56);
    root = Insert(root, 62);
    root = Insert(root, 23);
    root = Insert(root, 31);
    root = Delete(root, 62);
    root = Insert(root, 47);
    root = Insert(root, 48);
    root = Insert(root, 12);
    root = Delete(root, 47);
    root = Delete(root, 56);
    root = Insert(root, 50);

    Inorder(root);
    printf("\n");
    Preorder(root);
    return 0;
}