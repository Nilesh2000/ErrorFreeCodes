//A program to implement all types of traversals on a tree namely the inorder, preorder and postorder traversal techniques.
# include <iostream>
# include <queue>
# include <stack>

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

//In inorder traversal, the data present in the root node is displayed is display after the data in the left node and before the data in the right node.
void inOrderTraversal(Node *Root)
{
    if(Root == NULL)
      return ;

    inOrderTraversal(Root -> Left);
    cout << Root -> Data << " ";
    inOrderTraversal(Root -> Right);
}

//In preorder traversal, the data in the root node is displayed before the data in the left and right node.
void preOrderTraversal(Node *Root)
{
    if(Root == NULL)
      return ;

    cout << Root -> Data << " ";
    preOrderTraversal(Root -> Left);
    preOrderTraversal(Root -> Right);
}

//In postorder traversal, the data in the root node is displayed after the data in the left and right node.
void postOrderTraversal(Node *Root)
{
    if(Root == NULL)
      return ;

    postOrderTraversal(Root -> Left);
    postOrderTraversal(Root -> Right);
    cout << Root -> Data << " ";
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

void reverseLevelOrderTraversal(Node *Root)
{
    queue <Node*> Q;
    stack <Node*> S;
    Q.push(Root);
    while(Q.empty() == false)
    {
        Node *n = Q.front();
        Q.pop();
        S.push(n);

        if(n -> Left != NULL)
          Q.push(n -> Left);

        if(n -> Right != NULL)
          Q.push(n -> Right);
    }

    while(S.empty() == false)
    {
        Node *n = S.top();
        S.pop();
        cout << n -> Data << " ";
    }
}

int main(void)
{
    Node *Root = newNode(1);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);
    Root -> Right -> Left = newNode(6);
    Root -> Right -> Right = newNode(7);
    cout << "\nInorder traversal : ";
    inOrderTraversal(Root);
    cout << "\nPreorder traversal : ";
    preOrderTraversal(Root);
    cout << "\nPostorder traversal : ";
    postOrderTraversal(Root);
    cout << "\nLevel Order Traversal : ";
    levelOrderTraversal(Root);
    cout << "\nReverse level order traversal : ";
    reverseLevelOrderTraversal(Root);
    return 0;
}
