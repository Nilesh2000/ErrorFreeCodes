//A program to rotate the elements of a linked list in clockwise fashion.
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

//Function which performs the job.
Node *rotateList(Node *Head, int k)
{
  if (k == 0)
    return Head;

  Node *mainPtr = Head, *refPtr = Head;

  for (int i = 0; i < k; i++)
    refPtr = refPtr->Next;

  while (refPtr->Next != NULL)
  {
    refPtr = refPtr->Next;
    mainPtr = mainPtr->Next;
  }

  refPtr->Next = Head;
  Head = mainPtr->Next;
  mainPtr->Next = NULL;

  return Head;
}

int lengthOfList(Node *Head)
{
  int Len = 0;
  while (Head != NULL)
  {
    Head = Head->Next;
    Len++;
  }
  return Len;
}

int main(void)
{
  int k = 9;

  Node *Head = NULL;
  for (int i = 10; i <= 60; i += 10)
    Head = insertAtEnd(Head, i);

  printList(Head);
  cout << "\n";

  // Find length of list
  int Len = lengthOfList(Head);

  k = k % Len;
  Head = rotateList(Head, k);

  printList(Head);
  return 0;
}
