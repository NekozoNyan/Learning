#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20

// static sequential list
typedef struct
{
    int data[Maxsize];
    int length;
} Stlist;

// single linked list
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// initiate static list
void init_stList(Stlist *L)
{
    L->length = 0;
}

// initiate linkedlist
void init_sList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

// insert valve
int insertList(Stlist *L, int i, int e)
{
    if (i < 1 || i > L->length + 1)
        return 0;
    if (L->length >= Maxsize)
        return 0;
    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return 1;
}

// generate list
void generateList(Stlist *L, int n)
{
    int iput;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &iput);
        insertList(L, L->length + 1, iput);
    }
}

// TailInsert to create a single linked list
LinkList tailInsert(LinkList *L, int elenum)
{
    int x;
    *L = (LNode *)malloc(sizeof(LNode));
    LNode *p, *t = *L;
    for (int i = 0; i < elenum; i++)
    {
        scanf("%d", &x);
        p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        t->next = p;
        t = p;
    }
    t->next = NULL;
    return *L;
}

// length of list
int getlength(LinkList *L)
{
    int len = 0;
    LNode *p = *L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// HeadInsert to create a single linked list
void headInsert(LinkList *L, int e)
{
    LNode *t;
    t = (LNode *)malloc(sizeof(LNode));
    t->data = e;
    t->next = (*L)->next;
    (*L)->next = t;
}

// print seqlist
void print_SqList(Stlist *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

// print linklist
void printList(LinkList *L)
{
    LNode *p = (*L)->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void reverseSqList(Stlist *L)
{
    int temp;
    for (int i = 0; i < L->length / 2; i++)
    {
        temp = L->data[i];
        L->data[i] = L->data[L->length - i - 1];
        L->data[L->length - i - 1] = temp;
    }
}

void reverseLinkedList(LinkList *L)
{
    if (L == NULL || (*L)->next == NULL)
    {
        return;
    }

    // LNode *prev = NULL;
    // LNode *current = (*L)->next;
    // LNode *next = NULL;

    // while (current != NULL) {
    //     next = current->next;
    //     current->next = prev;
    //     prev = current;
    //     current = next;
    // }

    // (*L)->next = prev;

    LNode *current = (*L)->next;
    LNode *nxt = (*L)->next;
    (*L)->next = NULL;

    do
    {
        nxt = nxt->next;
        current->next = (*L)->next;
        (*L)->next = current;
        current = nxt;
    } while (nxt != NULL);
}

int main()
{
    Stlist L;
    init_stList(&L);
    LinkList S;
    init_sList(&S);

    int elenum;
    scanf("%d", &elenum);
    generateList(&L, elenum);
    tailInsert(&S, elenum);
    // print_List(&L);

    reverseSqList(&L);
    reverseLinkedList(&S);
    print_SqList(&L);
    printList(&S);
}