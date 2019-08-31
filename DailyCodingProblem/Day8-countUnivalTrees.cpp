/*
A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
Given the root to a binary tree, count the number of unival subtrees.
*/
# include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Left, *Right;
};

Node* newNode(int Data)
{
    Node *newNode = new Node(); //Memory allocation for new node.
    newNode -> Data = Data;
    newNode -> Left = newNode -> Right = NULL;
    return newNode;
}

//This function increments count by number of single valued subtrees under root. It returns true if subtree under root is Singly, else false.
bool countUnivalTrees(Node *Root, int &Cnt)
{
    if(Root == NULL)
      return true;

    //Recursively count in left and right subtrees
    bool leftNode = countUnivalTrees(Root -> Left, Cnt);
    bool rightNode = countUnivalTrees(Root -> Right, Cnt);

    //If any of the subtrees is not singly, then this cannot be singly.
    if(leftNode == false || rightNode == false)
      return false;

    //If left subtree is singly and non-empty, but data doesn't match
    if(Root -> Left && Root -> Data != Root -> Left -> Data)
      return false;

    //Same for right subtree
    if(Root -> Right && Root -> Data != Root -> Right -> Data)
      return false;

    //If none of the above conditions is true, then tree rooted under root is single valued, increment count and return true.
    Cnt++;
    return true;
}

//This function mainly calls countSingleRec()  after initializing count as 0
int count(Node *Root)
{
    int Count = 0;
    countUnivalTrees(Root, Count);
    return Count;
}

int main(void)
{
    Node* Root = newNode(5);
    Root-> Left = newNode(4);
    Root -> Right = newNode(5);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(4);
    Root -> Right -> Right = newNode(5);
    cout << "\nThe number of unival sub-trees is : " << count(Root);
    return 0;
}
//End of program
