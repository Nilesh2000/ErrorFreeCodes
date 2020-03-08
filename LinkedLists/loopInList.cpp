//An implementation of the Floyd's-Cycle finding algorithm to detect if a loop exists. if exists, find the length of the loop and the starting point of the loop. Also, remove the loop from the list.

/*
Explaination :-
Let the length of the cycle be n.
Let m be the number of nodes to the cycle initially.
Let the hare and tortoise pointer meet a k steps from the start of the cycle.
Let the tortoie go through the cycle p times and the hare go through the cycle q times.
Then,
i = m + (p*n) + k
2i = m + (q*n) + k
We are using 2i for the hare since it moves two nodes at a time whereas the tortoie moves only one node at a time.
Thus,
2{m + (p*n) + k} = m + (q*n) + k
m + k = (q - 2p)n

Finding the first node of the cycle:-
Once the hare and tortoise meet, put the tortoise pointer back to head and leave hare wherever they met which k steps from the start of the cycle.
Then, of we let them move k steps the tortoise would be back at the place where they met initially.
Since m + k steps is a multiple of cycle length n, hare, in the mean time, would go through the cycle (q-2p) times and would come back to the same point
(k steps away from the cycle beginning).
Now, instead of letting them move m + k steps, if we let them move only m steps, tortoise would arrive at the cycle beginning. Hare would go be k steps short
of completing (q-2p) rotations. Since it started k steps in front of the cycle beginning, hare would have to arrive at the cycle beginning.
As a result, this explains that they would have to meet at the cycle beginning after some number of steps for the very first time (very first time because
tortoise just arrived at the cycle after m steps and it could never see hare which was already in the cycle).
Now we know that the number of steps we need to move them until they meet turns out to be the distance from the beginning of the list to the cycle beginning,
 m. Of course, the algorithm does not need to know what m is. It will just move both tortoise and hare one step at a time until they meet. The meeting point
has to be the cycle start and the number of steps must be the distance (m) to the cycle beginning.
*/
#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

Node *Head = NULL; //List is initially empty.

int lengthOfLoop(Node *);
int firstNodeOfLoop(Node *, Node *);

void insertAtEnd(int x)
{
    Node *Temp = new Node(); //Allocate memory to create a new node.
    Temp->Data = x;          //Initialize the Data of the node to the parameter passed.
    if (Head == NULL)        //Check if the list is initially empty.
    {
        Head = Temp; //Set the address of the newly allocated node to Head.
        return;
    }
    //If the list is not empty,

    Node *lastNode = Head; //Set a temporary variable of type Node to Head.

    while (lastNode->Next != NULL) //Traverse the linked list till the end of the list.
    {
        lastNode = lastNode->Next; //Keep moving to the next node.
    }
    lastNode->Next = Temp; //Set the address of the last node to the newly allocated node in memory.
}

void printList()
{
    Node *Temp = Head;
    while (Temp != NULL)
    {
        cout << Temp->Data << " ";
        Temp = Temp->Next;
    }
}

//The idea here is to hava two pointers Ptr1 and Ptr2 pointing to Head and loopNode(Node where Slow_Ptr and Fast_Ptr met) respectively.
void removeLoop(Node *loopNode)
{
    Node *Ptr1, *Ptr2;
    Ptr1 = Head;
    while (1)
    {
        Ptr2 = loopNode;
        //Start traversing the list from loopNode and check if it ever reaches Ptr2.
        while (Ptr2->Next != loopNode && Ptr2->Next != Ptr1)
        {
            Ptr2 = Ptr2->Next;
        }
        //If Ptr2 ever reaches Ptr1, break out of the loop. Thus, Ptr2 will be the last node of the list.
        if (Ptr2->Next == Ptr1)
        {
            break;
        }
        //If Ptr2 didn'd reach Ptr1 after one loop, move Ptr1 forward by one node.
        Ptr1 = Ptr1->Next;
    }
    //After the end of loop ptr2 is the last node of the loop. So make next of ptr2 as NULL
    Ptr2->Next = NULL;
}

/*
Traverse linked list using two pointers.  Move one pointer by one noce and other pointer by two nodes.  If these pointers meet at same node,  then there is a
loop.  If pointers do not meet then linked list doesn’t have a loop.
*/

void detectLoop(Node *A)
{
    Node *Fast_Ptr = A;
    Node *Slow_Ptr = A;
    while (Slow_Ptr && Fast_Ptr && Fast_Ptr->Next)
    {
        Slow_Ptr = Slow_Ptr->Next;
        Fast_Ptr = Fast_Ptr->Next->Next;
        if (Slow_Ptr == Fast_Ptr)
        {
            cout << "\nLoop Exists In The Linked List.";
            cout << "\nThe Length Of the loop is : " << lengthOfLoop(Slow_Ptr);
            cout << "\nThe first node of the cycle is : " << firstNodeOfLoop(Slow_Ptr, Fast_Ptr) << endl;
            removeLoop(Slow_Ptr);
            cout << "Linked List after removing loop : ";
            printList();
            cout << endl;
            return;
        }
    }
    cout << "\nLoop Does Not Exist In The Linked List." << endl;
}

/*
We store the address of this common point in a pointer variable say ptr. Then we initialize a counter with 1 and start from the common point and
keeps on visiting next node and increasing the counter till we again reach the common point(ptr). At that point, the value of the counter will
be equal to the length of the loop.
*/
int lengthOfLoop(Node *n) //n refers to one of the nodes present in the loop of the linked list.
{
    int Len = 1;
    Node *Temp = n;
    while (Temp->Next != n)
    {
        Len++;
        Temp = Temp->Next;
    }
    return Len;
}

int firstNodeOfLoop(Node *slowPtr, Node *fastPtr)
{
    slowPtr = Head;
    while (slowPtr != fastPtr)
    {
        slowPtr = slowPtr->Next;
        fastPtr = fastPtr->Next;
    }
    return slowPtr->Data;
}

int main(void)
{
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    insertAtEnd(9);
    insertAtEnd(11);
    Head->Next->Next->Next->Next->Next = Head->Next; //Test case to check if the loop exists in the linked list.
    //Linked list is 3 -> 5 -> 7 -> 9 -> 11. (5, 7, 9 are the loop of the linked list)
    //                    |    <-   |
    detectLoop(Head);
    return 0;
}
