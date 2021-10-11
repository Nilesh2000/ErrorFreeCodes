/*
Given the head of a linked list, return the nth node from the end of the list.

APPROACH 1:
1. Maintain 2 pointers mainPtr and refPtr.
2. Both pointers point to head initially.
3. Move refPtr forward by 'n' nodes.
4. Now, move mainPtr and refPtr forward by one node until refPtr reaches end of list.
5. Return mainPtr.

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

Node *nthNodeFromLast(Node *Head, int n)
{
  if (Head == NULL)
    return NULL;

  Node *mainPtr = Head;
  Node *refPtr = Head;
  int Count = 1;

  while (Count <= n)
  {
    refPtr = refPtr->Next;
    Count++;
  }

  while (refPtr != NULL)
  {
    mainPtr = mainPtr->Next;
    refPtr = refPtr->Next;
  }
  return mainPtr;
}

Node *nthNodeFromLastRecur(Node *Head, int n)
{
  static int i;
  if (Head == NULL)
    return NULL;

  return nthNodeFromLast(Head->Next, n);
  if (++i == n)
    return Head;
}

int main(void)
{
  Node *Head = NULL;

  Head = insertAtEnd(Head, 3);
  Head = insertAtEnd(Head, 5);
  Head = insertAtEnd(Head, 7);
  Head = insertAtEnd(Head, 9);
  Head = insertAtEnd(Head, 11);
  Head = insertAtEnd(Head, 13);
  Head = insertAtEnd(Head, 15);

  cout << nthNodeFromLast(Head, 2)->Data << endl;
  cout << nthNodeFromLast(Head, 2)->Data;

  return 0;
}
