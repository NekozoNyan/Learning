#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int expo;
    struct Node *next;
} Node;

Node *createNode(int coeff, int expo)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int coeff, int expo)
{
    Node *newNode = createNode(coeff, expo);
    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
    }
    else
    {
        Node *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

void displayPolynomial(Node *head)
{
    if (head == NULL)
    {
        printf("Empty Polynomial\n");
        return;
    }
    Node *current = head;
    do
    {
        printf("(%dx^%d) ", current->coeff, current->expo);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void derivative(Node *poly, Node **derivativePoly)
{
    if (poly == NULL)
    {
        *derivativePoly = NULL;
        return;
    }

    Node *current = poly;
    do
    {
        int coeff = current->coeff * current->expo;
        int expo = current->expo - 1;
        if (expo >= 0)
        {
            insertNode(derivativePoly, coeff, expo);
        }
        current = current->next;
    } while (current != poly);
}

void destroyPolynomial(Node **poly)
{
    if (*poly == NULL)
        return;

    Node *current = *poly;
    Node *temp;
    do
    {
        temp = current->next;
        free(current);
        current = temp;
    } while (current != *poly);

    *poly = NULL;
}

int main()
{
    Node *poly = NULL;
    Node *derivativePoly = NULL;

    insertNode(&poly, 3, 4);
    insertNode(&poly, 2, 2);
    insertNode(&poly, 1, 0);

    printf("Original Polynomial: ");
    displayPolynomial(poly);

    derivative(poly, &derivativePoly);

    printf("Derivative Polynomial: ");
    displayPolynomial(derivativePoly);

    destroyPolynomial(&poly);
    destroyPolynomial(&derivativePoly);

    return 0;
}
