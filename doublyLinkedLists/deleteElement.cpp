//A program to delete an delete an element from a doubly linked list.
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

void deleteElement(int Value)
{
    Node *Temp = Head;

    if(Temp != NULL && Temp -> Data == Value) //If element to be deleted is contained in the last node,
    {
        Head = Temp -> Next; //Store the address of the second node in Head.
        Temp -> Next -> Prev = NULL; //Set the prev pointer of the second node to NULL.
        delete Temp; //Deallocate memory for Temp.
        return ; //Exit from the function
    }

    while(Temp -> Data != Value && Temp != NULL) //Traverse until the end of the linked list.
    {
        Temp = Temp -> Next; //Move to the next element of the linked list.
    }
    //If x is found, Temp is now pointing to the node which contains x.

    if(Temp == NULL) //x was not present in the linked list.
    {
        return ; //Exit from the function
    }

    if(Temp -> Next == NULL) //If the data is contained in the last node.
    {
      Temp -> Prev -> Next = Temp -> Next; //Set the Next pointer of the previous node to the next pointer of Temp (which happens to be NULL)
      delete Temp; //Deallocate memory for Temp.
      return ; //Exit from the function
    }

    Temp -> Prev -> Next = Temp -> Next; //Set the Next pointer of the previous node to the next pointer of Temp (which happens to be NULL)
    Temp -> Next -> Prev = Temp -> Prev; //Set the Previous pointer of the next node to the previous pointer of Temp.
    delete Temp; //Deallocate memory for Temp.
}

void printList()
{
  //Traversal in forward dierection.
    Node *Temp = Head;
    cout << "\nTraversal in forward dierection : ";
    while(Temp != NULL)
    {
      cout << Temp -> Data << " " ;
      Temp = Temp -> Next;
    }
}

int main(void)
{
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    printList();
    deleteElement(5);
    printList();
    return 0;
}
