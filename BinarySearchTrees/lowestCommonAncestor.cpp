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

/*
Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants
(where we allow a node to be a descendant of itself).
The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root. Computation of lowest common ancestors may be useful,
for instance, as part of a procedure for determining the distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed as the distance
 from the root to n1, plus the distance from the root to n2, minus twice the distance from the root to their lowest common ancestor.
 */

int lowestCommonAncestor(BstNode *Root, int n1, int n2)
{
    while(Root != NULL)
    {
        //If both n1 and n2 are smaller than root, then LCA lies in left
        if(Root -> Data > n1 && Root -> Data > n2)
          Root = Root -> Left;

        //If both n1 and n2 are larger than root, then LCA lies in right
        else if(Root -> Data < n1 && Root -> Data < n2)
          Root = Root -> Right;

        else
          break;
    }
    return Root -> Data;
}

//Driver function
int main(void)
{
    BstNode *Root = NULL;
    Root = insertNewNode(Root, 20);
    Root = insertNewNode(Root, 8);
    Root = insertNewNode(Root, 22);
    Root = insertNewNode(Root, 4);
    Root = insertNewNode(Root, 12);
    Root = insertNewNode(Root, 10);
    Root = insertNewNode(Root, 14);
    cout << "\nThe lowest common ancestor of 10 and 14 is : " << lowestCommonAncestor(Root, 10, 14);
    cout << "\nThe lowest common ancestor of 14 and 8 is : " << lowestCommonAncestor(Root, 14, 8);
    cout << "\nThe lowest common ancestor of 10 and 22 is : " << lowestCommonAncestor(Root, 10, 22);
    return 0;
}
