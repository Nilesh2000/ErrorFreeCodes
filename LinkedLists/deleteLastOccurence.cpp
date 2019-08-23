//A program to delete the last occurrence of a particular element in a linked list.
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

void printList()
{
    Node *Temp = Head;
      while(Temp != NULL)
        {
            cout << Temp -> Data << " ";
            Temp = Temp -> Next;
        }
}

void deleteLastOccurence(int x)
{
    Node *Pos = NULL, *Temp = Head;
    while(Temp -> Next != NULL)
    {
        if(Temp -> Data == x)
        {
            Pos = Temp;
        }
        Temp = Temp -> Next;
    }

    //If node to be deleted is the last node,
    if(Pos != NULL && Pos -> Next == NULL)
    {
        Temp = Head;
        while(Temp -> Next != Pos)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NULL;
    }

    //If node to be deleted is the last node
    if(Pos != NULL && Pos -> Next != NULL)
    {
        Pos -> Data = Pos -> Next -> Data;
        Temp = Pos -> Next;
        Pos -> Next = Pos -> Next -> Next;
        delete Temp;
    }
}

int main(void)
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(3);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(3);
    printList();
    cout << endl;
    deleteLastOccurence(3);
    printList();
    return 0;
}
//End of program
