//A program to print a linked list in the forward and reverse manner using recursion.
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

void forwardPrint(Node *A)
{
      if(A == NULL)
        {
            return ;
        }
    cout << A -> Data << " "; //Print the value present in the node.
    forwardPrint(A -> Next); //Recursive call to the function.
}

/*
The underlying principle to print the linked list in reverse order is that we traverse the linked list in a recursive way until the end of the list
has been reached. After that, we print the data present in each node.
*/

void reversePrint(Node *A)
{
    if(A == NULL)
      {
          return ;
      }
    reversePrint(A -> Next);
    cout << A -> Data << " ";
}

int main(void)
{
  insertAtEnd(2);
  insertAtEnd(3);
  insertAtEnd(5);
  insertAtEnd(7);
  insertAtEnd(4);
  forwardPrint(Head);
  cout << endl;
  reversePrint(Head);
  cout << endl;
}
