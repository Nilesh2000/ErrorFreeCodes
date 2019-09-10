//A program to construct a binary tree, given the inorder and preorder traversals of the tree.
# include <iostream>
# include <vector>
# include <map>

using namespace std;

//Structure for binary tree
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

void inOrderTraversal(Node *Root)
{
    if(Root == NULL)
      return ;

    inOrderTraversal(Root -> Left);
    cout << Root -> Data << " ";
    inOrderTraversal(Root -> Right);
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
The logic here is:
Say we have 2 arrays, POST and IN.
Postorder traversing implies that POST[n - 1] is the root node.
Then we can find this POST[n - 1] in IN, say it's IN[5].
Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side, IN[6] to the end is on the right side.
Recursively doing this on subarrays, we can build a tree out of it.
*/
//Function to construct tree from the postOrder and inOrder traversals
Node *constructTree(int postStart, int postEnd, int inStart, int inEnd, vector <int> postOrder, vector <int> inOrder, map <int, int> inMap)
{
  if(postStart > postEnd || inStart > inEnd)
  {
      return NULL;
  }

  Node *Root = new Node(postOrder[postEnd]); //The last node of the postOrder traversal will be the root node.
  int inRoot = inMap[postOrder[postEnd]]; //Find where the root node exists in the inOrder traversal list.
  int numsLeft = inRoot - inStart; //The number of nodes on the left side of the root on the inorder traversal are the number of nodes in the left subtree.

  //The left subtree of the root will be all the nodes which are present before the root node in the inorder traversal.
  Root -> Left = constructTree(postStart, postStart + numsLeft - 1, inStart, inRoot - 1, postOrder, inOrder, inMap);
  //The right subtree of the root will be all the nodes which are present after the root node in the inorder traversal.
  Root -> Right = constructTree(postStart + numsLeft, postEnd - 1, inRoot + 1, inEnd, postOrder, inOrder, inMap);
  return Root;
}

int main(void)
{
    vector <int> inOrder = {4, 2, 5, 1, 3, 6};
    vector <int> postOrder = {4, 5, 2, 6, 3, 1};

    if(inOrder.size() != postOrder.size())
    {
        cout << "\nCannot construct tree since both the tree since the number of elements in the both the lists is different.";
        return 1;
    }

    map <int, int> inMap;

    //Create a map to store the data as the key and the index as the value.
    for(int i = 0 ; i < inOrder.size() ; i++)
      inMap[inOrder[i]] = i;

    Node *Root = constructTree(0, postOrder.size() - 1, 0, inOrder.size() - 1, postOrder, inOrder, inMap);
    cout << "\nInorder and postorder traversals after constructing the tree : \n";
    inOrderTraversal(Root);
    cout << "\n";
    postOrderTraversal(Root);
    return 0;
}
//End of program
