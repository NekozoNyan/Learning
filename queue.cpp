#include <bits/stdc++.h>
using namespace std;

#define Maxsize 20

typedef struct
{
    int data;
    struct QNode *next;
} QNode;

typedef struct
{
    QNode *head;
    QNode *tail;
    int size;
} Queue;

void initQueue(Queue *q)
{
    assert(q);
    q->head = q->tail = NULL;
    q->size = 0;
}

bool isEmpty(Queue*q)
{
    if(q->head == NULL)
        return true;
    else 
        return false;
}

void Push(Queue *q, int e)
{
    assert(q);
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    if (newnode == NULL)
        perror("malloc fail");

    newnode->data = e;
    newnode->next = NULL;
    if (q->tail == NULL)
    {
        q->head = q->tail = newnode;
    }
    else
    {
        q->tail->next = newnode;
        q->tail = q->tail->next;
    }
    q->size++;
}

void Pop(Queue *q){
    assert(q);
    assert(!isEmpty(q));
    if(q->tail->next == NULL)

    
}
