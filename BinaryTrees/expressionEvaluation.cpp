/*
Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).
*/
# include <iostream>

using namespace std;

struct Node
{
    string Data;
    Node *Left, *Right;
};

//Function to allocate memory for a new node.
Node* newNode(string Data)
{
    Node *newNode = new Node(); //Memory allocation for new node.
    newNode -> Data = Data;
    newNode -> Left = newNode -> Right = NULL;
    return newNode;
}

int convertToInt(string s)
{
    int Num = 0;

    if(s[0] != '-')
    {
        for(int i = 0 ; i < s.length() ; i++)
        {
            Num = Num * 10 + int(s[i] - 48);
        }
    }

    else
    {
        for(int i = 1 ; i < s.length() ; i++)
        {
            Num = Num * 10 + int(s[i] - 48);
            Num *= -1;
        }
    }
    return Num;
}

int evalTree(Node *Root)
{
    if(!Root)
      return 0;

    if(!Root -> Left && !Root -> Right)
      return convertToInt(Root -> Data);

    int lValue = evalTree(Root -> Left);
    int rValue = evalTree(Root -> Right);

    if(Root -> Data == "+")
      return lValue + rValue;
    else if(Root -> Data == "-")
      return lValue - rValue;
    else if(Root -> Data == "*")
      return lValue * rValue;
    return lValue / rValue;
}

int main(void)
{
    Node *Root = newNode("*");
    Root -> Left = newNode("+");
    Root -> Right = newNode("+");
    Root -> Left -> Left = newNode("3");
    Root -> Left -> Right = newNode("2");
    Root -> Right -> Left = newNode("4");
    Root -> Right -> Right = newNode("5");
    //Root -> Right -> Right = newNode("-5");
    cout << evalTree(Root);
    return 0;
}
