//A program to display the nth Node from the end of a linked list.
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

Node *Head = NULL; //List is initially empty.

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
Maintain two pointers – reference pointer and main pointer. Initialize both reference and main pointers to head. First move reference pointer to n
nodes from head. Now move both pointers one by one until reference pointer reaches end. Now main pointer will point to nth node from the end.
Return main pointer.
*/
void PrintnthNodeFromLast(Node *A, int n)
{
    Node *Main_Ptr = A;
    Node *Ref_Ptr = A;
    int Count = 1;
      if(A != NULL) //If Head Is Not NULL
        {
            while(Count <= n)
              {
                  Ref_Ptr = Ref_Ptr -> Next;
                  Count++;
              }
        }
      while(Ref_Ptr != NULL)
        {
            Main_Ptr = Main_Ptr -> Next;
            Ref_Ptr = Ref_Ptr -> Next;
        }
    cout << "The nth Node From The End Is : " << Main_Ptr -> Data << endl;
}

//Recursive implementation
void nthNodeFromLast(Node *A, int n)
{
    static int i = 0;
      if(A == NULL)
        {
            return ;
        }
    nthNodeFromLast(A -> Next, n);
      if(++i == n)
        {
            cout << "The nth Node From The End Is : " << A -> Data << endl;
        }
}

int main(void)
{
    insertAtEnd(3);
    insertAtEnd(5);
    insertAtEnd(7);
    insertAtEnd(9);
    insertAtEnd(11);
    insertAtEnd(13);
    insertAtEnd(15);
    PrintnthNodeFromLast(Head, 2);
    nthNodeFromLast(Head, 2);
    return 0;
}
