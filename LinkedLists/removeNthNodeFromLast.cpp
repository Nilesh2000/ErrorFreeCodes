//A program to delete the Nth node from the end of the list.
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

int lengthOfList()
{
    Node *Temp = Head;
    int Count = 1;
    while(Temp -> Next != NULL)
    {
        Count++;
        Temp = Temp -> Next;
    }
    return Count;
}

void deleteNthNodeFromEnd(int Pos)
{
    Node *Main_Ptr = Head, *Ref_Ptr = Head, *Prev;
    if(Pos == lengthOfList())
    {
        Head = Main_Ptr -> Next;
        delete Main_Ptr;
        return ;
    }
    for(int i = 0 ; i < Pos - 1 ; i++)
      Ref_Ptr = Ref_Ptr -> Next;
    while(Ref_Ptr -> Next != NULL)
    {
        Ref_Ptr = Ref_Ptr -> Next;
        Prev = Main_Ptr;
        Main_Ptr = Main_Ptr -> Next;
    }
    Prev -> Next = Main_Ptr -> Next;
    delete Main_Ptr;
}

int main(void)
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    cout << "\nBefore deletion : ";
    printList();
    deleteNthNodeFromEnd(4);
    cout << "\nAfter Deletion : ";
    printList();
    return 0;
}
