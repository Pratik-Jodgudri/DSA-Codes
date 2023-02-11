#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head, int x)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = *head;
    *head = new_node;
}

int main()
{
    
    return 0;
}
