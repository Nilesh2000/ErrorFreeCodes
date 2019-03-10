//A program to remove duplicates from an unsorted linked list.
//This type of removal preserves the original order of the linked list.
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

Node *Head = NULL; //List is initially empty.

void removeDuplicates()
{
    Node *Ptr1 = Head, *Ptr2, *Dup; //Declare 3 pointers
    //Ptr1 to traverse the list, Ptr2 to compare every element of the list, Dup to delete the pointer which is a duplicate.

      while(Ptr1 != NULL && Ptr1 -> Next != NULL) //Condition so that the while loop is executed only till the (n-1)th element of the list.
        {
            Ptr2 = Ptr1; //Set Ptr2 to Ptr1 so that Ptr2 can be used to check for duplicates.
              while(Ptr2 -> Next != NULL) //Go till the nth node of the linked list.
                {
                    if(Ptr1 -> Data == Ptr2 -> Next -> Data) //If the data initially in Ptr1 is equal to the data stored in Ptr2,
                      {
                          Dup = Ptr2 -> Next; //Set the Node to be deleted as Dup
                          Ptr2 -> Next = Ptr2 -> Next -> Next; //We use next twice here because we intened to delete the duplicate element.
                          delete(Dup); //Delete the duplicate node.
                      }
                    else
                      {
                          Ptr2 = Ptr2 -> Next; //Else just go to the next element in the list.
                      }
                }
            Ptr1 = Ptr1 -> Next;
        }
}

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

int main(void)
{
    insertAtEnd(10);
    insertAtEnd(12);
    insertAtEnd(11);
    insertAtEnd(10);
    insertAtEnd(12);
    insertAtEnd(12);
    insertAtEnd(11);
    insertAtEnd(10);
    printList();
    cout << endl;
    removeDuplicates();
    printList();
    return 0;
}
