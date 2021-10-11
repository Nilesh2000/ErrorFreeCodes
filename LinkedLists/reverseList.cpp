/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

APPROACH 1 (Iterative)
1. Initialize 3 pointers namely prev, curr, next.
2. curr initially points to the Head node
3. Iterate till curr reaches end of list
    3.1 Store address of next node (next=curr->next)
    3.2 Store prev in curr->next (curr->next=prev)
    3.3 Store curr in prev (prev=curr)
    3.4 Move curr forward (curr=next)
4. The last node to be reversed is store in prev.
5. This is now the first node. Set Head=Prev

Time Complexity : O(N)
Space Complexity : O(1)

APPROACH 2 (Recursive)
1. Divide the list in two parts - first node and rest of the linked list.
2. Call reverse for the rest of the linked list.
3. Link rest to first.
4. Fix head pointer

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

Node *reverseList(Node *Head)
{
    Node *Curr = Head, *Prev = NULL, *Next;

    while (Curr != NULL)
    {
        Next = Curr->Next;
        Curr->Next = Prev;
        Prev = Curr;
        Curr = Next;
    }

    Head = Prev;
    return Head;
}

Node *reverseListRecur(Node *Head)
{
    if (Head == NULL || Head->Next == NULL)
        return Head;

    Node *node = reverseList(Head->Next);
    Head->Next->Next = Head;

    Head->Next = NULL;
    return node;
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

int main(void)
{
    Node *Head = NULL;

    Head = insertAtEnd(Head, 2);
    Head = insertAtEnd(Head, 3);
    Head = insertAtEnd(Head, 5);
    Head = insertAtEnd(Head, 7);
    Head = insertAtEnd(Head, 4);

    printList(Head);
    Head = reverseList(Head);
    printList(Head);
    Head = reverseListRecur(Head);
    printList(Head);

    return 0;
}
