/*
Program to check if there exists two elements in the BST element such that their sum is equal to the given target

Approach 1:
Store the inorder traversal of the BST in an array.
The array will be a sorted array.
Use the two pointer approach to check if there exists two elements which sum up to the given target

Time Complexity : O(n) + O(log n) ~ O(n)
Space Complexity : O(n)

Approach 2:
Another approach is to insert the elements of the BST into an unordered_set as and when we traverse the tree.
Before insertion check if the element (target - Root->Data) is present in the set. If it exists, return true, else just insert Root->Data into the unordered_set.

Time Complexity : O(n)
Space Complexity : O(n)

Approach 3:
For every element present in the BST, perform a search operation search(Target - Root->Data).
If elements exists return true, else traverse the remaining BST until you reach NULL.

Time Complexity : O(n*h)
Space Complexity : O(h)
h is the height of the tree

Approach 4:
Use a BinaryTree Iterator
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/106063/C%2B%2B-Clean-Code-O(n)-time-O(lg-n)-space-BinaryTree-Iterator

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

void inorderTraversal(BstNode *Root, vector<int> &V)
{
    if (Root == NULL)
        return;
    inorderTraversal(Root->Left, V);
    V.push_back(Root->Data);
    inorderTraversal(Root->Right, V);
}

bool findTarget(BstNode *Root, int Target)
{
    vector<int> V;

    // Store inorder traversal of the tree in the vector V
    inorderTraversal(Root, V);

    // Use two pointer approach to find if there exists two numbers which sum up to a target
    int Low = 0, High = V.size() - 1;
    while (Low < High)
    {
        if (V[Low] + V[High] == Target)
            return true;
        else if (V[Low] + V[High] < Target)
            Low++;
        else if (V[Low] + V[High] > Target)
            High--;
    }
    return false;
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

    bool isExist = findTarget(Root, 10);
    cout << isExist;
    return 0;
}
