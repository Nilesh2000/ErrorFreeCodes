/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

APPROACH 1:
Great explaination
https://www.youtube.com/watch?v=BE0hruM5O5U&ab_channel=JyotinderSingh

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;

    Node(int x)
    {
        Data = x;
        Next = NULL;
    }
};

Node *insertAtEnd(Node *Head, int x)
{
    Node *Temp = new Node(x);

    if (Head == NULL)
    {
        Head = Temp;
        return Head;
    }

    Node *lastNode = Head;
    while (lastNode->Next != NULL)
        lastNode = lastNode->Next;

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
    cout << "\n";
}

Node *reverseSublist(Node *Head, int m, int n)
{
    if (Head == NULL || m == n)
        return Head;

    Node *dummyNode = new Node(0);
    dummyNode->Next = Head;

    Node *nodeBeforeSublist = dummyNode;
    int Pos = 1;

    while (Pos < m)
    {
        nodeBeforeSublist = nodeBeforeSublist->Next;
        Pos++;
    }

    Node *workingPtr = nodeBeforeSublist->Next;
    while (m < n)
    {
        Node *nodeToBeExtracted = workingPtr->Next;
        workingPtr->Next = nodeToBeExtracted->Next;

        nodeToBeExtracted->Next = nodeBeforeSublist->Next;
        nodeBeforeSublist->Next = nodeToBeExtracted;
        m++;
    }
    return dummyNode->Next;
}

int main(void)
{
    Node *Head = NULL;

    Head = insertAtEnd(Head, 3);
    Head = insertAtEnd(Head, 5);
    Head = insertAtEnd(Head, 7);
    Head = insertAtEnd(Head, 11);
    Head = insertAtEnd(Head, 13);
    Head = insertAtEnd(Head, 15);
    Head = insertAtEnd(Head, 17);

    int m = 3, n = 6;
    printList(Head);
    Head = reverseSublist(Head, m, n);
    printList(Head);

    return 0;
}
