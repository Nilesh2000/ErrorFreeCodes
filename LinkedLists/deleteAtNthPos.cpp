//A program to delete a node at the nth position of a linked list.
#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

Node *Head = NULL;

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

void deleteAtPos(int Pos)
{
    Node *Temp1 = Head; //Set a temporary variable pointing to Head.
    if (Pos == 1)       //If the first node is to be Deleted
    {
        Head = Temp1->Next; //Head Is now pointing to the second node since Temp1 -> Next stores the address of the
                            //second node in the linked list.
        free(Temp1);        //Deallocate memory for the Node Temp1.
        return;
    }
    for (int i = 1; i < Pos - 1; i++) //Traverse the linked list Pos - 2 times.
    {
        Temp1 = Temp1->Next; //Keep moving to the next node of the linked list.
    }
    //Temp1 now points to the (n - 1)th node.
    Node *Temp2 = Temp1->Next; //Temp2 points to the nth node since Temp1 -> Next stores the address of the next node in
                               //the linked list.
    Temp1->Next = Temp2->Next; //Temp2 -> Next stores the address of the (n + 1)st node. Thus, a link between the
                               //(n - 1)th node and (n + 1)th node is created.
    delete Temp2;              //Deallocate memory for the Node Temp2
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

int main(void)
{
    int n;
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    insertAtEnd(4);
    printList();
    cout << "\nEnter The Position At Which The Node Is To Be Deleted : ";
    cin >> n;
    deleteAtPos(n);
    printList();
}
