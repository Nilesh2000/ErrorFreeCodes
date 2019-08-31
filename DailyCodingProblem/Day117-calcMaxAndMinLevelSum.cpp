//Given a binary tree, return the level of the tree with minimum sum and the level of the tree with maximum sum. Also, return the maximum and minimum sums.
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

void calcMaxAndMinLevelSum(Node *Root)
{
    queue <Node*> Q;
    int minRes = Root -> Data;
    int maxRes = Root -> Data;
    int Level = 0, minLevel, maxLevel;
    Q.push(Root);
    int maxSum, minSum;
    while(!Q.empty())
    {
        int Cnt = Q.size();
        maxSum = 0, minSum = 0;
        while(Cnt--)
        {
            Node *Temp = Q.front();
            Q.pop();

            maxSum += Temp -> Data;
            minSum += Temp -> Data;

            if(Temp -> Left != NULL)
              Q.push(Temp -> Left);
            if(Temp -> Right != NULL)
              Q.push(Temp -> Right);
        }
        Level++;
        if(maxSum >= maxRes)
        {
            maxRes = maxSum;
            maxLevel = Level;
        }
        if(minSum <= minRes)
        {
            minRes = minSum;
            minLevel = Level;
        }
    }
    cout << "\nThe level with the maximum sum and maximum sum is : " << maxLevel << " " << maxRes;
    cout << "\nThe level with the minimum sum and minimum sum is : " << minLevel << " " << minRes;
}

int main(void)
{
    Node *Root = newNode(4);
    Root -> Left = newNode(2);
    Root -> Right = newNode(3);
    Root -> Left -> Left = newNode(4);
    Root -> Left -> Right = newNode(5);
    Root -> Right -> Left = newNode(-5);
    calcMaxAndMinLevelSum(Root);
    return 0;
}
