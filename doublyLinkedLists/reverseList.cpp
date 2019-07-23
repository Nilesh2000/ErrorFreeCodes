//A program to reverse a doubly linked list.
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

void reverseList()
{
    //Declare two variable (Temp is initially NULL and Cur initially points to Head)
    Node *Temp = NULL, *Cur = Head;

    while(Cur != NULL) //Traverse till the end of the list
    {
        Temp = Cur -> Prev; //Set the address of Cur -> Prev to a temporary variable.
        Cur -> Prev = Cur -> Next; //Set the address of Cur -> Next to Cur -> Prev. The value of Cur -> Prev is not lost since it is stored in temp.
        Cur -> Next = Temp; //Store the address of Cur -> Next in temp.
        Cur = Cur -> Prev; //Continue to traverse the list. We don't use Cur = Cur -> Next here because we are reversing the list.
    }

    //Before changing head, check for the cases like empty list and list with only one node
    if(Temp != NULL)
      Head = Temp -> Prev;
}

void printList()
{
  //Traversal in forward dierection.
    Node *Temp1 = Head;
    while(Temp1 != NULL)
    {
      cout << Temp1 -> Data << " " ;
      Temp1 = Temp1 -> Next;
    }
}

int main(void)
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    cout << "Original List : ";
    printList();
    reverseList();
    cout << "\nReversed List : ";
    printList();
    return 0;
}
//End of program
