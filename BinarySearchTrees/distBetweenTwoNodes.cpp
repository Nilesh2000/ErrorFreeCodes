//A program to calculate the distance between two nodes in a BST.
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

//Function to measure distance of a node from root node.
int distanceFromRoot(BstNode *Root, int x)
{
    if(Root -> Data == x)
      return 0;
    else if(Root -> Data > x)
      return 1 + distanceFromRoot(Root -> Left, x);
    else
      return 1 + distanceFromRoot(Root -> Right, x);
}

int distanceBetweenNodes(BstNode *Root, int a, int b)
{
    if(Root -> Data > a && Root -> Data > b) //If both a and b are lesser than data in root, then both lie in left subtree.
    {
        return distanceBetweenNodes(Root -> Left, a , b);
    }
    else if(Root -> Data < a && Root -> Data < b) //If both a and b are greater than data in root, then both lie in right subtree.
    {
        return distanceBetweenNodes(Root -> Right, a, b);
    }
    else //Else, root is the lowest common ancestor of both the nodes
    {
        return distanceFromRoot(Root, a) + distanceFromRoot(Root, b);
    }
}

int main(void)
{
    BstNode *Root = NULL;
    Root = insertNewNode(Root, 5);
    Root = insertNewNode(Root, 2);
    Root = insertNewNode(Root, 12);
    Root = insertNewNode(Root, 1);
    Root = insertNewNode(Root, 3);
    Root = insertNewNode(Root, 9);
    Root = insertNewNode(Root, 21);
    Root = insertNewNode(Root, 19);
    Root = insertNewNode(Root, 25);
    cout << "\nThe distance between the two nodes is : " << distanceBetweenNodes(Root, 2, 25);
    return 0;
}
//End of program
