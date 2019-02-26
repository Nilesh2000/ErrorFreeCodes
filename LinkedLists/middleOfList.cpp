//A program to print the middle Element of a linked list.
# include <iostream>

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
    Temp -> Data = x; //Initialize the Data of the node to the parameter passed.
      if(Head == NULL) //Check if the list is initially empty.
        {
            Head = Temp; //Set the address of the newly allocated node to Head.
            return ;
        }
    //If the list is not empty,

    Node *lastNode = Head; //Set a temporary variable of type Node to Head.

    while(lastNode -> Next != NULL) //Traverse the linked list till the end of the list.
      {
          lastNode = lastNode -> Next; //Keep moving to the next node.
      }
  lastNode -> Next = Temp; //Set the address of the last node to the newly allocated node in memory.
}

/*
Traverse the linked list using two pointers. Move one pointer by one and other pointer by two. When the fast pointer reaches end slow pointer will
reach middle of the linked list.
*/

int middleElement(Node *A)
{
    Node *Fast_Ptr = A;
    Node *Slow_Ptr = A;
    //We have to check for both the conditions in the while loop as the linked list may have even or odd number of elements.
      while(Fast_Ptr != NULL && Fast_Ptr -> Next != NULL)
        {
            Fast_Ptr = Fast_Ptr -> Next -> Next;
            Slow_Ptr = Slow_Ptr -> Next;
        }
    return Slow_Ptr -> Data;
}

void printList()
{
    Node *Temp = Head;
      while(Temp != NULL)
        {
            cout << Temp -> Data << " ";
            Temp = Temp -> Next;
        }
}

int main(void)
{
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    insertAtEnd(11);
    insertAtEnd(13);
    printList();
    cout << "\nThe Middle Element Of The Linked List Is : " << middleElement(Head) << endl;
}
