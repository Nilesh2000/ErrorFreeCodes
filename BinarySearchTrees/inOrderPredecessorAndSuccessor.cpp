//A program to calculate the inorder successor of a node in a BST.
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

void inOrderTraversal(BstNode *Root)
{
    if(Root == NULL)
      return ;

    inOrderTraversal(Root -> Left);
    cout << Root -> Data << " ";
    inOrderTraversal(Root -> Right);
}

//Function to search for a particular node in a BST
BstNode *findNode(BstNode *Root, int Data)
{
    if(Root == NULL)
      return NULL;
    else if(Root -> Data > Data)
      return findNode(Root -> Left, Data);
    else if(Root -> Data < Data)
      return findNode(Root -> Right, Data);
    return Root;
}

//Function to find the node with smallest value in a tree/subtree.
BstNode *findMin(BstNode *Root)
{
    if(Root == NULL)
      return NULL;

    while(Root -> Left != NULL)
    {
        Root = Root -> Left;
    }
    return Root;
}

BstNode *findMax(BstNode *Root)
{
    if(Root == NULL)
      return NULL;

    while(Root -> Right != NULL)
    {
        Root = Root -> Right;
    }
    return Root;
}

//Function to get the inorder successor.
BstNode *getSuccessor(BstNode *Root, int Data)
{
    BstNode *Cur = findNode(Root, Data); //Find the position of the node in the BST whose inorder successor is to be found.

    if(Cur == NULL) //If not found, return from the function.
      return NULL;

    if(Cur -> Right != NULL) //If the right subtree of the current node is not empty, return the node with the least element in the right subtree
    {
        return findMin(Cur -> Right);
    }

    //If the right subtree is empty, then find the node with the greatest height which is greater than Cur -> Data.
    else
    {
        //Declare two pointers for traversal
        BstNode *Successor = NULL;
        BstNode *Ancestor = Root;

        //Continue until Ancestor does not become equal to Cur.
        //Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise go to left side.
        while(Ancestor != Cur)
        {
            if(Cur -> Data < Ancestor -> Data)
            {
                Successor = Ancestor;
                Ancestor = Ancestor -> Left; //We go left now as we know that Cur -> Data is defintely lesser than Ancestor -> Data and will lie in the left
                                             //subtree of Ancestor.
            }
            else
            {
                Ancestor = Ancestor -> Right;
            }
        }
        return Successor;
    }
}

BstNode *getPredecessor(BstNode *Root, int Data)
{
    BstNode *Cur = findNode(Root, Data); //Find if the node exists in the tree

    //If the node does not exist in the tree, return NULL.
    if(Cur == NULL)
      return NULL;

    //If the left subtree is not empty, then return the node with maximum value in the left subtree.
    if(Cur -> Left != NULL)
    {
        return findMax(Root -> Left);
    }

    //If the left subtree is empty, then find the node with the greatest height which is smaller than Cur -> Data.
    else
    {
        BstNode *Ancestor = Root;
        BstNode *Predecessor = NULL;

        while(Ancestor != Cur)
        {
            if(Cur -> Data > Ancestor -> Data)
            {
                Predecessor = Ancestor;
                Ancestor = Ancestor -> Right;
            }
            else
            {
                Ancestor = Ancestor -> Left;
            }
        }
        return Predecessor;
    }
}

//Driver function
int main(void)
{
    BstNode *Root = NULL;
    Root = insertNewNode(Root, 5);
    Root = insertNewNode(Root, 3);
    Root = insertNewNode(Root, 10);
    Root = insertNewNode(Root, 1);
    Root = insertNewNode(Root, 4);
    Root = insertNewNode(Root, 11);
    inOrderTraversal(Root);

    BstNode *Predecessor = getPredecessor(Root, 5);
    if(Predecessor == NULL)
      cout << "\nPredecessor not found.";
    else
      cout << "\nThe inorder Predecessor is : " << Predecessor -> Data;

    BstNode *Successor = getSuccessor(Root, 5);
    if(Successor == NULL)
      cout << "\nSuccessor not found.";
    else
      cout << "\nThe inorder successor is : " << Successor -> Data;

    return 0;
}
//End of program
