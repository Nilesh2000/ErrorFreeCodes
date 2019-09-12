//A program to check if two trees are identical.
//Two trees are identical when they have same data and arrangement of data is also same.
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


//To identify if two trees are identical, we need to traverse both trees simultaneously, and while traversing we need to compare data and children of the trees.
bool areTreesIdentical(Node *a, Node *b)
{
    if(a == NULL && b == NULL) //If both the subtrees are empty,
      return 1;

    if(a != NULL && b != NULL) //If both the subtrees are not empty,
      return (a -> Data == b -> Data &&
             areTreesIdentical(a -> Left, b -> Left) &&
             areTreesIdentical(a -> Right, b -> Right));

      return 0; //If one subtree is empty and the other is not.....
}

int main(void)
{
    Node *Root1 = newNode(1);
    Root1 -> Left = newNode(2);
    Root1 -> Right = newNode(3);

    Node *Root2 = newNode(1);
    Root2 -> Left = newNode(2);
    Root2 -> Right = newNode(3);

    cout << areTreesIdentical(Root1, Root2);

    return 0;
}
