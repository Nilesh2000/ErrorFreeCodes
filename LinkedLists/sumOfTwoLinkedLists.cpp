/*
Given two numbers represented by two lists, write a function that returns the sum list. The sum list is a list representation of the addition of two input numbers.

APPROACH:
1. Create a dummy node which stores an initial value of 0.
2. Create a temporary node pointing to the dummy node
3. Traverse both l1 and l2 together
4. Before each traversal, set sum=0
5. Increment sum by l1->Data and l2->Data at each step
6. Calculate carry using the formula carry = sum/10
7. Create a new node with the value sum % 10.
8. Set Temp->Next = Node
9. Set Temp=Temp->Next
10. Return Dummy->Next

Time Complexity : O(M), where M is the length of the longer list
Space Complexity : O(M)
*/

#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;

    Node(int x)
    {
        Data = x;
    }
};

Node *insertAtBeginning(Node *Head, int x)
{
    Node *newNode = new Node(x);
    newNode->Next = Head;
    Head = newNode;
    return Head;
}

Node *sumOfLists(Node *l1, Node *l2)
{
    Node *dummy = new Node(0);
    Node *Temp = dummy;
    int carry = 0;

    while (l1 || l2 || carry)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->Data;
            l1 = l1->Next;
        }
        if (l2)
        {
            sum += l2->Data;
            l2 = l2->Next;
        }

        sum += carry;
        carry = sum / 10;
        sum = sum % 10;

        Node *node = new Node(sum);
        Temp->Next = node;
        Temp = Temp->Next;
    }
    Temp->Next = NULL;
    return dummy->Next;
}

void printList(Node *Temp)
{
    cout << "\n";
    while (Temp != NULL)
    {
        cout << Temp->Data;
        Temp = Temp->Next;
    }
}

int main(void)
{
    Node *l1 = NULL, *l2 = NULL;

    l1 = insertAtBeginning(l1, 3);
    l1 = insertAtBeginning(l1, 4);
    l1 = insertAtBeginning(l1, 2);

    l2 = insertAtBeginning(l2, 4);
    l2 = insertAtBeginning(l2, 6);
    l2 = insertAtBeginning(l2, 5);

    printList(l1);
    printList(l2);

    Node *sumList = sumOfLists(l1, l2);
    printList(sumList);

    return 0;
}
