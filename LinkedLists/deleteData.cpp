//A program to delete a node from a linked list, given the key.
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

void deleteData(int x)
{
  Node *Temp = Head, *Prev; //Set a temporary variable pointing to Head.

  if (Temp != NULL && Temp->Data == x) //If the head node itself contains the data to be deleted
  {
    Head = Temp->Next; //Store the address of the second node in Head.
    delete Temp;       //Deallocate memory for Temp.
    return;            //Exit from the function.
  }

  while (Temp != NULL && Temp->Data != x) //Traverse until the end of the linked list.
  {
    Prev = Temp;       //Set a temporary variable Prev equal to Temp.
    Temp = Temp->Next; //Move to the next element of the linked list.
  }
  //If x is found, Temp is now pointing to the node which contains x.

  if (Temp == NULL) //x was not present in the linked list.
  {
    return; //Exit from the function.
  }

  Prev->Next = Temp->Next;
  delete Temp;
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
  int n;
  insertAtEnd(2);
  insertAtEnd(3);
  insertAtEnd(5);
  insertAtEnd(7);
  insertAtEnd(4);
  printList();
  cout << "\nEnter The Value Stored In The Node Which Has To Be Deleted : ";
  cin >> n;
  deleteData(n);
  printList();
}
