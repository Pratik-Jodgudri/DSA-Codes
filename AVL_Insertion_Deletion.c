#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
    int height;
};

struct Node *createNewnode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->height = 0;
    return temp;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = height(y);
    x->height = height(x);

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t = y->left;

    y->left = x;
    x->right = t;

    y->height = height(y);
    x->height = height(x);

    return y;
}

struct Node *Insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNewnode(data);

    if (data < root->data)
        root->left = Insert(root->left, data);
    else if (data > root->data)
        root->right = Insert(root->right, data);
    else
        return root;

    root->height = height(root);

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node *succ(struct Node *node)
{
    struct Node *temp = node->right;

    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

struct Node *Delete(struct Node *node, int data)
{
    if (node == NULL)
        return node;
    if (data < node->data)
        node->left = Delete(node->left, data);
    else if (data > node->data)
        node->right = Delete(node->right, data);
    else
    {
        if (node->left == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else
        {
            struct Node *temp = succ(node);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
    }

    if (node == NULL)
    {
        return node;
    }

    node->height = height(node);

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
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

int main()
{
    struct Node *root = NULL;
    char arr[100];
    scanf("%s",arr);
    root = createNewnode(35);
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
    return 0;
}