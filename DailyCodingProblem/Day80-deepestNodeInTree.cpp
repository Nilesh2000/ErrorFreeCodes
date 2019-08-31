//Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.
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

int findHeight(Node* Root)
{
    if(Root == NULL)
      return 0;

    int leftDepth = findHeight(Root -> Left);
    int rightDepth = findHeight(Root -> Right);

    return max(leftDepth, rightDepth) + 1;
}

/*
The logic here is to find the height of the tree and then recursively go till the node at the deepest level.
*/
void findDeepestNode(Node* Root, int Levels)
{
    if(!Root)
      return;

    if(Levels == 1)
    cout << Root -> Data;

    else if(Levels > 1)
    {
        findDeepestNode(Root -> Left, Levels - 1);
        findDeepestNode(Root -> Right, Levels - 1);
    }
}

int main(void) //Driver function
{
    Node *Root = newNode(1);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);
    Root -> Left -> Left -> Right = newNode(7);
    int Height = findHeight(Root);
    cout << "\nThe deepest node in the tree is : ";
    findDeepestNode(Root, Height);
    return 0;
}
