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

int burnTree(Node *Root, int Target, queue <Node*> &Q)
{
  //First check if the target node exists in the binary tree.
    if(Root == NULL)
      return 0;

    if(Root -> Data == Target)
    {
        cout << Root -> Data << endl; //Printing the target node
        if(Root -> Left != NULL)
        {
            Q.push(Root -> Left);
        }
        if(Root -> Right != NULL)
        {
            Q.push(Root -> Right);
        }
        return 1;
    }

    int a = burnTree(Root -> Left, Target, Q);

    if(a == 1)
    {
        int qSize = Q.size();
        while(qSize--)
        {
            Node *Temp = Q.front();
            cout << Temp -> Data << ", ";
            Q.pop();

            if(Temp -> Left != NULL)
              Q.push(Temp -> Left);
            if(Temp -> Right != NULL)
              Q.push(Temp -> Right);
        }
        if(Root -> Right != NULL)
          Q.push(Root -> Right);
        cout << Root -> Data << endl;
        return 1;
    }

    int b = burnTree(Root -> Right, Target, Q);

    if(b == 1)
    {
        int qSize = Q.size();
        while(qSize--)
        {
            Node *Temp = Q.front();
            cout << Temp -> Data << ", ";
            Q.pop();

            if(Temp -> Left != NULL)
              Q.push(Temp -> Left);
            if(Temp -> Right != NULL)
              Q.push(Temp -> Right);
        }
        if(Root -> Left != NULL)
          Q.push(Root -> Left);
        cout << Root -> Data << endl;
        return 1;
    }
}

int main(void)
{
    Node *Root = newNode(10);
    Root -> Left = newNode(12);
    Root -> Right = newNode(13);
    Root -> Right -> Left = newNode(14);
    Root -> Right -> Right = newNode(15);
    Root -> Right -> Left -> Left = newNode(21);
    Root -> Right -> Left -> Right = newNode(22);
    Root -> Right -> Right -> Left = newNode(23);
    Root -> Right -> Right -> Right = newNode(24);

    int targetNode = 14;
    queue <Node*> q;
    burnTree(Root, targetNode, q);

    while(!q.empty())
    {
        Node *Temp = q.front();
        cout << Temp -> Data;
        if(q.size() != 1)
          cout << " , ";
        q.pop();
    }
    return 0;
}
