#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100 // 定义顺序表的最大长度

// 定义顺序表结构
typedef struct
{
    int data[Maxsize];
    int length;
} Seqlist;

// 初始化顺序表
void init_seqList(Seqlist *L)
{
    L->length = 0;
}

// 向顺序表中插入元素
void insert_seqList(Seqlist *L, int value)
{
    if (L->length == Maxsize)
    {
        printf("List is full.\n");
        return;
    }

    L->data[L->length++] = value;
}

// 获取两个顺序表的交集
Seqlist getIntersection(Seqlist *B, Seqlist *C)
{
    Seqlist result;
    init_seqList(&result);

    int i = 0, j = 0;
    while (i < B->length && j < C->length)
    {
        if (B->data[i] < C->data[j])
            i++;
        else if (C->data[j] < B->data[i])
            j++;
        else
        {
            insert_seqList(&result, B->data[i]);
            i++;
            j++;
        }
    }

    return result;
}

// 获取 A 列表中不在交集中的元素
Seqlist getSubList(Seqlist *A, Seqlist *intersection)
{
    Seqlist result;
    init_seqList(&result);

    for (int i = 0; i < A->length; i++)
    {
        int flag = 0;
        for (int j = 0; j < intersection->length; j++)
        {
            if (A->data[i] == intersection->data[j])
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
            insert_seqList(&result, A->data[i]);
    }

    return result;
}

// 打印顺序表
void print_seqList(Seqlist *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int main()
{
    Seqlist A, B, C;
    Seqlist intersection, substractlist;
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);

    init_seqList(&A);
    init_seqList(&B);
    init_seqList(&C);

    for (int i = 0; i < m; i++)
    {
        int value;
        scanf("%d", &value);
        insert_seqList(&A, value);
    }

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        insert_seqList(&B, value);
    }

    for (int i = 0; i < p; i++)
    {
        int value;
        scanf("%d", &value);
        insert_seqList(&C, value);
    }

    intersection = getIntersection(&B, &C);
    substractlist = getSubList(&A, &intersection);

    print_seqList(&substractlist);

    return 0;
}
