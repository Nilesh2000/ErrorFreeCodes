// Program to sort a linkedlist of 0s 1s and 2s only in O(n) time.
#include <iostream>
using namespace std;
struct Node
{
  int Data;
  Node *Next;
};

Node *Head = NULL;
void insertAtEnd(int x)
{
  Node *Temp = new Node();
  Temp->Data = x;

  if (Head == NULL)
  {
    Head = Temp;
    return;
  }

  Node *lastNode = Head;
  while (lastNode->Next != NULL)
  {
    lastNode = lastNode->Next;
  }
  lastNode->Next = Temp;
}

/*
The logic here is count the occurrences of 0s, 1s and 2s.
And then create a linked list with them in order.
*/
void sort0s1s2s()
{
  int Count[3] = {0};
  Node *Temp = Head;

  while (Temp != NULL)
  {
    Count[Temp->Data]++;
    Temp = Temp->Next;
  }

  int i = 0;
  Node *Ptr = Head;
  while (Ptr != NULL)
  {
    if (Count[i] == 0)
      ++i;
    else
    {
      Ptr->Data = i;
      Count[i]--;
      Ptr = Ptr->Next;
    }
  }
}

void printList()
{
  Node *Temp = Head;
  while (Temp != NULL)
  {
    cout << Temp->Data << " ";
    Temp = Temp->Next;
  }
}

int main(void)
{
  insertAtEnd(0);
  insertAtEnd(2);
  insertAtEnd(2);
  insertAtEnd(1);
  insertAtEnd(2);
  insertAtEnd(0);
  insertAtEnd(1);
  insertAtEnd(0);
  cout << "\nBefore Sorting : ";
  printList();
  sort0s1s2s();
  cout << "\nAfter Sorting : ";
  printList();
  cout << "\n";
  return 0;
}
