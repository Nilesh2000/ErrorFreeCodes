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

//Function which does the job
void calcMaxAndMinLevelSum(Node *Root)
{
    queue <Node*> Q; //Create a queue to store the elements at different levels of the queue
    //Initially, intilaize the data at the root node as the minimum and maximum data
    int minRes = Root -> Data; //Variable to store the maximum sum among all levels on a tree.
    int maxRes = Root -> Data; //Variable to store the minimum sum among all levels on a tree.
    //Set Level = 0 initially because we will traverse the tree from the root to the leaf nodes.
    int Level = 0, minLevel, maxLevel;
    Q.push(Root);
    int maxSum, minSum; //Variable tp compute the sum at a particular level and then compare with minRes and maxRes.

    while(!Q.empty())
    {
        int Cnt = Q.size(); //Cnt number of elements on a particular level.
        maxSum = 0, minSum = 0;

        while(Cnt--)
        {
            Node *Temp = Q.front();
            Q.pop();

            maxSum += Temp -> Data;
            minSum += Temp -> Data;

            //Push the elements on the subsequent levels into the queue.
            if(Temp -> Left != NULL)
              Q.push(Temp -> Left);
            if(Temp -> Right != NULL)
              Q.push(Temp -> Right);
        }
        Level++;  //Increment Level as you go down the tree.

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
