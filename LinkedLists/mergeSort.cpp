//A program to sort the elements of a linked list using the merge sort algorithm.
//Time Complexity : O(n log n)
//Space Complexity : O(1)
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

void insertAtEnd(Node **Head, int x)
{
    Node *Temp = new Node(); //Allocate memory to create a new node.
    Temp -> Data = x; //Initialize the Data of the node to the parameter passed.
      if(Head == NULL) //Check if the list is initially empty.
        {
            Head = Temp; //Set the address of the newly allocated node to Head.
            return ;
        }
    //If the list is not empty,

    Node *lastNode = Head; //Set a temporary variable of type Node to Head.

    while(lastNode -> Next != NULL) //Traverse the linked list till the end of the list.
      {
          lastNode = lastNode -> Next; //Keep moving to the next node.
      }
  lastNode -> Next = Temp; //Set the address of the last node to the newly allocated node in memory.
}

Node* getMiddle(Node *Head)
{
    Node *fastPtr, *slowPtr;
    fastPtr = slowPtr = Head;
    while(fastPtr != NULL && fastPtr -> Next != NULL)
    {
        slowPtr = slowPtr -> Next;
        fastPtr = fastPtr -> Next -> Next;
    }
    return slowPtr;
}

Node* mergeSort(Node *Head)
{
    if(Head == NULL || Head -> Next == NULL)
      return Head;

    Node *midNode = getMiddle();
    Node *leftHead = Head;
    Node *rightHead = midNode -> Next;
    midNode -> Next = NULL;

    return mergeList(mergeSort(leftHead), mergeSort(rightHead));
}

void printList()
{
    Node *Temp = Head;
      while(Temp != NULL)
        {
            cout << Temp -> Data << " ";
            Temp = Temp -> Next;
        }
}

int main(void)
{
    Node *Head = NULL;
    insertAtEnd(&Head, 3);
    insertAtEnd(&Head, 5);
    insertAtEnd(&Head, 7);
    printList();
    mergeSort(Head);
    return 0;
}
