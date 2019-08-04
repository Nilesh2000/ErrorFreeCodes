//A program to create a BST of integers and search an element in it.
# include <iostream>

using namespace std;

struct BstNode
{
    int Data;
    BstNode *Left, *Right;
};

BstNode* insertNewNode(BstNode* Root, int Data)
{
    BstNode *newNode = new BstNode();
    newNode -> Data = Data;

    if(Root == NULL)
    {
        Root = newNode;
        newNode -> Left = newNode -> Right = NULL;
        return Root;
    }

    if(Root -> Data >= Data)
    {
        Root -> Left = insertNewNode(Root -> Left, Data);
    }
    else
    {
        Root -> Right = insertNewNode(Root -> Right, Data);
    }
    return Root;
}

bool searchForElement(BstNode* Root, int Data)
{
    if(Root == NULL)
      return false;

    else if(Root -> Data == Data)
      return true;

    else if(Root -> Data >= Data)
      return searchForElement(Root -> Left, Data);

    else
      return searchForElement(Root -> Right, Data);
}

int main(void)
{
    BstNode *Root = NULL;
    Root = insertNewNode(Root, 15);
    Root = insertNewNode(Root, 10);
    Root = insertNewNode(Root, 20);
    Root = insertNewNode(Root, 25);
    Root = insertNewNode(Root, 8);
    Root = insertNewNode(Root, 12);
    Root = insertNewNode(Root, 15);
    if(searchForElement(Root, 8) == true)
      cout << "Found";
    else
      cout << "Not found.";
    return 0;
}
