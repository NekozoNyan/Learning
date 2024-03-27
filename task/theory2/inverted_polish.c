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
} *Stack;

bool initStack(Stack s)
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

bool isFull(Stack s)
{
    if (s->top == s->stacksize - 1)
        return true;
    else
        return false;
}

bool isEmpty(Stack s)
{
    if (s->top == -1)
        return true;
    else
        return false;
}

void Push(Stack s, char e)
{
    assert(s);
    assert(!isFull(s));
    s->top++;
    s->data[s->top] = e;
}

void Pop(Stack s)
{
    assert(s);
    assert(!isEmpty(s));
    s->top--;
}

char getTop(Stack s)
{
    assert(s);
    assert(!isEmpty(s));
    return s->data[s->top];
}

int precedence(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
}

char *invertPolish(char a[])
{
    char output[Maxsize]; // 用于存储逆波兰式
    int idx = 0;

    Stack s = (Stack)malloc(Maxsize * sizeof(char));
    initStack(s);
    if (!s)
    {
        perror("mallock failed.");
        exit(1);
    }

    int lens = strlen(a);
    for (int i = 0; i < lens; i++) // 遍历表达式
    {
        char c = a[i];
        // printf("current character: %c\n", c);

        if (c == '(') // 左括号直接入栈
            Push(s, c);
        else if (c == ')') // 右括号则出栈至左括号
        {
            while (getTop(s) != '(') // 将左括号之前的栈内元素加入输出
            {
                output[idx++] = getTop(s);
                Pop(s);
            }
            Pop(s); // 将左括号出栈
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') // 操作运算符
        {
            if (isEmpty(s) || getTop(s) == '(')
                Push(s, c);
            else
            {
                while (precedence(getTop(s)) >= precedence(c)) // 比较运算符优先级
                {
                    // 将栈内优先级不低于待处理操作符的符号出栈加入输出
                    output[idx++] = getTop(s);
                    Pop(s);
                }
                Push(s, c); // 将待处理操作符入栈
            }
        }
        else // 单字符运算数直接加入输出
        {
            output[idx++] = c;
        }
    } // 输入遍历完成，此时栈内还有未处理字符

    // 将栈内剩余元素直接加入输出
    while (!isEmpty(s))
    {
        output[idx++] = getTop(s);
        Pop(s);
    }

    output[idx] = '\0'; // 添加终止符，用于打印

    free(s->data);
    free(s);

    return strdup(output); // 重新分配内存给output，否则数组被摧毁无法返回
}

int main()
{
    char a[Maxsize];
    int i = 0;
    while ((a[i] = getchar()) != '\n')
        i++;
    a[i] = '\0';

    // for (int j = 0; j < i; j++)
    //     printf("%c", a[j]);
    // printf("\n");

    char *output = invertPolish(a);
    while (*output != '\0')
    {
        printf("%c", *output);
        output++;
    }

    return 0;
}
