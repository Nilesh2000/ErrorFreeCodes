// Program to find the maximum path sum of a binary tree

/*
Brilliant Explaination
https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603423/Python-Recursion-stack-thinking-process-diagram
Kinda similar to diameter of tree problem

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Left, *Right;
};

//Function to allocate memory for a new node.
Node *newNode(int Data)
{
    Node *newNode = new Node(); //Memory allocation for new node.
    newNode->Data = Data;
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

int maximumPathSumUtil(Node *Root, int &maxSum)
{
    if (Root == NULL)
        return 0;

    int leftSubtreeSum = max(0, maximumPathSumUtil(Root->Left, maxSum));
    int rightSubtreeSum = max(0, maximumPathSumUtil(Root->Right, maxSum));
    maxSum = max(maxSum, Root->Data + leftSubtreeSum + rightSubtreeSum);
    return Root->Data + max(leftSubtreeSum, rightSubtreeSum);
}

int maximumPathSum(Node *Root)
{
    int maxSum = INT_MIN;
    maximumPathSumUtil(Root, maxSum);
    return maxSum;
}

int main(void)
{
    Node *Root = newNode(-10);
    Root->Left = newNode(9);
    Root->Right = newNode(20);
    Root->Right->Left = newNode(15);
    Root->Right->Right = newNode(7);
    cout << maximumPathSum(Root);
    return 0;
}
