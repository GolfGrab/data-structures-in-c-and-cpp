#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void LLprintRecur(Node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    LLprintRecur(head->next);
}

void LLrecurRev(Node *now, Node **head)
{
    if (now->next == NULL)
    {
        *head = now;
        return;
    }
    Node *nextnow = now->next;
    LLrecurRev(nextnow, head);
    nextnow->next = now;
    now->next = NULL;
}

void LLprintRecurRev(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    LLprintRecurRev(head->next);
    printf("%d ", head->data);
}

void LLreverse(Node **head)
{

    Node *tempNow = *head;
    Node *tempNext = NULL;
    Node *tempPrev = NULL;
    if (tempNow == NULL)
    {
        printf("empty LL no rev \n");
        return;
    }
    if (tempNow->next == NULL)
    {
        printf("only 1 LL no rev \n");
        return;
    }
    while (1)
    {
        if (tempNow->next == NULL)
        {
            *head = tempNow;
            tempNow->next = tempPrev;
            break;
        }
        tempNext = tempNow->next;
        tempNow->next = tempPrev;
        tempPrev = tempNow;
        tempNow = tempNext;
    }
}

void LLappend(int x, int pos, Node **head, int *n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;

    if (pos > *n)
    {
        printf("error try again !!! \n");
        return;
    }

    if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
        *n += 1;
        return;
    }

    Node *temp = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    *n += 1;
}

void LLdelete(int pos, Node **head, int *n)
{
    if (pos >= *n)
    {
        printf("error try again !!! \n");
        return;
    }

    if (pos == 0)
    {
        Node *temp1 = *head;
        *head = temp1->next;
        free(temp1);
        *n -= 1;
        return;
    }

    Node *temp = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    Node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    *n -= 1;
}

void LLprint(Node *head)
{
    printf("LL : [ ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

int main()
{
    int n = 0;
    Node *head;
    head = NULL;

    int x, pos;
    printf("start append\n");
    while (1)
    {
        printf("x : ");
        scanf("%d", &x);
        printf("pos : ");
        scanf("%d", &pos);
        if (pos < 0)
        {
            printf("end append\n");
            break;
        }

        LLappend(x, pos, &head, &n);
        LLprintRecur(head);
    }
    printf("start swop\n");
    printf("normal print\n");
    LLprintRecur(head);
    printf("revprint\n");
    LLprintRecurRev(head);
    printf("end revprint\n");
    LLrecurRev(head, &head);
    LLprintRecur(head);
    printf("end swop\n");
    LLrecurRev(head, &head);
    LLprintRecur(head);
    printf("end swop\n");
    printf("start delete\n");
    while (1)
    {
        if (n == 0)
        {
            printf("empty LL end\n");
            break;
        }
        printf("pos : ");
        scanf("%d", &pos);
        if (pos < 0)
        {
            printf("end delete\n");
            break;
        }

        LLdelete(pos, &head, &n);
        LLprintRecur(head);
    }
}