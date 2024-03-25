#include <stdio.h>
#include <stdlib.h>

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

// merge sequence
Node *getMergedList(Node *a, Node *b)
{
    Node *result = (Node *)malloc(sizeof(Node));
    result->next = NULL;
    Node *current = result;

    a = a->next;
    b = b->next;
    while (a != NULL && b != NULL)
    {
        // printf("current a and b is: %d %d\n", a->data, b->data);
        if (a->data > b->data)
        {
            // put b into tail
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->data = b->data;
            newnode->next = NULL;

            current->next = newnode;
            current = newnode;

            b = b->next;
        }
        else if (a->data < b->data)
        {
            // put a into tail
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->data = a->data;
            newnode->next = NULL;

            current->next = newnode;
            current = newnode;

            a = a->next;
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                Node *newnode = (Node *)malloc(sizeof(Node));
                newnode->data = a->data;
                newnode->next = NULL;

                current->next = newnode;
                current = newnode;
            }
            a = a->next;
            b = b->next;
        }
    }

    // Append the remaining elements of a or b
    while (a != NULL)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = a->data;
        newnode->next = NULL;

        current->next = newnode;
        current = newnode;

        a = a->next;
    }

    while (b != NULL)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = b->data;
        newnode->next = NULL;

        current->next = newnode;
        current = newnode;

        b = b->next;
    }

    return result;
}

// print list
void printList(Node *head)
{
    Node *current = head->next;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;    
    }
    // printf("\n");
}

int main()
{
    Node *a, *b, *mergedList;
    int m, n;
    scanf("%d", &m);
    a = createList(m);
    scanf("%d", &n);
    b = createList(n);

    mergedList = getMergedList(a, b);
    printList(mergedList);

    return 0;
}
