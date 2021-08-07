/*
Program to find the number of nodes and sum of values of the nodes with a value in the inclusive range of [low, high] in the BST

Time Complexity : O(n)
Space Complexity : O(h)
*/

#include <iostream>
#include <vector>

using namespace std;

struct BstNode
{
    int Data;
    BstNode *Left, *Right;
};

//Function to allocate memory for a new node.
BstNode *newNode(int Data)
{
    BstNode *newNode = new BstNode(); //Memory allocation for new node.
    newNode->Data = Data;
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

BstNode *insertNewNode(BstNode *Root, int Data)
{
    if (Root == NULL) //If the tree or subtree has no elements
        return newNode(Data);

    if (Root->Data >= Data) //If data stored in the root node is greater than the data to be inserted, make sure to insert the new node in the left subtree.
    {
        Root->Left = insertNewNode(Root->Left, Data);
    }
    else //Else, just insert it into the right subtree.
    {
        Root->Right = insertNewNode(Root->Right, Data);
    }
    return Root; //Return address of the root node every time a new node is inserted in the tree..
}

int rangeSum(BstNode *Root, int Low, int High)
{
    if (Root == NULL)
        return 0;

    if (Root->Data > High)
        return rangeSum(Root->Left, Low, High);
    else if (Root->Data < Low)
        return rangeSum(Root->Right, Low, High);
    return Root->Data + rangeSum(Root->Left, Low, High) + rangeSum(Root->Right, Low, High);
}

int noOfNodes(BstNode *Root, int Low, int High)
{
    if (Root == NULL)
        return 0;

    if (Root->Data > High)
        return noOfNodes(Root->Left, Low, High);
    else if (Root->Data < Low)
        return noOfNodes(Root->Right, Low, High);
    return 1 + noOfNodes(Root->Left, Low, High) + noOfNodes(Root->Right, Low, High);
}

int main(void)
{
    BstNode *Root = NULL;
    Root = insertNewNode(Root, 4);
    Root = insertNewNode(Root, 2);
    Root = insertNewNode(Root, 6);
    Root = insertNewNode(Root, 1);
    Root = insertNewNode(Root, 3);
    Root = insertNewNode(Root, 5);
    Root = insertNewNode(Root, 7);

    cout << "The sum of all nodes which have values in the range of 3 and 7 is : " << rangeSum(Root, 3, 7);
    cout << "\nThe total number of nodes in having values in the range of 5 and 7 is : " << noOfNodes(Root, 5, 7);
    return 0;
}
