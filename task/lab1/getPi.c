#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next, *pre;
} Node;

Node *initList(Node *head)
{
    head = (Node *)malloc(sizeof(Node));
    if (!head)
    {
        perror("malloc failed\n");
        exit(1);
    }
    head->pre = NULL;
    head->next = NULL;

    for(int i = 0; i < 500; i++)
    {
        insertList(head, 0);
    }
}

// 计算Pi值并返回
double getPi(){
    
}

// 尾插法
void insertList(Node *L, int e)
{
    Node *current = L;
    if (current == NULL)
        return;
    else
    {
        while (current->next)
        {
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->data = e;
            current->next = newnode;

            newnode->pre = current;
            newnode->next = L;
            current = newnode;
        }
        L->pre = current;
    }
}



// 输出链表
void printList(Node *L, int n)
{
    Node *current = L->next;
    printf("%d.", current->data);
    current = current->next;

    for (int i = 0; i < n; i++)
    {
        printf("%d", current->data);
        if(!current->next)
        {
            printf("list over, return now.");
            return;
        }
        current = current->next;
    }
    printf("\n");
}
