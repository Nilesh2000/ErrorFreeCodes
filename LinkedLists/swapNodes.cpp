/*
Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may be expensive in
many situations when data contains many fields.

This may look a simple problem, but is interesting question as it has following cases to be handled.
1) x and y may or may not be adjacent.
2) Either x or y may be a head node.
3) Either x or y may be last node.
4) x and/or y may not be present in linked list.
*/
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

void swapNodes(int x, int y)
{
    if(x == y)
    {
        cout << "Both the nodes are equal.\n";
        return ;
    }

    Node *curX = Head, *curY = Head, *prevX = NULL, *prevY = NULL;
    //Search for the location of both the nodes. Keep track of their respective previous pointers too.
    while(curX -> Data != x && curX != NULL)
    {
        prevX = curX;
        curX = curX -> Next;
    }
    while(curY -> Data != y && curY != NULL)
    {
        prevY = curY;
        curY = curY -> Next;
    }

    if(curX == NULL || curY == NULL)
    {
      cout << "x or y is not present in the list.\n";
      return ;
    }

    //If x is not a head node
    if(prevX != NULL)
    {
        prevX -> Next = curY;
    }
    else
    {
        Head = curY;
    }

    //If y is not a head node
    if(prevY != NULL)
    {
        prevY -> Next = curX;
    }
    else
    {
        Head = curX;
    }

    //Swap the next pointers of the respective nodes
    Node *Temp = curY -> Next;
    curY -> Next = curX -> Next;
    curX -> Next = Temp;
}

int main(void)
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(8);
    cout << "\nList after swapping 2 and 5 : ";
    swapNodes(2, 5);
    printList();
    cout << "\nSwapping 7 and 7 : ";
    swapNodes(7, 7);
    printList();
    cout << "\nSwapping 8 (last node) with 4 : ";
    swapNodes(4, 8);
    printList();
    cout << "\nSwapping 1 (Head node) and 3 : ";
    swapNodes(1, 3);
    printList();
    return 0;
}
