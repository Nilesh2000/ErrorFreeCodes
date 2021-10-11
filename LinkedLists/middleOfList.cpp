/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

APPROACH 1:
1. Calculate the length of the list. Let it be n.
2. Calculate n/2.
3. Traverse from Head till n/2 nodes. Return the n/2th node.

Time Complexity : O(3N/2)
Space Complexity : O(1)

APPROACH 2:
1. Declare 2 pointers slow and fast.
2. Both slow and fast point to Head initially.
3. Move slow by one pointer forward and fast by two pointers forward until fast or fast->next is not NULL.
4. slow is now at the middle of the list.

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

Node *middleElement(Node *Head)
{
  Node *fastPtr = Head;
  Node *slowPtr = Head;

  while (fastPtr != NULL && fastPtr->Next != NULL)
  {
    fastPtr = fastPtr->Next->Next;
    slowPtr = slowPtr->Next;
  }
  return slowPtr;
}

int main(void)
{
  Node *Head = NULL;

  Head = insertAtEnd(Head, 3);
  Head = insertAtEnd(Head, 5);
  Head = insertAtEnd(Head, 7);
  Head = insertAtEnd(Head, 11);
  Head = insertAtEnd(Head, 13);

  cout << middleElement(Head)->Data;

  return 0;
}
