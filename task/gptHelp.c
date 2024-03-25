#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int date;
    struct node *pre;
    struct node *next;
} node, *pnode;
void insert(pnode list, int date)
{
    // 尾插法向链表中添加元素
    pnode p = list;
    if (p == NULL)
    {
        return;
    }
    else
    {
        while (p->next)
        {
            p = p->next;
        }
        pnode pnew = (pnode)malloc(sizeof(node));
        pnew->date = date;
        p->next = pnew;
        pnew->pre = p;
        pnew->next = NULL;
    }
}
void tranverselist(pnode list, int n)
{
    // 遍历链表并输出指定位数的小数
    pnode p = list;
    p = p->next;
    printf("%d.", p->date);
    int i;
    p = p->next;
    for (i = 0; i < n; i++)
    {
        printf("%d", p->date);
        if (p->next)
        {
            p = p->next;
        }
    }
    printf("\n");
}
int main()
{
    pnode num; // num为每次相加的 R(n);
    pnode sum; // sum最终的值约等于 Π；
    num = (pnode)malloc(sizeof(node));
    sum = (pnode)malloc(sizeof(node));
    num->pre = NULL;
    sum->pre = NULL;
    num->next = NULL;
    sum->next = NULL;
    // n为题目要求输出的的Π的小数位数；
    int n;
    scanf("%d", &n);
    // 给链表补够600位来进行计算,因为我的精度要达到500
    int i;
    for (i = 0; i < 600; i++)
    {
        insert(num, 0);
        insert(sum, 0);
    }

    // p1,p2为指向两个链表的指针
    pnode p1 = num->next;
    pnode p2 = sum->next;
    
    // 使两个链表除头节点外第一个节点的数据为2，计算直接从R2开始计算，简化了计算
    p1->date = 2;
    p2->date = 2;
    // 指向num,和sum的尾节点
    while (p1->next)
    {
        p1 = p1->next;
    }
    pnode numtail = p1;
    while (p2->next)
    {
        p2 = p2->next;
    }
    pnode sumtail = p2;

    // 开始运算；
    int temp = 0; // 计算过程中产生的临时数据
    int ret = 0;  // 计算过程中产生的借位or进位
    int t;        // 计算时有规律出现的除数 (2n+1)
    for (i = 1, t = 3; i < 10000; i++, t = t + 2)
    { // 根据数学的知识，算的次数越多越精确
        // i同时承担计数和做乘数的任务
        // 先计算乘法（即公式中R(n)*n）
        pnode p3 = numtail;
        ret = 0;
        while (p3)
        {
            temp = p3->date * i + ret;
            p3->date = temp % 10;
            ret = temp / 10;
            p3 = p3->pre;
        }
        ret = 0;
        p3 = num->next;
        // 计算除法 (即公式中的R(n)*n/(2*n+1))
        while (p3)
        {
            temp = p3->date + ret * 10;
            ret = temp % t;
            p3->date = temp / t;
            p3 = p3->next;
        }
        ret = 0;
        pnode p4 = sumtail;
        p3 = numtail;
        // 将得到的R(n)的值加入到结果中
        while (p3 && p4)
        {
            temp = p3->date + p4->date + ret;
            ret = temp / 10;
            p4->date = temp % 10;
            p3 = p3->pre;
            p4 = p4->pre;
        }
    }
    tranverselist(sum, n);
    return 0;
}
