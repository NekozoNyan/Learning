#include <bits/stdc++.h>
using namespace std;

#define Maxsize 50
#define Initsize 50

// static sequential list
typedef struct
{
    int data[Maxsize];
    int length;
} Stlist;

// dynamic sequential list
typedef struct
{
    int *data;
    int length, maxsize;
} Dylist;

// initiate static list
void init_stList(Stlist &L)
{
    L.length = 0;
}

// initiate dynamic list
void init_dyList(Dylist &L)
{
    L.data = new int[Initsize];
    L.length = 0;
    L.maxsize = Initsize;
}

// Functions below, example for static sequential list
// insert valve
bool insertList(Stlist &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= Maxsize)
        return false;
    for (int j = L.length; j > i - 1 ; j--)
        L.data[j] = L.data[j-1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// generate list
void generateList(Stlist &L, int n)
{
    int iput;
    for (int i = 0; i < n; i++)
    {
        cin >> iput;
        insertList(L, L.length + 1, iput);
    }
}

// delete
bool deleteList(Stlist &L, int i)
{
    if (i < 0 || i > L.length + 1)
        return false;
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

// search by value
int locateElem(Stlist &L, int e)
{
    int i;
    for (i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

// print data
void print_List(Stlist &L)
{
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

int main()
{
    Stlist L;
    init_stList(L);

    generateList(L, 5);
    print_List(L);

    insertList(L, 3, 12);
    print_List(L);

    deleteList(L, 3);
    print_List(L);

    cout << locateElem(L, 1) << endl;

    return 0;
}