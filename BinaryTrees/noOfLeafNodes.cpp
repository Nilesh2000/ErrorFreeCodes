//A program to count the number of leaf nodes located in a binary tree.
//A leaf node is a node which has no children.
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

int noOfLeadNodes(Node *Root)
{
    if(Root == NULL)
      return 0;

    if(Root -> Left == NULL && Root -> Right == NULL)
      return 1;

    int lCount = noOfLeafNodes(Root -> Left);
    int rCount = noOfLeafNodes(Root -> Right);
    return lCount + rCount;
}

int main(void)
{
    Node *Root = newNode(1);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);
    Root -> Left -> Left -> Right = newNode(7);
    cout << "\nThe number of leaf nodes in the binary tree is : " << noOfLeafNodes(Root);
    return 0;
}
