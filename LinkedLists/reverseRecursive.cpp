//A program to reverse the elements of a linked list using a recursive function.
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

//The recursive function reverses the linked list from the last to the first.

void reverseList(Node *A) //Recursive function to reverse a linked list.
{
     if(A -> Next == NULL) //When the last node is reached,
       {
           Head = A; //Set the head pointer pointing to the address of the last node.
           return ; //Exit from the function.
       }
    reverseList(A -> Next);

    //These statements will only start executing once the base condition of the recursion has been met.
    //Traversing the list in the backward direction.

    Node *Temp = A -> Next; //Store the address of thr current node in a temporary variable.
    Temp -> Next = A; //Make the current node point to the previous node.
    A -> Next = NULL; //Make the previous node point to NULL.
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

int  main(void)
{
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    printList();
    cout << endl;
    reverseList(Head);
    printList();
}
