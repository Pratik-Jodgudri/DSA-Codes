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

// void Inorder(struct Node* root, int k)
// {
//     if(root != NULL)
//     {
//         Inorder(root->left, k);
//         printf("%d ", root->data);
//         Inorder(root->right, k);
//     }
// }

int count = 0;
void kthMinimum(struct Node *root, int k)
{
    if (root != NULL)
    {
        kthMinimum(root->left, k);
        count++;
        if(count == k)
            printf("%d\n", root->data);
        kthMinimum(root->right, k);
    }
}

int count2 = 0;
void kthMaximum(struct Node* root, int k)
{
    if (root != NULL)
    {
        kthMaximum(root->right, k);
        count2++;
        if(count2 == k)
            printf("%d ", root->data);
        kthMaximum(root->left, k);
    }
}

int main()
{
    int n = 16;
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
    
    // Inorder(root, 3);
    // printf("\n");
    printf("3rd minimum is  : ");
    kthMinimum(root, 3);
    printf("3rd maximum is  : ");
    kthMaximum(root, 3);
}