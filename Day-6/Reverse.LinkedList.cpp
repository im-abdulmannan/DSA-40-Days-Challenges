
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
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void reverse()
{
    Node *current = first;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {

        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    first = prev;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 23, 45, 77};

    cout << "\nLinked List Elements" << endl;
    create(A, 8);
    Display(first);

    cout << "\nReverse Linked List Elements" << endl;
    reverse();
    Display(first);

    return 0;
}
