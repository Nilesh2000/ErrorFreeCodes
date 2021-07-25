// A program to merge two sorted linked lists to create a new sorted linked list
#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

Node *insertAtEnd(Node *Head, int x)
{
    Node *Temp = new Node();
    Temp->Data = x;
    Temp->Next = NULL;

    if (Head == NULL)
    {
        Head = Temp;
        return Head;
    }

    Node *lastNode = Head;
    while (lastNode->Next != NULL)
    {
        lastNode = lastNode->Next;
    }

    lastNode->Next = Temp;
    return Head;
}

void printList(Node *Head)
{
    while (Head != NULL)
    {
        cout << Head->Data << " ";
        Head = Head->Next;
    }
}

Node *mergeSortedLists(Node *Head1, Node *Head2)
{
    if (Head1 == NULL && Head2 == NULL)
        return NULL;
    if (Head1 == NULL)
        return Head2;
    if (Head2 == NULL)
        return Head1;

    Node *Head3 = NULL;
    while (Head1 != NULL && Head2 != NULL)
    {
        if (Head1->Data < Head2->Data)
        {
            Head3 = insertAtEnd(Head3, Head1->Data);
            Head1 = Head1->Next;
        }
        else if (Head2->Data < Head1->Data)
        {
            Head3 = insertAtEnd(Head3, Head2->Data);
            Head2 = Head2->Next;
        }
        else
        {
            Head3 = insertAtEnd(Head3, Head1->Data);
            Head3 = insertAtEnd(Head3, Head2->Data);
            Head1 = Head1->Next;
            Head2 = Head2->Next;
        }
    }

    if (Head1 != NULL)
    {
        while (Head1 != NULL)
        {
            Head3 = insertAtEnd(Head3, Head1->Data);
            Head1 = Head1->Next;
        }
    }

    if (Head2 != NULL)
    {
        while (Head2 != NULL)
        {
            Head3 = insertAtEnd(Head3, Head2->Data);
            Head2 = Head2->Next;
        }
    }

    return Head3;
}

int main(void)
{
    int n;
    Node *Head1 = NULL, *Head2 = NULL, *Head;

    Head1 = insertAtEnd(Head1, 1);
    // Head1 = insertAtEnd(Head1, 7);
    // Head1 = insertAtEnd(Head1, 8);
    Head1 = insertAtEnd(Head1, 2);
    Head1 = insertAtEnd(Head1, 4);
    printList(Head1);
    cout << "\n";

    Head2 = insertAtEnd(Head2, 1);
    Head2 = insertAtEnd(Head2, 3);
    Head2 = insertAtEnd(Head2, 4);
    // Head2 = insertAtEnd(Head2, 10);
    // Head2 = insertAtEnd(Head2, 12);
    printList(Head2);
    cout << "\n";

    Head = mergeSortedLists(Head1, Head2);
    printList(Head);

    return 0;
}
