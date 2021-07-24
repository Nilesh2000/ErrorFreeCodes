//A program to get the intersection (common elements) of two sorted linked lists.
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

Node *sortedIntersection(Node *Head1, Node *Head2)
{
    // Base Case
    if (Head1 == NULL || Head2 == NULL)
        return NULL;

    if (Head1->Data < Head2->Data)
        return sortedIntersection(Head1->Next, Head2);

    if (Head1->Data > Head2->Data)
        return sortedIntersection(Head1, Head2->Next);

    // Below lines are executed only when Head1->Data==Head2->Data
    Node *Temp = new Node();
    Temp->Data = Head1->Data;

    Temp->Next = sortedIntersection(Head1->Next, Head2->Next);

    return Temp;
}

int main(void)
{
    Node *Head1 = NULL;
    Node *Head2 = NULL;

    insertAtEnd(&Head1, 10);
    insertAtEnd(&Head1, 20);
    insertAtEnd(&Head1, 30);
    insertAtEnd(&Head1, 40);
    printList(Head1);
    cout << endl;

    insertAtEnd(&Head2, 20);
    insertAtEnd(&Head2, 30);
    insertAtEnd(&Head2, 40);
    insertAtEnd(&Head2, 50);
    insertAtEnd(&Head2, 60);
    printList(Head2);
    cout << endl;

    Node *IntersectList = sortedIntersection(Head1, Head2);
    printList(IntersectList);
    cout << endl;

    return 0;
}
