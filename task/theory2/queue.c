#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size;

typedef struct
{
    int *data;
    int front, rear;
} *Queue;

void initQueue(Queue Q)
{
    Q->data = (int *)malloc(size * sizeof(int));
    if (Q->data == NULL)
    {
        perror("Malloc failed.");
    }
    Q->rear = Q->front = 0;
}

bool isEmpty(Queue Q)
{
    if (Q->rear == Q->front)
        return true;
    else
        return false;
}

bool isFull(Queue Q)
{
    if ((Q->rear + 1) % size == Q->front)
        return true;
    else
        return false;
}

void Push(Queue Q, int e)
{
    if (isFull(Q))
    {
        perror("Queue FULL!");
        exit(1);
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q ,->rear + 1) % size;
}

int getFront(Queue Q)
{
    if (!isEmpty(Q))
        return Q->data[Q->front];
}

void Pop(Queue Q)
{
    if (isEmpty(Q))
    {
        perror("Queue Empty!");
        exit(1);
    }
    Q->front = (Q->front + 1) % size;
}

int main()
{
    Queue Q = malloc(sizeof(Queue));
    scanf("%d", &size);
    initQueue(Q);

    int i = 0;
    int e, out;
    int a[size];
    while (i++ < size)
    {
        scanf("%d", &e);
        a[i] = e;
        Push(Q, e);
    }

    scanf("%d", &out);

    if(isFull(Q))
        printf("yes\n");
    else
        printf("no\n");

    i = 0;
    while (i++ < size)
        printf("%d ", a[i]);
    printf("\n");
    
    while(getFront(Q) != out)
        Pop(Q);
    Pop(Q);

    printf("%d", getFront(Q));

    return 0;
}
