//A program to find the size of a binary tree.
//Size of a binary tree refers to the number of nodes in the binary tree.
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

int sizeOfTree(Node *Root)
{
    if(Root == NULL)
      return 0;

    int lSize = sizeOfTree(Root -> Left);
    int rSize = sizeOfTree(Root -> Right);
    return (lSize + rSize + 1);
}

int main(void)
{
    Node *Root = newNode(1);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);
    Root -> Left -> Left -> Right = newNode(7);
    cout << "\nThe size of the binary tree is : " << sizeOfTree(Root);
    return 0;
}
