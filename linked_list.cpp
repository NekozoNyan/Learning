#include <bits/stdc++.h>
using namespace std;

// single linked list
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// double linked list
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// single linked list
// initiate list
bool init_sList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    return true;
}

// length of list
int getlength(LinkList &L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// search node by index
LNode *getElem(LinkList &L, int i)
{
    LNode *p = L;
    int j = 0;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// search node by value
LNode *locateElem(LinkList &L, int e)
{
    LNode *p = L->next;
    // LNode *p = L;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

// insert node in front
bool insertList(LinkList &L, int i, int e){
    LNode *p = L;
    int j = 0;
    while(p->next!=NULL && j < i - 1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// delete node
bool deleteNode(LinkList &L, int i)
{
    LNode *p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s;
    s = p->next;
    p->next = p->next->next;
    free(s);
    return true;
}

// HeadInsert to create a single linked list
LinkList headInsert(LinkList &L)
{
    LNode *p;
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        p->next = L->next;
        L->next = p;
        scanf("%d", &x);
    }
    return L;
}

// TailInsert to create a single linked list
LinkList tailInsert(LinkList &L)
{
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    LNode *p, *t = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        t->next = p;
        t = p;
        scanf("%d", &x);
    }
    t->next = NULL;
    return L;
}

// print linklist
void printList(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int main(){
    LinkList L;
    init_sList(L);

    headInsert(L);
    printList(L);

    cout << getElem(L, 3) << endl;
    cout << locateElem(L, 1) << endl;

    insertList(L, 1, 100);
    printList(L);

    deleteNode(L, 1);
    printList(L);

    return 0;
}