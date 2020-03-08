//A program to count the frequency of each element present in the linked list.
#include <iostream>
#include <map>

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

void frequencyOfElement()
{
  map<int, int> M; //Declare a map with key and value of type int.
  Node *Temp = Head;
  while (Temp != NULL) //Traverse through the linked list.
  {
    M[Temp->Data]++;   //Increment the frequency of a particular element using maps.
    Temp = Temp->Next; //Move to the next node
  }
  //Display frequency of each element.
  for (auto x : M)
    cout << "\nFrequency of " << x.first << " is " << x.second;
}

//Driver function
int main(void)
{
  insertAtEnd(1);
  insertAtEnd(1);
  insertAtEnd(1);
  insertAtEnd(2);
  insertAtEnd(2);
  insertAtEnd(3);
  insertAtEnd(4);
  insertAtEnd(4);
  insertAtEnd(4);
  insertAtEnd(4);
  insertAtEnd(5);
  insertAtEnd(5);
  frequencyOfElement();
  return 0;
}
