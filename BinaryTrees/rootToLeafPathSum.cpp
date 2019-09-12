//A program to check if the Root to leaf path sum in a binary tree equals to a given number.
# include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Left, *Right;
};

//Function to allocate memory for a new node.
Node* newNode(int Data)
{
    Node *newNode = new Node(); //Memory allocation for new node.
    newNode -> Data = Data;
    newNode -> Left = newNode -> Right = NULL;
    return newNode;
}

/*
Subtract the node value from the sum when recurring down, and check to see if the sum is 0 when you reach the end of the tree.
*/
bool rootToLeafPathSum(Node *Root, int Sum)
{
    if(Root == NULL)
      return (Sum == 0);

    bool Res = false;
    int subSum = Sum - Root -> Data;

    if(subSum == 0 && Root -> Left == NULL && Root -> Right == NULL)
      return true;

    if(Root -> Left)
      Res = Res || rootToLeafPathSum(Root -> Left, subSum);
    if(Root -> Right)
      Res = Res || rootToLeafPathSum(Root -> Right, subSum);
    return Res;
}

int main(void)
{
    Node *Root = NULL;
    Root = newNode(10);
    Root -> Left = newNode(8);
    Root -> Right = newNode(2);
    Root -> Left -> Left = newNode(3);
    Root -> Left -> Right = newNode(5);
    Root -> Right -> Left = newNode(2);
    cout << rootToLeafPathSum(Root, 21);
    cout << '\n' << rootToLeafPathSum(Root, 19);
    return 0;
}
