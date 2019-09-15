//A program to check if a binary tree is a height balanced binary tree.
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

int heightOfTree(Node *node)
{
    if(node == NULL)
      return 0;

    return 1 + max(heightOfTree(node -> Left), heightOfTree(node -> Right));
}

/*
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.
*/
bool isHeightBalanced(Node *Root)
{
    if(Root == NULL)
      return true;

    int leftHeight = heightOfTree(Root -> Left);
    int rightHeight = heightOfTree(Root -> Right);

    if(abs(leftHeight - rightHeight) <= 1 && isHeightBalanced(Root -> Left) && isHeightBalanced(Root -> Right))
      return true;

    return false;
}

int main(void)
{
    Node *Root = newNode(1);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);
    Root -> Left -> Right -> Left = newNode(6);
    cout << isHeightBalanced(Root);
    return 0;
}
