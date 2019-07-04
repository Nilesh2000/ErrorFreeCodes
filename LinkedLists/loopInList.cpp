//An implementation of the Floyd's-Cycle finding algorithm to detect if a loop exists and to find the length of the loop in a linked list.
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

Node *Head = NULL; //List is initially empty.

int lengthOfLoop(Node*);

void insertAtEnd(int x)
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

/*
Traverse linked list using two pointers.  Move one pointer by one and other pointer by two.  If these pointers meet at same node then there is a
loop.  If pointers do not meet then linked list doesn’t have loop.
*/
void detectLoop(Node *A)
{
    Node *Fast_Ptr = A;
    Node *Slow_Ptr = A;
      while(Slow_Ptr && Fast_Ptr && Fast_Ptr -> Next)
        {
            Slow_Ptr = Slow_Ptr -> Next;
            Fast_Ptr = Fast_Ptr -> Next -> Next;
              if(Slow_Ptr == Fast_Ptr)
                {
                    cout << "\nLoop Exists In The Linked List." << endl;
                    cout << "The Length Of the loop is : " << lengthOfLoop(Slow_Ptr) << endl;
                    return ;
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
      while(Temp -> Next != n)
        {
            Len++;
            Temp = Temp -> Next;
        }
    return Len;
}
int main(void)
{
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    insertAtEnd(9);
    insertAtEnd(11);
    Head -> Next -> Next -> Next = Head; //Test case to check if the loop exists in the linked list.
    detectLoop(Head);
    return 0;
}
