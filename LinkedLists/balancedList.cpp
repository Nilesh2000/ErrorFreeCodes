/*
A program to check if a given linked list is a balanced list.
A linked list is called balanced if there exists a node where the sum of all the nodes on its left is equal to the sum of all the node on its right,
if no such node is found then print -1.
*/
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

/*
The logic here is as follows:-
1. First, find the total sum of the all node values.
2. Now, traverse the linked list one by one and while traversing keep track of all the previous nodes value sum and find the sum of the remaining node by
subtracting current node value and the sum of the previous nodes value from the total sum.
3. Compare both the sums, if they are equal then current node is the required node else print -1.
*/

void balancedList()
{
    Node *Temp = Head;
    int Sum = 0, tempSum = 0;
    while (Temp != NULL)
    {
        Sum += (Temp->Data);
        Temp = Temp->Next;
    }

    Temp = Head;
    while (Temp != NULL)
    {
        int x = Temp->Data;
        if (tempSum == Sum - tempSum - x)
        {
            cout << "\nThe linked list is balanced at the element " << Temp->Data;
            return;
        }
        tempSum += x;
        Temp = Temp->Next;
    }
    cout << "\nThe linked list is not balanced.";
}

int main(void)
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(7);
    insertAtEnd(10);
    insertAtEnd(1);
    insertAtEnd(6);
    insertAtEnd(3);
    balancedList();
    return 0;
}
