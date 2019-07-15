//A program to check if a specific element is present in the linked list.
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

void findElement(int x)
{
    Node *Temp = Head;
    while(Temp -> Next != NULL && Temp -> Data != x)
    {
        Temp = Temp -> Next;
    }
    if(Temp -> Next == NULL)
      cout << "\nElement not present in the linked list.";
    else
      cout << "\nElement present in the linked list.";
}

int main(void)
{
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    insertAtEnd(9);
    insertAtEnd(11);
    findElement(3);
    findElement(6);
    return 0;
}
