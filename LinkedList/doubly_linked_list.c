#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void DLLinsertHead(int x, Node **head, Node **tail, int *n)
{
    Node *new;
    new->data = x;
    printf("imh");

    if (n == 0)
    {
        new->next = NULL;
        new->prev = NULL;
        (*head) = new;
        (*tail) = new;
        n += 1;
        return;
    }

    new->prev = NULL;
    new->next = (*head);
    (*head) = new;
    (new->next)->prev = new;
}
void DLLinsertTail(int x, Node **tail, Node **head, int *n)
{
    Node *new;
    new->data = x;
    if ((*n) == 0)
    {
        new->next = NULL;
        new->prev = NULL;
        (*head) = new;
        (*tail) = new;
        (*n) += 1;
        return;
    }

    new->next = NULL;
    new->prev = (*tail);
    (*tail) = new;
    (new->prev)->next = new;
    (*n) += 1;
}

void DLLdeleteFromHead(int pos, Node **head, Node **tail, int *n)
{
    if (pos >= (*n) || pos < 0)
    {
        printf("error try again !!! \n");
        return;
    }

    if (pos == 0)
    {
        Node *temp1 = *head;
        *head = temp1->next;
        free(temp1);
        ((*head)->next)->prev = (*head);
        (*n) -= 1;
        return;
    }
    Node *now = *head;
    for (int i = 0; i < pos; i++)
    {
        now = now->next;
    }

    Node *tempN = now->next;
    Node *tempP = now->prev;

    if (tempN != NULL)
    {
        tempN->prev = tempP;
    }
    else
    {
        (*tail) = tempP;
    }

    if (tempP != NULL)
    {
        tempP->next = tempN;
    }
    else
    {
        (*head) = tempN;
    }
    free(now);
    (*n) -= 1;
}
void DLLdeleteFromTail(int pos, Node **head, Node **tail, int *n)
{
    if (pos >= (*n) || pos < 0)
    {
        printf("error try again !!! \n");
        return;
    }

    if (pos == (*n) - 1)
    {
        Node *temp1 = *tail;
        *tail = temp1->prev;
        free(temp1);
        ((*tail)->prev)->next = (*tail);
        (*n) -= 1;
        return;
    }
    Node *now = *tail;
    for (int i = (*n) - 1; i > pos; i--)
    {
        now = now->prev;
    }

    Node *tempN = now->next;
    Node *tempP = now->prev;

    if (tempN != NULL)
    {
        tempN->prev = tempP;
    }
    else
    {
        (*tail) = tempP;
    }

    if (tempP != NULL)
    {
        tempP->next = tempN;
    }
    else
    {
        (*head) = tempN;
    }
    free(now);
    (*n) -= 1;
}

void DLLprintFromHead(Node *head)
{
    printf("DLL From Head : [ ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}
void DLLprintFromTail(Node *tail)
{
    printf("DLL From Tail : [ ");
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->next;
    }
    printf("]\n");
}

void main()
{
    int n = 0;
    Node *head, *tail;
    head = NULL;
    tail = NULL;
    int x, pos;
    printf("start insert Head\n");
    while (1)
    {
        printf("x : ");
        scanf("%d", &x);
        if (x == 69)
        {
            printf("end insert Head\n");
            break;
        }
        printf("imh hh");
        DLLinsertHead(x, &head, &tail, &n);
    }
    printf("start insert Tail\n");
    while (1)
    {
        printf("x : ");
        scanf("%d", &x);

        if (x == 69)
        {
            printf("end insert Tail\n");
            break;
        }

        DLLinsertTail(x, &head, &tail, &n);
    }
}