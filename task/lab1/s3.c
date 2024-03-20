#include <stdio.h>
#define Maxsize 100

// static sequential list
typedef struct
{
    int data[Maxsize];
    int length;
} Stlist;

// initiate static list
void init_stList(Stlist *L)
{
    L->length = 0;
}

// insert valve
int insertList(Stlist *L, int i, int e)
{
    if (i < 1 || i > L->length + 1)
        return 0;
    if (L->length >= Maxsize)
        return 0;
    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return 1;
}

// generate list
void generateList(Stlist *L, int n)
{
    int iput;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &iput);
        insertList(L, L->length + 1, iput);
    }
}

int isContain(Stlist *L, int e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
            return 1;
    }
    return 0;
}

int getNumlist(Stlist *L, Stlist *S)
{
    int a[100] = 0;
    int j = 0;
    for (int i = 0; i < L->length; i++)
    {
        if (isContain(&S, L->data[i]))
        {
            a[j] = L->data[i];
            j++;
        }
    }
    return a;
}

// find index
int getIndex(Stlist *L, int x)
{
    for (int i = 0; i < L->length; i++)
        if (L->data[i] > x)
            return i + 1;
        else if (L->data[i] == x)
            return i + 2;
    return L->length + 1;
}

void print_List(Stlist *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

int main()
{
    Stlist A, B, C;
    init_stList(&A);
    init_stList(&B);
    init_stList(&C);

    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);
    generateList(&A, m);
    generateList(&B, n);
    generateList(&C, p);

    printf("\n");
    print_List(&A);
    print_List(&B);
    print_List(&C);

    int i = 0;
    int a[100] = getNumlist(&B, &C);
    while(a[i]!=0)
    {
        printf("%d ", a[i]);
        i++;
    }
}
