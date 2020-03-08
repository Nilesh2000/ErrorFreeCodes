/*
A program to find the bitonic point of a linked list.
A Bitonic Point is a point in bitonic sequence before which elements are strictly increasing and after which elements are strictly decreasing.
if no there is no bitonic point, return -1, else return the data at the bitonic node.
*/
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

int bitonicPoint()
{
  Node *n = Head;

  if (n == NULL || n->Next == NULL) //If the list contains no nodes or only one node,
    return -1;

  if (n->Data > n->Next->Data) //If there is no element smaller than the first element itself, the list will not be bitonic.
    return -1;

  while (n->Next != NULL) //Start traversing the list
  {
    if (n->Data > n->Next->Data) //If the order of the list is disturbed somewhere, break from the loop.
      break;

    n = n->Next; //Else, continue to Traverse the list.
  }

  int bitonicPoint = n->Data;
  //Nodes must be descending order starting from here.
  while (n->Next != NULL)
  {
    if (n->Data < n->Next->Data) //If the element which is being checked is smaller than the next element (ascending), exit from the function.
      return -1;

    n = n->Next; //Else, continue to Traverse the list.
  }
  return bitonicPoint;
}

int main(void)
{
  insertAtEnd(1);
  insertAtEnd(2);
  insertAtEnd(3);
  insertAtEnd(4);
  insertAtEnd(3);
  insertAtEnd(2);
  insertAtEnd(1);
  //insertAtEnd(6);
  cout << "\nThe bitonic point of the linked list is : " << bitonicPoint();
  return 0;
}
//End of program.
