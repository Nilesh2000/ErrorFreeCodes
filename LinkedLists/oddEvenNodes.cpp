// Program to rearrange a linked list such that all even and odd positioned nodes are together

// Test Cases:-
// 1. Empty Linked List
// 2. Linked List With One Node
// 3. Linked List With Two Nodes
// 4. Linked List With Odd Number of Nodes
// 5. Linked List With Even Number of Nodes

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

Node *oddEvenNodes(Node *Head)
{
    if (Head == NULL || Head->Next == NULL)
        return Head;

    // First Odd Node
    Node *odd = Head;
    // First Even Node
    Node *evenHead = Head->Next;

    // Store the address of the first node of the even list so that we can connect the end of the odd list to the first even node
    Node *even = evenHead;
    while (even && even->Next)
    {
        odd->Next = odd->Next->Next;
        even->Next = even->Next->Next;
        odd = odd->Next;
        even = even->Next;
    }
    odd->Next = evenHead;
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

int main(void)
{
    Node *Head = NULL;

    Head = insertAtEnd(Head, 1);
    Head = insertAtEnd(Head, 2);
    Head = insertAtEnd(Head, 3);
    Head = insertAtEnd(Head, 4);
    Head = insertAtEnd(Head, 5);
    Head = insertAtEnd(Head, 6);

    printList(Head);
    cout << "\n";

    Head = oddEvenNodes(Head);

    printList(Head);

    return 0;
}
