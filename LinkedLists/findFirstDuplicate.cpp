//A program to display the first duplicate node in a linked list.
# include <iostream>
# include <unordered_map>

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

void findFirstDuplicate()
{
    unordered_map <int, int> M;
    Node *Temp = Head;
    while(Temp != NULL)
    {
        M[Temp -> Data]++;
        Temp = Temp -> Next;
    }

    Temp = Head;
    while(Temp != NULL)
    {
        if(M[Temp -> Data] > 1)
        {
            cout << "\nThe first duplicate element is : " << Temp -> Data;
            return ;
        }
        Temp = Temp -> Next;
    }
    cout << "\nAll nodes are unique.";
}

int main(void)
{
    insertAtEnd(1);
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    //insertAtEnd(1);
    insertAtEnd(9);
    insertAtEnd(11);
    insertAtEnd(13);
    //insertAtEnd(7);
    insertAtEnd(15);
    findFirstDuplicate();
    return 0;
}
