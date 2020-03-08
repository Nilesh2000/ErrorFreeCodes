//A program to insert elements at the nth position of a linked list.

#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

Node *Head = NULL; //List is initially empty

void insertAtPos(int x, int n) //Pass the value to be stored and the location to be inserted at.
{
    Node *Temp1 = new Node(); //Allocate memory to create a new node.
    Temp1->Data = x;          //Initialize the Data of the node to the parameter passed.
    Temp1->Next = NULL;       //Initialize the address of the new node to NULL by default.

    //This segment will only be used create a link between the already existing linked list and the new node.

    if (n == 1) //If node is to be inserted at the beginning
    {
        Temp1->Next = Head; //Store the address of the first node in the newly created node which will therafter be the first node.
        Head = Temp1;       //The address of the new first node is stored in Head.
        return;             //Exit from the function
    }

    //If node is to be inserted position n,

    Node *Temp2 = Head; //Set a temporary variable pointing to Head because we don't want to alter the value stored in Head.

    //Set i to the beginning of the linked list.
    for (int i = 1; i < n - 1; i++)
    {
        Temp2 = Temp2->Next; //Traverse the linked list.
    }

    //Linked list has been traversed till the ( n - 1 )th node.
    Temp1->Next = Temp2->Next; //Store the address of ( n - 1 )th node to the memory Allocated node Temp1 because the (n - 1)th node
                               //is currently storing the address of the nth node.
    Temp2->Next = Temp1;       //Store the addrss of the newly created node in the previous node.
}

void printList()
{
    Node *Temp = Head;
    while (Temp != NULL)
    {
        cout << Temp->Data << " ";
        Temp = Temp->Next;
    }
    cout << endl;
}

int main(void)
{
    insertAtPos(2, 1);
    insertAtPos(3, 2);
    insertAtPos(4, 1);
    insertAtPos(5, 2);
    printList();
    return 0;
}
