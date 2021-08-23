/*
Given a Binary Tree, find the lowest common ancestor of the two nodes.

One approach is to find both the nodes and then store their traversal paths in two arrays.
Then, we traverse both the arrays and find the last element at which both the arrays are equal.
This approach requires extra space.

Time Complexity : O(n)
Space Complexity : O(n)

Another approach we can do is to perform a preorder traversal at each step and check if the root node of the tree or subtree is equal to the address of n1 or n2.
If that's true, we return the address to the parent node, else we return NULL to the parent
If we get a NOT NULL address from both sides of the root, that node is the parent node.
If we get a NULL address from both sides of the root, the 2 nodes have no LCA.
If we get a NOT NULL only from one side of the tree/subtree, then that node is the LCA.

Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Left, *Right;
};

//Function to allocate memory for a new node.
Node *newNode(int Data)
{
    Node *newNode = new Node(); //Memory allocation for new node.
    newNode->Data = Data;
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

Node *lowestCommonAncestor(Node *Root, Node *n1, Node *n2)
{
    // If root is empty, it is incapable of being an LCA
    if (Root == NULL)
        return NULL;

    // If the root node of the tree or subtree equals n1 or n2, root node is the LCA
    if (Root == n1 || Root == n2)
        return Root;

    Node *leftNode = lowestCommonAncestor(Root->Left, n1, n2);
    Node *rightNode = lowestCommonAncestor(Root->Right, n1, n2);

    if (leftNode != NULL && rightNode != NULL)
        return Root;
    if (leftNode == NULL && rightNode == NULL)
        return NULL;

    return leftNode != NULL ? leftNode : rightNode;
}

int main(void)
{
    Node *Root = newNode(1);
    Root->Left = newNode(2);
    Root->Right = newNode(3);
    Root->Left->Left = newNode(4);
    Root->Left->Right = newNode(5);
    Root->Right->Left = newNode(6);
    Root->Right->Right = newNode(7);

    Node *n1 = Root->Left->Left;
    Node *n2 = Root->Left->Right;
    cout << "Lowest Common Ancestor of 4 and 5 is : " << lowestCommonAncestor(Root, n1, n2)->Data;

    n1 = Root->Left;
    n2 = Root->Right;
    cout << "\nLowest Common Ancestor of 2 and 3 is : " << lowestCommonAncestor(Root, n1, n2)->Data;

    n1 = Root;
    n2 = Root->Right->Right;
    cout << "\nLowest Common Ancestor of 1 and 4 is : " << lowestCommonAncestor(Root, n1, n2)->Data;

    return 0;
}
