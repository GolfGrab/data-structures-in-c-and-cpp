#include <stdio.h>
#include <stdlib.h>

/*########### NOTE ##############
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

///////////////////////////////////// def Node struct //////////////////////////////////////
typedef struct Node // struct of the list node have 2 field : data and pointer to next node
{
    int data;
    struct Node *next;
} Node;

///////////////////////////////////// def Insert function //////////////////////////////////////
// perform insertion new number in front of old linked list
void *InsertFront(Node **ptr_head, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node)); // create new node

    temp->data = x;         // assign data in node = x
    temp->next = *ptr_head; // assign next pointer to old head
    *ptr_head = temp;       // assign new head pointer to new node
}

///////////////////////////////////// def Print function //////////////////////////////////////
// perform print all element of the linked list
void Print(Node *head)
{
    // Node *temp = head;
    // no need temp because head value was copied and pass to function
    printf("List is: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

///////////////////////////////////// main function //////////////////////////////////////
int main()
{
    Node *head; // pointer to head node

    head = NULL;
    printf("How many number?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number\n");
        scanf("%d", &x);
        InsertFront(&head, x);
        Print(head);
    }
}