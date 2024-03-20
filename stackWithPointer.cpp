#include <bits/stdc++.h>
using namespace std;

#define Maxsize 20

typedef struct
{
    int *data;
    int top;
    int stacksize; // 添加了一个成员变量来表示栈的最大容量
} SqStack;

// 初始化栈
bool initStack(SqStack *S)
{
    S->top = -1;
    S->data = (int *)malloc(Maxsize * sizeof(int));
    if (S->data == NULL)
    {
        exit(1);
    }
    S->stacksize = Maxsize; // 初始化栈的最大容量
    return true;
}

// 判断栈是否满
bool isFull(SqStack *S)
{
    return S->top == S->stacksize - 1;
}

// 判断栈是否为空
bool isEmpty(SqStack *S)
{
    return S->top == -1;
}

// 入栈
void Push(SqStack *S, int e)
{
    if (isFull(S))
    {
        exit(1);
    }
    S->top++;
    S->data[S->top] = e;
}

// 出栈
void Pop(SqStack *S, int &e)
{
    if (isEmpty(S))
    {
        exit(1);
    }
    e = S->data[S->top];
    S->top--;
}

// 获取栈顶元素
void getTop(SqStack *S, int &e)
{
    if (!isEmpty(S))
        e = S->data[S->top];
    else
        exit(1);
}

// 遍历栈并打印元素
void traverseStack(SqStack *S)
{
    for (int i = 0; i <= S->top; i++)
    {
        cout << S->data[i] << " ";
    }
    cout << endl;
}

int main()
{
    SqStack S;
    initStack(&S);

    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);

    traverseStack(&S);

    int topElement;
    getTop(&S, topElement);
    cout << "Top element: " << topElement << endl;

    int popElement;
    Pop(&S, popElement);
    cout << "Popped element: " << popElement << endl;

    traverseStack(&S);

    free(S.data);

    return 0;
}
