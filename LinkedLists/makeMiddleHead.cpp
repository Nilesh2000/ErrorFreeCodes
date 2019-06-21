//A program to make the middle node of the linked list as the head node.
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
    cout << endl;
}

//Figure out the middle node using slow-fast pointer method and also keep a track of the previous pointer using a variable. The Node
//before the middle node can be called Prev.
void makeMiddleHead()
{
    Node *Slow_Ptr = Head, *Fast_Ptr = Head, *Prev = NULL;
    while(Fast_Ptr != NULL && Fast_Ptr -> Next != NULL)
    {
        Prev = Slow_Ptr;
        Slow_Ptr = Slow_Ptr -> Next;
        Fast_Ptr = Fast_Ptr -> Next -> Next;
    }
    Prev -> Next = Prev -> Next -> Next; //Set the Prev -> Next to the address of the node after the middle node which is
                                         //Prev -> Next -> Next
    Slow_Ptr -> Next = Head; //Set Slow_Ptr-> Next to the address of the current first node.
    Head = Slow_Ptr; //Set the address of Slow_Ptr to Head so that the middle node is now the new first node.
}

int main(void)
{
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    printList();
    makeMiddleHead();
    printList();
    return 0;
}
