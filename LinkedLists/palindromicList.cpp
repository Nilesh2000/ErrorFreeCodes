/*
Given the head of a singly linked list, return true if it is a palindrome.

APPROACH 1:
1. Reverse the linked list iteratively/recursively
2. Iterate over the original and reverse linked list one by one, return false if data does not match
3. If you have reached end of linked list, return false.

Time Complexity : O(2*N)
Space Complexity : O(N)

APPROACH 2:
1. Iterate over the list and store all elements into a stack.
2. Iterate over the list again and compare the list element with element at the top of the stack.
3. If elements match, pop the stack.
4. If elements do not match, return false.
5. If you have reached end of linked list, return false.

Time Complexity : O(2*N)
Space Complexity : O(N)

APPROACH 3:
1. Two pointers fast and slow are pointing to head.
2. Move slow one pointer at a time and fast by 2 pointers at a time. Insert slow->data into stack.
3. Move fast until fast or fast->next becomes NULL.
4. If fast is NULL and fast->next is not NULL, there are an odd number of nodes. Thus, move slow one step forward.
5. Compare data present in S.top() present with slow->data.
6. If elements match, pop the stack and move slow pointer forward.
7. If they don't, return false.
8. If you have reached end of linked list, return false.

Time Complexity : O(N)
Space Complexity : O(N/2)

APPROACH 4:
1. Two pointers fast and slow are pointing to head.
2. Move slow one pointer at a time and fast by 2 pointers at a time.
3. Move fast until fast or fast->next becomes NULL.
4. If fast is NULL and fast->next is not NULL, there are an odd number of nodes
5. slow is now at the middle of the list
6. Reverse List from slow to end of list
7. Move fast to head.
8. Move fast and slow one pointer at a time, return false if data does not match.
9. If slow reaches end of the reversed list, return true.

Time Complexity : O(2*N)
Space Complexity : O(N)
*/

#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int Data;
    Node *Next;

    Node(int x)
    {
        Data = x;
        Next = NULL;
    }
};

Node *insertAtEnd(Node *Head, int x)
{
    Node *Temp = new Node(x);

    if (Head == NULL)
    {
        Head = Temp;
        return Head;
    }

    Node *lastNode = Head;
    while (lastNode->Next != NULL)
    {
        lastNode = lastNode->Next;
    }

    lastNode->Next = Temp;
    return Head;
}

bool isListPalindrome(Node *Head)
{
    if (Head == NULL)
        return false;
    if (Head->Next == NULL)
        return true;

    Node *Temp = Head;
    stack<int> s;
    bool isPalindrome = true;

    while (Temp != NULL)
    {
        s.push(Temp->Data);
        Temp = Temp->Next;
    }

    Temp = Head;
    while (Temp != NULL)
    {
        int Top = s.top();
        s.pop();
        if (Temp->Data == Top)
            isPalindrome = true;
        else
        {
            isPalindrome = false;
            break;
        }
        Temp = Temp->Next;
    }
    return isPalindrome;
}

Node *reverseList(Node *Head)
{
    if (Head == NULL || Head->Next == NULL)
        return Head;

    Node *prev = NULL, *curr = Head, *next;
    while (curr != NULL)
    {
        next = curr->Next;
        curr->Next = prev;
        prev = curr;
        curr = next;
    }
    Head = prev;
    return Head;
}

bool isListPalindromeSpaceEfficient(Node *Head)
{
    if (Head == NULL)
        return false;
    if (Head->Next == NULL)
        return true;

    Node *slowPtr = Head, *fastPtr = Head;
    while (fastPtr && fastPtr->Next)
    {
        slowPtr = slowPtr->Next;
        fastPtr = fastPtr->Next->Next;
    }

    if (fastPtr != NULL)
        slowPtr = slowPtr->Next;

    slowPtr = reverseList(slowPtr);
    fastPtr = Head;
    while (slowPtr != NULL)
    {
        if (slowPtr->Data != fastPtr->Data)
            return false;
        slowPtr = slowPtr->Next;
        fastPtr = fastPtr->Next;
    }
    return true;
}

int main(void) //Driver function
{
    Node *Head = NULL;
    Head = insertAtEnd(Head, 1);
    Head = insertAtEnd(Head, 2);
    Head = insertAtEnd(Head, 3);
    Head = insertAtEnd(Head, 2);
    Head = insertAtEnd(Head, 1);

    cout << isListPalindrome(Head) << endl;
    cout << isListPalindromeSpaceEfficient(Head);
    return 0;
}
