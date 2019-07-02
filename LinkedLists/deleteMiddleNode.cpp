//A program to delete the middle node of a linked list.
//If the list contains odd number of nodes, delete the middle node.
//If the list contains even number of nodes, delete the second middle node.
//If the list is empty, return NULL.
//If the list conatins, only one node, delete that node.
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

void deleteMiddleNode()
{
    if(Head == NULL) //If list is empty, exit from the function.
      return ;
    if(Head -> Next == NULL) //If the list contains only one node, delete that node by setting Head to NULL.
    {
        Head = NULL;
    }

    Node *slowPtr, *fastPtr, *Prev = NULL;
    slowPtr = fastPtr = Head;

    //Use the fast pointer - slow pointer method to determine the middle node.
    //Also, maintain a variable to tarck the previous of the middle node.
    while(fastPtr != NULL && fastPtr -> Next != NULL)
    {
        fastPtr = fastPtr -> Next -> Next;
        Prev = slowPtr;
        slowPtr = slowPtr -> Next;
    }

    Prev -> Next = slowPtr -> Next; 
    delete slowPtr;
}

int main(void)
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    deleteMiddleNode();
    printList();
    return 0;
}
