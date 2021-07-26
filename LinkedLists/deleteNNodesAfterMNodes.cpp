// Program to Delete N nodes after every M nodes of a linked list
#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

Node *insertAtEnd(Node *Head, int x)
{
    Node *Temp = new Node();
    Temp->Data = x;
    Temp->Next = NULL;

    if (Head == NULL)
    {
        Head = Temp;
        return Head;
    }

    Node *lastNode = Head;
    while (lastNode->Next != NULL)
    {
        lastNode = lastNode->Next;
    }

    lastNode->Next = Temp;
    return Head;
}

Node *deleteNNodesAfterMNodes(Node *Head, int M, int N)
{
    Node *Temp = Head;
    while (Temp != NULL)
    {
        // Skip M nodes
        for (int count = 1; count < M && Temp != NULL; count++)
        {
            Temp = Temp->Next;
        }

        // If we reach end of list, exit
        if (Temp == NULL)
            return Head;

        // Start from next node and delete N nodes
        Node *delNodes = Temp->Next;

        for (int count = 1; count <= N && delNodes != NULL; count++)
        {
            Node *d = delNodes;
            delNodes = delNodes->Next;
            free(d);
        }

        // Link previous node with remaining node
        Temp->Next = delNodes;
        // Set current node for next iteration
        Temp = delNodes;
    }

    return Head;
}

void printList(Node *Head)
{
    while (Head != NULL)
    {
        cout << Head->Data << " ";
        Head = Head->Next;
    }
}

int main(void)
{
    int M = 2, N = 2;
    Node *Head = NULL;

    Head = insertAtEnd(Head, 1);
    Head = insertAtEnd(Head, 2);
    Head = insertAtEnd(Head, 3);
    Head = insertAtEnd(Head, 4);
    Head = insertAtEnd(Head, 5);
    Head = insertAtEnd(Head, 6);
    Head = insertAtEnd(Head, 7);
    Head = insertAtEnd(Head, 8);
    Head = insertAtEnd(Head, 9);
    Head = insertAtEnd(Head, 10);

    printList(Head);
    cout << "\n";

    Head = deleteNNodesAfterMNodes(Head, M, N);
    printList(Head);

    return 0;
}
