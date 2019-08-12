//A program to print all the ancestors of a given node.
//Time Complexity : O(n)
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

bool printAllAncestors(Node *Root, int Num)
{
    if(Root == NULL)
      return false;

    if(Root -> Data == Num)
      return true;

    //If Num is present either in the left or right subtree of the BST, print that node.
    if(printAllAncestors(Root -> Left, Num) || printAllAncestors(Root -> Right, Num))
    {
        cout << Root -> Data << " ";
        return true;
    }

    //Else, just return false.
    return false;
}

//Driver Function
int main(void)
{
    Node *Root = newNode(1);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);
    Root -> Left -> Left -> Right = newNode(7);
    cout << "\nThe ancestors of 7 are : ";
    printAllAncestors(Root, 7);
    return 0;
}
//End of program.
