//A program to delete all the nodes having the value k

#include <iostream>

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
    Temp->Data = x;          //Initialize the Data of the node to the parameter passed.
    if (Head == NULL)        //Check if the list is initially empty.
    {
        Head = Temp; //Set the address of the newly allocated node to Head.
        return;
    }
    //If the list is not empty,

    Node *lastNode = Head; //Set a temporary variable of type Node to Head.

    while (lastNode->Next != NULL) //Traverse the linked list till the end of the list.
    {
        lastNode = lastNode->Next; //Keep moving to the next node.
    }
    lastNode->Next = Temp; //Set the address of the last node to the newly allocated node in memory.
}

void printList()
{
    Node *Temp = Head;
    while (Temp != NULL)
    {
        cout << Temp->Data << " ";
        Temp = Temp->Next;
    }
}

void deleteKey(int x)
{
    while (Head != NULL && Head->Data == x)
    {
        Head = Head->Next;
    }

    Node *Temp = Head, *Prev = NULL;

    while (Temp != NULL)
    {
        if (Temp->Data == x)
        {
            Prev->Next = Temp->Next;
        }

        Prev = Temp;
        Temp = Temp->Next;
    }
}

//Driver function
int main(void)
{
    insertAtEnd(1);
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(1);
    insertAtEnd(4);
    insertAtEnd(1);
    insertAtEnd(5);
    insertAtEnd(1);
    cout << "\nBefore deletion : ";
    printList();
    deleteKey(1);
    cout << "\nAfter Deletion : ";
    printList();
    return 0;
}
//End of program
