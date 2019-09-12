//A program to construct a BST, given the level order traversal of the BST.
# include <iostream>
# include <queue>

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

Node *levelOrder(Node *Root, int Data)
{
    if(Root == NULL)
    {
        Root = newNode(Data);
        return Root;
    }

    if(Data <= Root -> Data)
      Root -> Left = levelOrder(Root -> Left, Data);
    if(Data >= Root -> Data)
      Root -> Right = levelOrder(Root -> Right, Data);
    return Root;
}

Node *constructBst(int Arr[], int n)
{
    Node *Root = NULL;

    for(int i = 0 ; i < n ; i++)
      Root = levelOrder(Root, Arr[i]);

    return Root;
}

void levelOrderTraversal(Node *Root)
{
    queue <Node*> Q;
    Q.push(Root);
    while(Q.empty() == false)
    {
        Node *n = Q.front();
        cout << n -> Data << " ";
        Q.pop();

        if(n -> Left != NULL)
          Q.push(n -> Left);

        if(n -> Right != NULL)
          Q.push(n -> Right);
    }
}

int main(void)
{
    int Arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    Node *Root = constructBst(Arr, n);
    cout << "\nLevel order traversal after constructing the tree : ";
    levelOrderTraversal(Root);
    return 0;
}
//End of program
