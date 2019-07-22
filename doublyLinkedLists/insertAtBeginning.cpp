//A program to insert a node at the beginning of a list.
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Prev, *Next;
};

Node *Head = NULL; //List is initially empty.

void insertAtBeginning(int x)
{
    Node *newNode = new Node(); //Allocate memory to create a new node.
    newNode -> Data = x; //Initialize the Data of the node to the parameter passed.
    newNode -> Prev = NULL; //Set the previous pointer of the newNode to NULL.
    newNode -> Next = Head; //Store the address of the first node in the newly created node which will therafter be the first node.
    if(Head != NULL) //If the list is not empty,
    {
        Head -> Prev = newNode; //Set the Prev of the initially first node to the newly allocated node.
    }
    Head = newNode;  //The address of the new first node is stored in Head.
}

void printList()
{
  //Traversal in forward dierection.
    Node *Temp1 = Head, *Temp2;
    cout << "\nTraversal in forward dierection : ";
    while(Temp1 != NULL)
    {
      cout << Temp1 -> Data << " " ;
      Temp2 = Temp1;
      Temp1 = Temp1 -> Next;
    }

  //Traversal in reverse dierection
    cout << "\nTraversal in reverse dierection : ";
    while(Temp2 != NULL)
    {
        cout << Temp2 -> Data << " ";
        Temp2 = Temp2 -> Prev;
    }
}

int main(void)
{
    insertAtBeginning(2);
    insertAtBeginning(3);
    insertAtBeginning(4);
    insertAtBeginning(5);
    printList();
    return 0;
}
