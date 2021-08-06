// Program to delete a node from a linked list in O(1) time.
// The address of the node to be deleted is given
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

    Node *lastNode = Head; //Set a temporary variable of type Node pointing to Head.

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

void deleteNode(Node *delNode)
{
    Node *Temp = delNode->Next;
    delNode->Data = Temp->Data;
    delNode->Next = Temp->Next;
    delete Temp;
}

int main(void)
{
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtEnd(7);
    printList();
    deleteNode(Head->Next->Next);
    cout << "\n";
    printList();
    return 0;
}
