#include <stdio.h>
#include <stdlib.h>

// 链表节点结构体
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 创建链表
Node *createList(int length)
{
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < length; i++)
    {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            current->next = newNode;
        }

        current = newNode;
    }

    return head;
}

// 求链表的交集
Node *intersectLists(Node *listA, Node *listB)
{
    Node *result = NULL;
    Node *tail = NULL;

    while (listA != NULL && listB != NULL)
    {
        if (listA->data < listB->data)
        {
            listA = listA->next;
        }
        else if (listA->data > listB->data)
        {
            listB = listB->next;
        }
        else
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = listA->data;
            newNode->next = NULL;

            if (result == NULL)
            {
                result = newNode;
            }
            else
            {
                tail->next = newNode;
            }

            tail = newNode;

            listA = listA->next;
            listB = listB->next;
        }
    }

    return result;
}

// 求链表的差集
Node *subtractLists(Node *listA, Node *listB)
{
    Node *result = NULL;
    Node *tail = NULL;

    while (listA != NULL)
    {
        int found = 0;
        Node *currentB = listB;

        while (currentB != NULL)
        {
            if (listA->data == currentB->data)
            {
                found = 1;
                break;
            }
            currentB = currentB->next;
        }

        if (!found)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = listA->data;
            newNode->next = NULL;

            if (result == NULL)
            {
                result = newNode;
            }
            else
            {
                tail->next = newNode;
            }

            tail = newNode;
        }

        listA = listA->next;
    }

    return result;
}

// 释放链表内存
void freeList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    int lengthA, lengthB, lengthC;
    Node *listA, *listB, *listC, *intersection, *difference;

    printf("Enter the length of list A: ");
    scanf("%d", &lengthA);
    listA = createList(lengthA);

    printf("Enter the length of list B: ");
    scanf("%d", &lengthB);
    listB = createList(lengthB);

    printf("Enter the length of list C: ");
    scanf("%d", &lengthC);
    listC = createList(lengthC);

    // 计算 B ∩ C - A
    intersection = intersectLists(listB, listC);
    difference = subtractLists(intersection, listA);

    // 打印结果
    printf("Result: ");
    Node *current = difference;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // 释放链表内存
    freeList(listA);
    freeList(listB);
    freeList(listC);
    freeList(intersection);
    freeList(difference);

    return 0;
}
