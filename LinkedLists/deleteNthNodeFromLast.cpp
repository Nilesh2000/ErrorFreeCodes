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

//The idea here is to maintain two pointers, namely a reference pointer and another main pointer. Move the reference pointer n nodes from the head. Then, start
//moving the main pointer from the head and the reference pointer simultaneously until the reference pointer till the reference pointer reaches the end of the
//list. During this process, keep a track of the previous pointer of Main_Ptr as we need to set Prev_Ptr -> next to Main_ptr -> next for the deletion to occur.
void deleteNthNodeFromEnd(int Pos)
{
    Node *Main_Ptr = Head, *Ref_Ptr = Head, *Prev;
    //The head node is the last node from the end of the list.
    if(Pos == lengthOfList()) //If asked to delete head node,
    {
        Head = Main_Ptr -> Next; //Store the address of the second node in Head.
        delete Main_Ptr; //Delete the memory for the first node.
        return ; //Exit from the function.
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

//Driver function
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
//End of program
