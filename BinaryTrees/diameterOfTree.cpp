/*
Diameter of a Tree is the longest path between two end nodes in a tree.
It is not necessary that the path needs to pass through the root of the binary tree.

The node at which the sum of the height of the left subtree and height of the right subtree is maximum, that sum is the diameter of the tree.

Time Complexity : O(N)
Space Complexity : O(1)
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

int diameterOfTreeRecur(Node *Root, int &Diameter)
{
    if (Root == NULL)
        return 0;

    // Find the height of the left and right subtree at that node
    int leftHeight = diameterOfTreeRecur(Root->Left, Diameter);
    int rightHeight = diameterOfTreeRecur(Root->Right, Diameter);

    // Check if the sum of the leftHeight and rightHeight exceeds the existing Diameter
    Diameter = max(Diameter, leftHeight + rightHeight);

    // Return height of the subtree
    return 1 + max(leftHeight, rightHeight);

    // We use this returned value only in the recursive function and we do not return our final function call to the calling environment.
    // We need this return statement only to calculate the height of the subtrees and then to calculate diameter
}

int diameterOfTree(Node *Root)
{
    int Diameter = 0;
    diameterOfTreeRecur(Root, Diameter);
    return Diameter;
}

int main(void)
{
    Node *Root = newNode(1);
    Root->Left = newNode(2);
    Root->Right = newNode(3);
    Root->Right->Left = newNode(4);
    Root->Right->Left->Left = newNode(5);
    Root->Right->Left->Left->Left = newNode(9);
    Root->Right->Right = newNode(6);
    Root->Right->Right->Right = newNode(7);
    Root->Right->Right->Right->Right = newNode(8);
    cout << diameterOfTree(Root);
    return 0;
}
