#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next, *pre;
} Node;

void insertList(Node *L, int e);
Node *initList(Node *head);
void getPi(Node *num, Node *sum, int n);
void printList(Node *L, int n);

int main()
{
    Node *num, *sum;
    num = initList(num);
    sum = initList(sum);
    int n;
    scanf("%d", &n);
    getPi(num, sum, n);

    return 0;
}

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

    // 初始化500长度，确保精度要求
    for (int i = 0; i < 500; i++)
    {
        insertList(head, 0);
    }
    return head;
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
            current = current->next;
        }

        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = e;
        newnode->next = NULL;
        newnode->pre = current;
        current->next = newnode;
    }
}

// 反三角函数幂级展开求Pi
void getPi(Node *num, Node *sum, int n)
{
    Node *p1 = num->next;
    Node *p2 = sum->next;
    p1->data = 2;
    p2->data = 2;

    // 将临时指针移到表尾作为表尾指针
    while (p1->next)
    {
        p1 = p1->next;
    }
    while (p2->next)
    {
        p2 = p2->next;
    }

    // 将计算用链表表尾指针赋给临时指针
    Node *numtail = p1;
    Node *sumtail = p2;

    // 计算，在num链表中完成
    int temp = 0;
    int ret = 0; // 进位数 || 退位数
    int t;       // 存储除数，即反三角函数展开的各项分母，在循环条件中完成迭代
    for (int i = 1, t = 3; i < 10000; i++, t += 2)
    {
        // 由于公式中存在n，可用i直接代替
        Node *p3 = numtail;
        ret = 0;
        // 从表尾向表头计算乘法
        while (p3->pre)
        {
            temp = p3->data * i + ret;
            p3->data = temp % 10;
            ret = temp / 10;
            p3 = p3->pre;
        }
        // 将进退位数置零，将p3从头结点挪回首元节点
        ret = 0;
        p3 = num->next;
        // 从表头向表尾计算除法
        while (p3->next)
        {
            temp = p3->data + ret * 10;
            ret = temp % t;
            p3->data = temp / t;
            p3 = p3->next;
        }
        // 本轮计算完成，将进退位数置零
        ret = 0;
        // 将计算结果从尾部插入sum表中
        Node *p4 = sumtail;
        while (p3 && p4)
        {
            temp = p3->data + p4->data + ret;
            ret = temp / 10;
            p4->data = temp % 10;
            p3 = p3->pre;
            p4 = p4->pre;
        }
    }
    printList(sum, n);
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
        if (!current->next)
        {
            printf("list over, return now.");
            return;
        }
        current = current->next;
    }
    printf("\n");
}
