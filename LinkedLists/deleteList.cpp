//A program to delete all the elements of a linked list.
#include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

Node *Head = NULL; //List is initially empty.

void insertAtEnd(int x)
{
  Node *Temp = new Node(); //Allocate memory to create a new node.
  Temp->Data = x;          //Initialize the Data of the node to the parameter passed.
  if (Head == NULL)        //Check if the list is initially empty.
  {
    Head = Temp; //Set the address of the newly allocated node to Head.
    return;
  }
  //If the list is not empty,

  Node *lastNode = Head; //Set a temporary variable of type Node to Head.

  while (lastNode->Next != NULL) //Traverse the linked list till the end of the list.
  {
    lastNode = lastNode->Next; //Keep moving to the next node.
  }
  lastNode->Next = Temp; //Set the address of the last node to the newly allocated node in memory.
}

void printList()
{
  cout << "\nThe elements of the list are :";
  Node *Temp = Head;
  while (Temp != NULL)
  {
    cout << Temp->Data << " ";
    Temp = Temp->Next;
  }
}

void deleteList()
{
  Node *Cur = Head, *Link;
  while (Cur->Next != NULL)
  {
    Link = Cur->Next;
    delete Cur;
    Cur = Link;
  }
  Head = NULL;
}

int main(void)
{
  insertAtEnd(3);
  insertAtEnd(5);
  insertAtEnd(7);
  printList();
  deleteList();
  cout << "\nLinked list deleted.";
  printList();
  return 0;
}
