//A program to calculate the length of a linked list.
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

//Iterative Implementation
int lengthList(Node *A)
{
  int Count = 0;
    while(A != NULL)
      {
          Count++;
          A = A -> Next;
      }
  return Count;
}

//Recursive Implementation
int lengthOfList(Node *A)
{
    if(A == NULL)
      {
          return 0;
      }
  return 1 + lengthOfList(A -> Next); //Count is 1 + length of the remaining list.
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
    insertAtEnd(9);
    printList();
    cout << "\nThe Length Of The Linked List Is : " << lengthList(Head) << endl;
    cout << "The Length Of The Linked List Is : " << lengthOfList(Head) << endl;
}
