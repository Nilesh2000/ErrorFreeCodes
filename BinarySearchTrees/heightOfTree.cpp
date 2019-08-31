//A program to calculate the height or maximum depth of a binary search tree.
/*
Outstanding explaination
https://www.youtube.com/watch?time_continue=383&v=TQI_m32_AeU
*/
# include <iostream>

using namespace std;

struct BstNode
{
    int Data;
    BstNode *Left, *Right;
};

//Function to allocate memory for a new node.
BstNode* newNode(int Data)
{
    BstNode *newNode = new BstNode(); //Memory allocation for new node.
    newNode -> Data = Data;
    newNode -> Left = newNode -> Right = NULL;
    return newNode;
}

BstNode* insertNewNode(BstNode* Root, int Data)
{
    if(Root == NULL) //If the tree or subtree has no elements
      return newNode(Data);

    if(Root -> Data >= Data) //If data stored in the root node is greater than the data to be inserted, make sure to insert the new node in the left subtree.
    {
        Root -> Left = insertNewNode(Root -> Left, Data);
    }
    else //Else, just insert it into the right subtree.
    {
        Root -> Right = insertNewNode(Root -> Right, Data);
    }
    return Root; //Return address of the root node every time a new node is inserted in the tree..
}

int findHeight(BstNode* Root)
{
    if(Root == NULL)
      return 0;

    int leftDepth = findHeight(Root -> Left);
    int rightDepth = findHeight(Root -> Right);

    return max(leftDepth, rightDepth) + 1;
}

int main(void) //Driver function
{
    BstNode *Root = NULL;
    Root = insertNewNode(Root, 15);
    Root = insertNewNode(Root, 20);
    Root = insertNewNode(Root, 30);
    Root = insertNewNode(Root, 40);
    Root = insertNewNode(Root, 7);
    Root = insertNewNode(Root, 5);
    Root = insertNewNode(Root, 6);
    cout << "\nThe height/maximum depth of the BST is : " << findHeight(Root);
    return 0;
}
