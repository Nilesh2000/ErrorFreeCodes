//Program to insert data in a sorted fashion in a doubly linked list.
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Prev, *Next;
};

Node *Head = NULL; //List is initially empty.

void sortedInsert(int x)
{
    Node *newNode = new Node(); //Allocate memory for node to be inserted
    newNode -> Data = x; //Set the data part of the new node to x.
    newNode -> Prev = newNode -> Next = NULL; //Set the next and previous pointer initially to NULL.

    if(Head == NULL) //If the list is initially empty
    {
        Head = newNode; //Store the address of newNode in Head
        return ; //Exit from the function
    }

    if(Head -> Data > x) //If the data in the head node is greater than the data to be inserted, then the new node has to be the first node.
    {
        newNode -> Next = Head; //Store the address of the Head pointer in the next pointer of the newly allocated node.
        newNode -> Next -> Prev = newNode; //Set the Prev pointer of the second node to the new first node.
        Head = newNode; //Store the address of the newNode in Head.
        return ; //Exit from the function
    }

    Node *Cur = Head; //Create a temporary pointer to traverse the list.

    while(Cur -> Next != NULL && Cur -> Next -> Data < x) //Traverse the list until you find the an appropriate position for insertion.
    {
        Cur = Cur -> Next;
    }

    //Cur now points to the node after which the insertion has to take place.

    newNode -> Next = Cur -> Next; //Set the next pointer of newNode to the next pointer of Cur.

    if(Cur -> Next != NULL) //If the node is to be inserted at the end of the list, the statement should not be executed.
      newNode -> Next -> Prev = newNode;

    newNode -> Prev = Cur; //Set the Prev pointer of the new node to to Cur.
    Cur -> Next = newNode; //Set the next pointer of Cur to the newly allocated node.
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
    sortedInsert(2);
    sortedInsert(1);
    sortedInsert(5);
    sortedInsert(4);
    printList();
    return 0;
}
