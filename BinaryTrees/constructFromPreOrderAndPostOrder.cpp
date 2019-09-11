/*
It is not possible to create a tree, given the preorder and postorder traversals of a binary tree.
But, if it is given that the tree to be constructed is a full binary tree, then the preorder and postorder traversals are sufficient/
A full binary tree is a tree where every internal node has 2 childeren only.
*/
# include <iostream>
# include <vector>

using namespace std;

struct Node
{
    int Data;
    Node *Left, *Right;

    Node(int x)
    {
        Data = x;
        Left = Right = NULL;
    }
};

void preOrderTraversal(Node *Root)
{
    if(Root == NULL)
      return ;

    cout << Root -> Data << " ";
    preOrderTraversal(Root -> Left);
    preOrderTraversal(Root -> Right);
}

void postOrderTraversal(Node *Root)
{
    if(Root == NULL)
      return ;

    postOrderTraversal(Root -> Left);
    postOrderTraversal(Root -> Right);
    cout << Root -> Data << " ";
}

/*
The logic here is that:-
Create a node TreeNode(pre[preIndex]) as the root.

Becasue root node will be lastly iterated in post order,
if root.val == post[posIndex],
it means we have constructed the whole tree,

If we haven't completed constructed the whole tree,
So we recursively constructFromPrePost for left sub tree and right sub tree.

And finally, we'll reach the posIndex that root.val == post[posIndex].
We increment posIndex and return our root node.
*/
int preIndex = 0, postIndex = 0;
Node *constructTree(vector <int> preOrder, vector <int> postOrder)
{
    Node *Root = new Node(preOrder[preIndex++]);
    if(Root -> Data != postOrder[postIndex])
      Root -> Left = constructTree(preOrder, postOrder);
    if(Root -> Data != postOrder[postIndex])
      Root -> Right = constructTree(preOrder, postOrder);
    postIndex++;
    return Root;
}

int main(void)
{
    vector <int> preOrder = {1, 2, 3};
    vector <int> postOrder = {2, 3, 1};

    Node *Root = constructTree(preOrder, postOrder);
    cout << "\nPreorder and postorder traversals after constructing the tree : \n";
    preOrderTraversal(Root);
    cout << "\n";
    postOrderTraversal(Root);
    return 0;
}
//End of program
