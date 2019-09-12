//A program to convert a binary tree into it's mirror image.
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

void inOrderTraversal(Node *Root)
{
    if(Root == NULL)
      return ;

    inOrderTraversal(Root -> Left);
    cout << Root -> Data << " ";
    inOrderTraversal(Root -> Right);
}

void mirrorOfTree(Node *Root)
{
    if(Root == NULL)
      return ;

    Node *Temp;
    mirrorOfTree(Root -> Left);
    mirrorOfTree(Root -> Right);

    Temp = Root -> Left;
    Root -> Left = Root -> Right;
    Root -> Right = Temp;
}

int main(void)
{
    Node *Root = newNode(1);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);

    cout << "Original Tree : ";
    inOrderTraversal(Root);
    mirrorOfTree(Root);
    cout << "\nMirror Tree : ";
    inOrderTraversal(Root);

    return 0;
}
