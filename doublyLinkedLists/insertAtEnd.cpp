//A program to insert a node at the beginning of a list.
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Prev, *Next;
};

Node *Head = NULL; //List is initially empty.

void insertAtEnd(int x)
{
    Node *newNode = new Node(); //Allocate memory to create a new node.
    newNode -> Data = x; //Initialize the Data of the node to the parameter passed.

    if(Head == NULL) //Check if list is initially empty,
    {
        newNode -> Prev = NULL; //Set the previous pointer of the newly allocated node to NULL.
        Head = newNode; //Save the address of the newly allocated node in Head.
        return ; //Exit from the function
    }

    Node *Temp = Head; //Create a temporary pointer to traverse the list.
    while(Temp -> Next != NULL) //Traverse the list till you reach the last node. (Stop when you reach the last node)
    {
        Temp = Temp -> Next;
    }
    Temp -> Next = newNode; //Set the next pointer of the last node to the new node.
    newNode -> Prev = Temp; //Set the previous pointer of the newly allocated node to the second last node.
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
        cout << Temp2 Data << " ";
        Temp2 = Temp2 -> Prev;
    }
}

int main(void)
{
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    printList();
    return 0;
}
