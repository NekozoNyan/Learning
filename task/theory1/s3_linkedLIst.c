#include <stdio.h>
#include <stdlib.h>

// define the structure of linked node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// create linked list
Node *createList(int length)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *current = head;

    int value;
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &value);

        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = value;
        newnode->next = NULL;

        // put into tail
        current->next = newnode;
        current = newnode;
    }
    return head;
}

// get the intersection of B and C
Node *getIntersection(Node *B, Node *C)
{
    Node *result = (Node *)malloc(sizeof(Node));
    result->next = NULL;
    Node *current = result;

    B = B->next;
    C = C->next;
    while (B != NULL && C != NULL)
    {
        if (B->data > C->data)
            C = C->next;
        else if (C->data > B->data)
            B = B->next;
        else
        {
            // create a newnode
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->data = B->data;
            newnode->next = NULL;

            current->next = newnode;
            current = newnode;

            B = B->next;
            C = C->next;
        }
    }
    return result;
}

// get sublist
Node *getSubList(Node *A, Node *intersection)
{
    Node *result = (Node *)malloc(sizeof(Node));
    result->next = NULL;
    Node *current = result;

    int flag;
    A = A->next;
    while (A != NULL)
    {
        flag = 0;
        Node *temp = intersection->next;
        while (temp != NULL)
        {
            if (A->data == temp->data)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }

        if (!flag)
        {
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->data = A->data;
            newnode->next = NULL;

            current->next = newnode;
            current = newnode;
        }
        A = A->next;
    }
    return result;
}

// print list
void printList(Node *head)
{
    Node *current = head->next;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *A, *B, *C;
    Node *intersection, *substractlist;
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);

    A = createList(m);
    B = createList(n);
    C = createList(p);

    intersection = getIntersection(B, C);
    // printList(intersection);
    // printf("\n");
    substractlist = getSubList(A, intersection);

    printList(substractlist);

    return 0;
}