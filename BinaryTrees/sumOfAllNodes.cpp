/*
Give a binary tree, find the sum of all nodes present in the binary tree
*/
#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Left, *Right;
};

//Function to allocate memory for a new node.
Node *newNode(int Data)
{
    Node *newNode = new Node(); //Memory allocation for new node.
    newNode->Data = Data;
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

int sumOfNodes(Node *Root)
{
    if (Root == NULL)
        return 0;
    return Root->Data + sumOfNodes(Root->Left) + sumOfNodes(Root->Right);
}

int main(void)
{
    Node *Root = newNode(1);
    Root->Left = newNode(2);
    Root->Right = newNode(3);
    Root->Left->Left = newNode(4);
    Root->Left->Right = newNode(5);
    Root->Right->Left = newNode(6);
    Root->Right->Right = newNode(7);
    cout << sumOfNodes(Root);
    return 0;
}
