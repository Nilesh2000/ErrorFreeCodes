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
    Node *Temp1 = Head;
    cout << "\nTraversal in forward dierection : ";
    while(Temp1 != NULL)
    {
      cout << Temp1 -> Data << " " ;
      Temp1 = Temp1 -> Next;
    }
}

void deleteDuplicates()
{
    Node *Temp = Head, *Dup;
    while(Temp -> Next != NULL)
    {
        if(Temp -> Data == Temp -> Next -> Data)
        {
            Dup = Temp -> Next;
            Temp -> Next = Dup -> Next;
            Dup -> Next -> Prev = Temp;
            delete(Dup);
        }
        else
        {
            Temp = Temp -> Next;
        }
    }
}

int main(void)
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(7);
    insertAtEnd(8);
    printList();
    deleteDuplicates();
    printList();
    return 0;
}
