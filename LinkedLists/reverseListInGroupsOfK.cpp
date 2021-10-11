/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

APPROACH :
1. Recursively reverse the nodes in groups of k.
2. When you write code to reverse a linked list, the last element to be reversed will be prev.
3. Also, the last element in reversed list will be the old head of the linked list.
4. Thus, we recursively set Head->Next = Prev for each group of size k in the linked list.
5. Return prev to the calling environment.

Time Complexity : O(N)
Space Complexity : O(N/K)

The length of the linked list. (n)
The number of groups we have to reverse. (n/k)
For every linked list group of size k, we have to perform k - 1 reverse operations.
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

Node *reverseKNodes(Node *Head, int k)
{
    // Edge Case
    if (Head == NULL || Head->Next == NULL || k == 1)
        return Head;

    // Go to (k+1)th node to check if there are 'k' elements to reverse
    int Count = 0;
    Node *Temp = Head;
    while (Temp != NULL && ++Count < k)
        Temp = Temp->Next;

    // Base Case
    if (Count < k)
        return Head;

    // Reverse the group of 'k' elements
    Node *Curr = Head, *Prev = NULL, *Next = NULL;
    while (Count--)
    {
        Next = Curr->Next;
        Curr->Next = Prev;
        Prev = Curr;
        Curr = Next;
    }

    Head->Next = reverseKNodes(Curr, k);
    return Prev;
}

void printList(Node *ListNode)
{
    while (ListNode != NULL)
    {
        cout << ListNode->Data << " ";
        ListNode = ListNode->Next;
    }
    cout << "\n";
}

int main(void)
{
    Node *Head = NULL;
    int k = 3;

    Head = insertAtEnd(Head, 1);
    Head = insertAtEnd(Head, 2);
    Head = insertAtEnd(Head, 3);
    Head = insertAtEnd(Head, 4);
    Head = insertAtEnd(Head, 5);
    Head = insertAtEnd(Head, 6);
    Head = insertAtEnd(Head, 7);

    printList(Head);

    Head = reverseKNodes(Head, k);

    printList(Head);

    return 0;
}
