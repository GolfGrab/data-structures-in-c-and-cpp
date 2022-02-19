#include <stdio.h>
#include <stdlib.h>

/*###############################
#                               #
#       (*temp).data = x;       #
#                               #
#         is same as            #
#                               #
#       temp->data = x;         #
#                               #
#        ez way to get data     #
#     from pointer of struct    #
#                               #
###############################*/

struct Node // struct of the list node have 2 field : data and pointer to next node
{
    int data;
    struct Node *next;
};

struct Node *head; // pointer to head node

void Insert(int x) // perform insertion new number in front of old linked list
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // create new node

    temp->data = x;    // assign data in node = x
    temp->next = head; // assign next pointer to old head
    head = temp;       // assign new head pointer to new node
}

void Print() // perform print all element of the linked list
{
    struct Node *temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    printf("How many number?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number\n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
}