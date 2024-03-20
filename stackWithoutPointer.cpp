#include <bits/stdc++.h>
using namespace std;
#define InitSize 10
#define Increment_Size 5

typedef struct
{
    int *top;
    int *base;
    int stacksize;
} SqStack;

// initiate stack
bool initStack(SqStack &S)
{
    S.base = (int *)malloc(InitSize * sizeof(int));
    if (!S.base)
        return false;
    S.top = S.base;
    S.stacksize = InitSize;
    return true;
}

// destroy stack
void destroyStack(SqStack &S)
{
    free(S.base);
    S.top = S.base = NULL;
    S.stacksize = 0;
}

// clear stack
void clearStack(SqStack &S)
{
    S.top = S.base;
}

// comfirm if the stack is empty
bool isEmpty(SqStack &S)
{
    if (S.top == S.base)
        return true;
    else
        return false;
}

// return the length of the stack
int getLength(SqStack &S)
{
    return S.top - S.base;
}

// get top element of the stack
int getTop(SqStack &S)
{
    if (!isEmpty(S))
        return *(S.top - 1);
    else
        return false;
}

// push
void Push(SqStack &S, int e)
{
    if (S.top - S.base == S.stacksize)
    {
        S.base = (int *)realloc(S.base, (S.stacksize + Increment_Size) * sizeof(int));
        if (!S.base)
            cout << "Overflow!" << endl;
        exit(1);
        S.top = S.base + S.stacksize;
        S.stacksize += Increment_Size;
    }
    *S.top = e;
    S.top++;
}

// pop
void Pop(SqStack &S, int e)
{
    if (S.top != S.base)
    {
        e = *(S.top-1);
        S.top--;
    }
    else
    {
        cout << "Stack Is Empty!" << endl;
        exit(1);
    }
}

// print stack
void traverseStack(SqStack &S)
{
    int *p = S.base;
    while (p < S.top)
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;
}

// main
int main()
{
    SqStack S;
    initStack(S);
    int i = 0;
    int e;
    cout << isEmpty(S) << endl;
    while (i < 5)
    {
        cin >> e;
        Push(S, e);
        i++;
    }
    cout << isEmpty(S) << endl;
    traverseStack(S);
    cout << getLength(S) << endl;

    cout << getTop(S) << endl;
    traverseStack(S);

    int top;
    Pop(S, top);
    cout << top << endl;
    traverseStack(S);

    clearStack(S);
    cout << isEmpty(S) << endl;

    destroyStack(S);
    cout << (S.base == NULL) << endl;

    return 0;
}