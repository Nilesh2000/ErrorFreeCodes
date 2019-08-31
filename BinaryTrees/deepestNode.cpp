//A program to calculate the height or maximum depth of a binary search tree and find the deepest node in the tree.
/*
Outstanding explaination
https://www.youtube.com/watch?time_continue=383&v=TQI_m32_AeU
*/
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
