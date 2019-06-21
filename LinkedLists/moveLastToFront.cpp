//A program to move the last element of a linked list to the front of the list.
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

void moveLastToFront()
{
    Node *lastNode = Head, *secondLast = NULL; //Set a variable lastNode initially to Head to traverse the linked list.
                                               //Set secondLast to null initially.
    while(lastNode -> Next != NULL)
    {
        secondLast = lastNode;
        lastNode = lastNode -> Next;
    }
    //At the the end of the loop lastNode points to the last node in the list and secondLast points to node before the last node.
    secondLast -> Next = NULL; //This is done because there are no more nodes after the second last node.
    lastNode -> Next = Head; //This is done because new first node now points to the older first node whose address is stored in Head.
    Head = lastNode; //Set Head to the address of lastNode as lastNode is now the new first node.
}

int main(void)
{
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    printList();
    moveLastToFront();
    printList();
    return 0;
}
