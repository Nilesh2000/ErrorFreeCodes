/*
Given a sorted array, convert it to a height balanced binary search tree.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Approach:-
Find the middle of the array in O(1) time. Make it the root of the BST
Recursively make the middle of the left and right halves the root of the left and right subtrees.

Time Complexity : O(n)
Since we do not have to traverse the tree during each insertion. We have to just perform insertion and connect the nodes
*/

#include <iostream>
#include <vector>

using namespace std;

struct BstNode
{
    int Data;
    BstNode *Left, *Right;
};

// Helper Method to allocate memory for a new node
BstNode *newNode(int x)
{
    BstNode *Temp = new BstNode();
    Temp->Data = x;
    Temp->Left = Temp->Right = NULL;
    return Temp;
}

BstNode *sortedArrayToBST(BstNode *Root, vector<int> V, int Low, int High)
{
    // Base Case
    if (Low > High)
        return NULL;

    // Find the Middle Index
    int Mid = (Low + High) / 2;
    Root = newNode(V[Mid]);

    // Left Subtree stores the middle element of the left half
    Root->Left = sortedArrayToBST(Root, V, Low, Mid - 1);

    // Right Subtree stores the middle element of the right half
    Root->Right = sortedArrayToBST(Root, V, Mid + 1, High);

    // Return Root Node
    return Root;
}

void inorderTraversal(BstNode *Root)
{
    if (Root == NULL)
        return;
    inorderTraversal(Root->Left);
    cout << Root->Data << " ";
    inorderTraversal(Root->Right);
}

int main(void)
{
    vector<int> V = {1, 2, 3, 4, 5, 6, 7};
    int Low = 0, High = V.size() - 1;
    BstNode *Root = NULL;

    // Insert sorted array elements into BST
    Root = sortedArrayToBST(Root, V, Low, High);

    // Inorder traversal of BST returns a sorted list of numbers
    inorderTraversal(Root);

    return 0;
}
