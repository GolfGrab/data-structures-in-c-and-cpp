#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

void Print(Node *head)
{
    printf("Linked list : ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void InsertAnyPosition(Node **ptr_head, int data, int position, int *n)
{
    if (position > *n)
    {
        printf("error try again\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0)
    {
        newNode->next = *ptr_head;
        *ptr_head = newNode;
        *n += 1;
        return;
    }

    Node *tamp = *ptr_head;
    for (int i = 0; i < position - 1; i++) // loop until temp point to node before position
    {
        tamp = tamp->next;
    }
    newNode->next = tamp->next;
    tamp->next = newNode;
    *n += 1;
}

int main()
{
    int n = 0;
    Node *head;
    head = NULL; // Empty List

    int num, idx;
    while (1)
    {
        printf("num : ");
        scanf("%d", &num);
        printf("idx : ");
        scanf("%d", &idx);
        InsertAnyPosition(&head, num, idx, &n);
        Print(head);
        printf("\ncount = %d\n", n);
    }
}