//A program to find the maximum and minimum element in a binary search tree.

/*
In a binary search tree, just traverse the tree from root to right until right is NULL. The node whose right is NULL is the node with the maximum value in
the tree. The same logic is applied to find the minimum element of the tree where you to traverse till the leftmost element of the tree.
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

int findMin(BstNode *Root)
{
    BstNode *Cur = Root;
    while(Cur -> Left != NULL)
    {
        Cur = Cur -> Left;
    }
    return Cur -> Data;
}

int findMax(BstNode *Root)
{
    BstNode *Cur = Root;
    while(Cur -> Right != NULL)
    {
        Cur = Cur -> Right;
    }
    return Cur -> Data;
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
    cout << "\nThe maximum element is : " << findMax(Root);
    cout << "\nThe minimum element is : " << findMin(Root);
    return 0;
}
