#include <bits/stdc++.h>
#include <string>
using namespace std;

#define Maxsize 20

typedef struct
{
    char *data;
    int top;
    int stacksize;
} SqStack;

bool initStack(SqStack *s)
{
    s->top = -1;
    s->data = (char *)malloc(Maxsize * sizeof(char));
    if (s->data == NULL)
        perror("malloc fail");
    s->stacksize = Maxsize;
    return true;
}

bool isFull(SqStack *s)
{
    if (s->top == s->stacksize - 1)
        return true;
    else
        return false;
}

bool isEmpty(SqStack *s)
{
    if (s->top == -1)
        return true;
    else
        return false;
}

void Push(SqStack *s, char e)
{
    assert(s);
    assert(!isFull(s));
    s->top++;
    s->data[s->top] = e;
}

void Pop(SqStack *s)
{
    assert(s);
    assert(isEmpty(s));
    s->top--;
}

char getTop(SqStack *s)
{
    assert(s);
    assert(!isFull(s));
    return s->data[s->top];
}

bool isLeftBracket(char e)
{
    if (e == '(' || e == '[' || e == '{')
        return true;
    else
        return false;
}

bool isRightBracket(char e)
{
    if (e == ')' || e == ']' || e == '}')
        return true;
    else
        return false;
}

bool isMatched(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    else if (a == '[' && b == ']')
        return true;
    else if (a == '{' && b == '}')
        return true;
    else
        return false;
}

bool branketMatch(char a[])
{
    assert(a);
    SqStack s;
    initStack(&s);
    for (int i = 0; i < strlen(a); i++)
    {
        if (isLeftBracket(a[i]))
        {
            cout << "This is a left bracket." << endl;
            Push(&s, a[i]);
        }
        else if (isRightBracket(a[i]))
        {
            cout << "This is a right bracket." << endl;
            if (isMatched(getTop(&s), a[i]))
                Pop(&s);
            else
                return false;
        }
    }
    if (isEmpty(&s))
        return true;
    else
        return false;
}

int main()
{
    char a[20];
    int i = 0;
    while ((a[i] = getchar()) != '\n')
        i++;
    a[i] = '\0';

    for (int j = 0; j < i; j++)
        cout << a[j];
    cout << endl;

    if (branketMatch(a))
        cout << "Branket Matched!" << endl;
    else
        cout << "Branket Error!" << endl;

    return 0;
}