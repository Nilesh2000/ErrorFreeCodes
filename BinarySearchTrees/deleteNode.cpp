//A program to delete a node from a binary search tree.
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

BstNode* findMin(BstNode *Root)
{
    while(Root -> Left != NULL)
      Root = Root -> Left;
    return Root;
}

/*
Deletion Of A Node From BST:-
1. If the node to be deleted is a leaf node, simply delete it.
2. If the node to be deleted has only one child, replace the node to be deleted with the child node.
3. If the node to be deleted has two children, copy the contents of the inorder successor of the node to be deleted and delete the inorder successor.
    (Inorder Predecessor can also be used.)
*/

BstNode *deleteNode(BstNode *Root, int Key)
{
    if(Root == NULL) //Base Case
      return Root;

    //If the node to be deleted contains data lesser than the root node, then it lies in the left tree / subtree.
    if(Key < Root -> Data)
      Root -> Left = deleteNode(Root -> Left, Key);

    //Else if node to be deleted contains data greater than the root node, then it lies in the right tree / subtree.
    else if(Key > Root -> Data)
      Root -> Right = deleteNode(Root -> Right, Key);

    else
    {
        //Case 1 : If the node to be deleted is a leaf node
        if(Root -> Left == NULL && Root -> Right == NULL)
        {
            delete Root;
            Root = NULL;
        }
        //Case 2 : If the node to be deleted has either the left or right child
        else if(Root -> Left == NULL)
        {
            BstNode *Temp = Root;
            Root = Root -> Right;
            delete Temp;
        }
        else if(Root -> Right == NULL)
        {
            BstNode *Temp = Root;
            Root = Root -> Left;
            delete Temp;
        }
        /*
        Case 3 : The node to be deleted has two children
        Find the inorder successor/predecessor of the node to be deleted.
        Copy the data in that node to the the node which was to be deleted.
        Delete the inorder successor/predecessor.
        In this case, we use inorder Successor.
        */
        else
        {
            BstNode *Temp = findMin(Root -> Right);
            Root -> Data = Temp -> Data;
            Root -> Right = deleteNode(Root -> Right, Temp -> Data);
        }
    }
    return Root;
}

int main(void)
{
    BstNode *Root = NULL;
    Root = insertNewNode(Root, 50);
    Root = insertNewNode(Root, 30);
    Root = insertNewNode(Root, 70);
    Root = insertNewNode(Root, 20);
    Root = insertNewNode(Root, 40);
    Root = insertNewNode(Root, 60);
    Root = insertNewNode(Root, 80);
    cout << "\nBefore deletion : ";
    inOrderTraversal(Root);
    Root = deleteNode(Root, 20);
    Root = deleteNode(Root, 30);
    Root = deleteNode(Root, 50);
    cout << "\nAfter deletion : ";
    inOrderTraversal(Root);
    return 0;
}
//End of program
