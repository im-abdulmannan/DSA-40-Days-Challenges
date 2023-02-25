#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *temp, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << ", ";
        p = p->next;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 23, 45, 77};
    create(A, 8);
    Display(first);
    return 0;
}
