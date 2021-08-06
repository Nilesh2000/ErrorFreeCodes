/*
Program to insert all the elements of a sorted linked list into a BST
*/

#include <iostream>

using namespace std;

struct Node
{
    int Data;
    struct Node *Next;
};

struct BSTNode
{
    int Data;
    struct BSTNode *Left, *Right;
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
        lastNode = lastNode->Next;

    lastNode->Next = Temp;
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

Node *middleOfList(Node *Head, Node *Tail)
{
    Node *slowPtr, *fastPtr;
    slowPtr = fastPtr = Head;
    while (fastPtr != Tail && fastPtr->Next != Tail)
    {
        slowPtr = slowPtr->Next;
        fastPtr = fastPtr->Next->Next;
    }
    return slowPtr;
}

// Helper Method to allocate memory for a new tree node
BSTNode *newNode(int x)
{
    BSTNode *Temp = new BSTNode();
    Temp->Data = x;
    Temp->Left = Temp->Right = NULL;
    return Temp;
}

BSTNode *sortedLinkedListToBST(BSTNode *Root, Node *Head, Node *Tail)
{
    // Base Case
    if (Head == Tail)
        return NULL;

    // Find the Middle Node
    Node *MidNode = middleOfList(Head, Tail);

    // Store the data in middle node in root of tree/subtree
    Root = newNode(MidNode->Data);

    // Left Subtree stores the middle element of the left half
    Root->Left = sortedLinkedListToBST(Root, Head, MidNode);

    // Right Subtree stores the middle element of the right half
    Root->Right = sortedLinkedListToBST(Root, MidNode->Next, Tail);

    // Return Root Node
    return Root;
}

void inorderTraversal(BSTNode *Root)
{
    if (Root == NULL)
        return;
    inorderTraversal(Root->Left);
    cout << Root->Data << " ";
    inorderTraversal(Root->Right);
}

int main(void)
{
    Node *Head = NULL;

    Head = insertAtEnd(Head, 1);
    Head = insertAtEnd(Head, 2);
    Head = insertAtEnd(Head, 3);
    Head = insertAtEnd(Head, 4);
    Head = insertAtEnd(Head, 5);
    Head = insertAtEnd(Head, 6);
    Head = insertAtEnd(Head, 7);
    cout << "Linked List : ";
    printList(Head);

    BSTNode *Root = NULL;
    Root = sortedLinkedListToBST(Root, Head, NULL);

    cout << "\nInorder Traversal of BST : ";
    inorderTraversal(Root);

    return 0;
}
