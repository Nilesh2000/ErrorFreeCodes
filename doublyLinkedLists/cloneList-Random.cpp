/*
Given a linked list having two pointers in each node. The first one points to the Next node of the list, however the other pointer is random and can point
to any node of the list. Write a program that clones the given list in O(1) space, i.e., without any extra space.
*/
# include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next, *Random;
    Node(int x)
    {
        Data = x;
        Next = Random = NULL;
    }
};

void printList(Node*);
/*
Create the Copy of node 1 and insert it between node 1 & node 2 in Original Linked List, create the Copy of 2 and insert it between 2 & 3. Continue in this
fashion for all nodes.
Then separate the original and cloned list.
*/
Node *cloneList(Node *Start) //Start stores the address of the head of the list.
{
  Node *Cur = Start, *Temp; //Set Cur pointing to Start initially

  while(Cur != NULL) //Traverse till the end of the doubly linked list
  {
      Temp = Cur -> Next; //Set temp pointing to the Next node of cur
      Cur -> Next = new Node(Cur -> Data); //Create a duplicate node of Cur and link it with Cur itself.
      Cur -> Next -> Next = Temp; //Then the Next pointer of the duplicate node should point to Temp
      Cur = Temp; //Then, set Cur to Temp so that we can create the duplicate node of the Next element
  }
  /*
  The list is:-
  1 --> 1 --> 2 --> 2 --> 3 --> 3 --> 4 --> 4 --> 5 --> 5
  */
  Cur = Start;

  //Now we set the random pointers of the newly created nodes.
  while(Cur != NULL) //Traverse till the end of the list
  {
          Cur -> Next -> Random = Cur -> Random; //Set the random pointer of the newly created node to the random pointer of the original node
          //Move to the original node, skipping the newly added node.
          Cur = Cur -> Next -> Next;
  }

  //Now, we separate the Original and the Copy list
  Node *Original = Start, *Copy = Start -> Next;
  //Save the start of copied linked list
  Temp = Copy;
  while(Original && Copy)
  {
      /*
      We use conditional operators so that the code looks more elegant.
      If Copy -> Next is not NULL, set Copy -> Next to Copy -> Next -> Next, else just set it to Copy -> Next.
      */
      Original -> Next = Original -> Next -> Next;
      Copy -> Next = Copy -> Next ? Copy -> Next -> Next : Copy -> Next;
      Original = Original -> Next; //Move original one node forward
      Copy = Copy -> Next; //Move copy one node forward too.
  }
  return Temp; //Return the start of the copied linked list
}

void printList(Node *Start)
{
    Node *Ptr = Start;
    while(Ptr)
    {
        cout << "Data = " << Ptr -> Data << ", Random = " << Ptr -> Random -> Data << endl;
        Ptr = Ptr -> Next;
    }
}

int main(void)
{
    Node *Head = new Node(1);
    Head -> Next = new Node(2);
    Head -> Next -> Next = new Node(3);
    Head -> Next -> Next -> Next = new Node(4);
    Head -> Next -> Next -> Next -> Next = new Node(5);
    Head -> Random = Head -> Next -> Next;
    Head -> Next -> Random = Head;
    Head -> Next -> Next -> Random = Head -> Next -> Next -> Next -> Next;
    Head -> Next -> Next -> Next -> Random = Head -> Next -> Next -> Next -> Next;
    Head -> Next -> Next -> Next -> Next -> Random = Head -> Next;
    cout << "Initial doubly linked list:-\n";
    /*
    The list is:-
          |-----------------|
    |----|    |---------|   |
    1 -> 2 -> 3 -> 4 -> 5 --|
    | --------|    |----|

    Data = 1, Random = 3
    Data = 2, Random = 1
    Data = 3, Random = 5
    Data = 4, Random = 5
    Data = 5, Random = 2
    */
    printList(Head);

    cout << "\nCloned doubly linked list:-\n";
    Node *cloneHead = cloneList(Head);
    printList(Head);

    return 0;
}
