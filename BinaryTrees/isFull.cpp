//A program to check if a binary tree is a full binary tree.
# include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Left, *Right;
};

//Function to allocate memory for a new node.
Node* newNode(int Data)
{
    Node *newNode = new Node(); //Memory allocation for new node.
    newNode -> Data = Data;
    newNode -> Left = newNode -> Right = NULL;
    return newNode;
}

bool isFull(Node *Root)
{
    if(Root == NULL)
      return true;

    if(Root -> Left == NULL && Root -> Right == NULL)
      return true;

    if(Root -> Left && Root -> Right)
      return (isFull(Root -> Left) && isFull(Root -> Right));

    return false;
}
int main(void)
{
    Node *Root = newNode(1);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);
    cout << isFull(Root);
    return 0;
}
