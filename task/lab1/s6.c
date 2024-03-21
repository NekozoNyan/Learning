#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next, *prior;
    int fre;
} Node;

Node *createList(int length)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->prior = NULL;
    Node *current = head;
    char value;
    for (int i = 0; i < length; i++)
    {
        scanf(" %c", &value);

        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = value;
        newnode->next = NULL;
        newnode->fre = 0;
        newnode->prior = current;

        current->next = newnode;
        current = newnode;
    }
    head->prior = current;
    return head;
}

void moveNode(Node *L, char x)
{
    Node *head = L;
    while (L->data != x)
    {
        L = L->next;
    }

    while (L->prior != head && L->fre > L->prior->fre)
    {
        // printf("currrent fre of L and prior Node is:%d %d\n", L->fre, L->prior->fre);
        Node *prev = L->prior;
        Node *next = L->next;

        prev->next = next;
        if (next != NULL)
            next->prior = prev;

        Node *prevPrev = prev->prior;

        prev->prior = L;
        L->next = prev;

        L->prior = prevPrev;
        prevPrev->next = L;
    }
}

void Locate(Node *L, char x)
{
    Node *head = L;
    L = L->next;
    while (L != NULL)
    {
        if (L->data == x)
        {
            L->fre++;
            moveNode(head, x);
        }
        L = L->next;
    }
}

void printList(Node *L)
{
    Node *current = L->next;
    while (current != NULL)
    {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *L;
    int elenum, locatetimes;
    scanf("%d %d", &elenum, &locatetimes);
    L = createList(elenum);
    char x;
    for (int i = 0; i < locatetimes; i++)
    {
        scanf(" %c", &x);
        Locate(L, x);
    }

    printList(L);
    return 0;
}
