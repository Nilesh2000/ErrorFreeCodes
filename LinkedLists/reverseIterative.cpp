//A program to reverse a linked list by an iterative method.
# include <iostream>

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

void reverseList()
{
    Node *Current, *Prev, *Next; //Here *Next is an object of type Node and not a data member which belongs to the structure Node.
    Current = Head; //Set Current to the start of the linked list.
    Prev = NULL; //Prev is initially set to NULL because there is no node before the first node.
      while(Current != NULL)
        {
            Next = Current -> Next; //Store the address of the next node in a variable "Next" so that the list can be traversed.
            Current -> Next = Prev; //Set the address in the current node to the previous node. Actual reversing takes place here.
            //Now, Reset the current and previous pointers.
            Prev = Current; //Move Prev one step forward in the linked list.
            Current = Next; //Move current one step forward in the linked list.
        }
    Head = Prev; //After exiting the loop, set the Head pointer to the last node, which happens to be the node which is pointed to by Prev.
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
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    insertAtEnd(4);
    printList();
    reverseList();
    cout << endl;
    printList();
    return 0;
}
