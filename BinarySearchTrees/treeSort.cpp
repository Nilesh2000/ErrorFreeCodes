//Given an unsorted array, sort it in increasing order using BST's
//The logic here is really simple, just insert all the elements into the BST and then do the inorder traversal of the BST.
# include <iostream>

using namespace std;

struct BstNode
{
    int Data;
    BstNode *Left, *Right;
};

BstNode* newNode(int Data)
{
    BstNode *newNode = new BstNode(); //Memory allocation for new node.
    newNode -> Data = Data;
    newNode -> Left = newNode -> Right = NULL;
    return newNode;
}

BstNode* insertIntoTree(BstNode* Root, int Data)
{
    if(Root == NULL) //If the tree or subtree has no elements
      return newNode(Data);

    if(Root -> Data >= Data) //If data stored in the root node is greater than the data to be inserted, make sure to insert the new node in the left subtree.
    {
        Root -> Left = insertIntoTree(Root -> Left, Data);
    }
    else //Else, just insert it into the right subtree.
    {
        Root -> Right = insertIntoTree(Root -> Right, Data);
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

int main(void)
{
    BstNode *Root = NULL;
    int Arr[] = {23, 24, 54, 67, 12, 11, 78};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    for(int i = 0 ; i < n ; i++)
      Root = insertIntoTree(Root, Arr[i]);
    cout << "\nSorted Array : ";
    inOrderTraversal(Root);
    return 0;
}
