//A program to check if a binary tree is a perfect binary tree.
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

int depthOfTree(Node *Root)
{
    int d = 0;
    while(Root != NULL)
    {
        d++;
        Root = Root -> Left;
    }
    return d;
}

bool isPerfect(Node *Root, int Depth, int Lvl = 0)
{
    if(Root == NULL) //If the tree/subtree is empty, then it is perfect.
      return true;

    if(Root -> Left == NULL && Root -> Right == NULL) //If the left and right children of a node are NULL, that is if it is a leaf node, it should have same
                                                     //depth as the other leaf nodes.
      return (Depth == Lvl + 1);

    if(Root -> Left == NULL || Root -> Right == NULL)
      return false;

    return isPerfect(Root -> Left, Depth, Lvl + 1) && isPerfect(Root -> Right, Depth, Lvl + 1);
}

//Driver function
int main(void)
{
    Node *Root = newNode(1);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);
    Root -> Right -> Left = newNode(6);
    //Root -> Right -> Right = newNode(7);
    int Depth = depthOfTree(Root);
    cout << isPerfect(Root, Depth);
    return 0;
}
