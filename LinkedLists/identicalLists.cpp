//A program to check if two lists are identical
#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

void insertAtEnd(Node **A, int x) //A refers to the address of the head node.
{
    Node *Temp = new Node(); //Allocate memory to create a new node.
    Temp->Data = x;          //Initialize the Data of the node to the parameter passed.
    if ((*A) == NULL)        //Check if the list is initially empty.
    {
        (*A) = Temp; //Set the address of the newly allocated node to Head.
        return;
    }
    //If the list is not empty,

    Node *lastNode = *A; //Set a temporary variable of type Node to Head.

    while (lastNode->Next != NULL) //Traverse the linked list till the end of the list.
    {
        lastNode = lastNode->Next; //Keep moving to the next node.
    }
    lastNode->Next = Temp; //Set the address of the last node to the newly allocated node in memory.
}

void printList(Node *Head)
{
    Node *Temp = Head;
    while (Temp != NULL)
    {
        cout << Temp->Data << " ";
        Temp = Temp->Next;
    }
}

void isIdentical(Node *h1, Node *h2)
{
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->Data != h2->Data)
        {
            cout << "\nLists are not identical.";
            return;
        }
        h1 = h1->Next;
        h2 = h2->Next;
    }
    if (h1 == NULL && h2 == NULL)
    {
        cout << "\nLists are identical.";
    }
}

int main(void)
{
    Node *Head1 = NULL;
    Node *Head2 = NULL;
    insertAtEnd(&Head1, 3);
    insertAtEnd(&Head1, 5);
    insertAtEnd(&Head1, 7);
    insertAtEnd(&Head2, 3);
    insertAtEnd(&Head2, 5);
    insertAtEnd(&Head2, 6);
    printList(Head1);
    cout << endl;
    printList(Head2);
    isIdentical(Head1, Head2);
    return 0;
}
