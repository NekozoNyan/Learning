#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define Maxsize 50

typedef struct
{
    char *data;
    int top;
    int stacksize;
} SqStack, *stack;

bool initStack(SqStack *s)
{
    s->top = -1;
    s->data = (char *)malloc(Maxsize * sizeof(char));
    if (s->data == NULL)
    {
        perror("malloc fail");
        return false;
    }
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
    assert(!isEmpty(s));
    s->top--;
}

char getTop(SqStack *s)
{
    assert(s);
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

bool isBracket(char a)
{
    if(a == '(' || ')' || '[' || ']' || '{' || '}')
        return true;
    else  
        return false;
}

bool bracketMatch(char a[])
{
    assert(a);
    SqStack s;
    SqStack *ptr = &s;
    initStack(&s);
    for (int i = 0; i < strlen(a); i++)
    {
        if (isLeftBracket(a[i]))
        {
            // printf("This is a left bracket.\n");
            Push(ptr, a[i]);
        }
        else if (isRightBracket(a[i]))
        {
            if(isEmpty(ptr))
                return false;

            // printf("This is a right bracket.\n");
            if (isMatched(getTop(ptr), a[i]))
                Pop(ptr);
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
    char a[Maxsize];
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && isBracket(c))
    {
        a[i] = c;
        i++;
    }
    a[i] = '\0';

    // for (int j = 0; j < i; j++)
    //     printf("%c", a[j]);
    // printf("\n");

    if (bracketMatch(a))
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
