#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

Node *head;

void Print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void InsertAnyPosition(int data, int position)
{
    Node *temp1 = (Node *)malloc(sizeof(Node));
    temp1->data = data;
    temp1->next = NULL;

    if (position == 0)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node *temp2 = head;
    for (int i = 0; i < position - 1; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

int main()
{
    head = NULL;             // Empty List
    InsertAnyPosition(2, 0); // List : [2]
    InsertAnyPosition(3, 1); // list : [2,3]
    InsertAnyPosition(4, 0); // list : [4,2,3]
    InsertAnyPosition(5, 1); // list : [4,5,2,3]
    Print();
}