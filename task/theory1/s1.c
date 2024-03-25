#include <stdio.h>
#define Maxsize 20

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
    Stlist L;
    init_stList(&L);

    int elenum;
    scanf("%d", &elenum);
    generateList(&L, elenum);

    int x;
    scanf("%d", &x);

    // printf("locate %d\n", getIndex(&L, x));
    insertList(&L, getIndex(&L, x), x);
    print_List(&L);

    return 0;
}
