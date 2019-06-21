//A program to insert elements at the end of a linked list.
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

int getIntersectionNode(Node *, Node *, int);

void insertAtEnd(Node **A, int x) //A refers to the address of the head node.
{
    Node *Temp = new Node(); //Allocate memory to create a new node.
    Temp -> Data = x; //Initialize the Data of the node to the parameter passed.
      if((*A) == NULL) //Check if the list is initially empty.
        {
            (*A) = Temp; //Set the address of the newly allocated node to Head.
            return ;
        }
    //If the list is not empty,

    Node *lastNode = *A; //Set a temporary variable of type Node to Head.

    while(lastNode -> Next != NULL) //Traverse the linked list till the end of the list.
      {
          lastNode = lastNode -> Next; //Keep moving to the next node.
      }
  lastNode -> Next = Temp; //Set the address of the last node to the newly allocated node in memory.
}

//Calculating Length of the linked list.
int countNodes(Node *A)
{
    Node *Temp = A; //Set a temporary pointer as the head node
    int Count = 0;
      while(Temp != NULL)
        {
            Count++;
            Temp = Temp -> Next;
        }
    return Count;
}

int pointOfIntersection(Node *A1, Node *A2) //A1 and A2 are addresses of the head nodes of the 2 linked lists.
{
    int c1 = countNodes(A1);
    int c2 = countNodes(A2);
    int Diff = abs(c1 - c2);
    return getIntersectionNode(A1, A2, Diff); //Returns absolute difference in the length of the two lists.
}

/*
The underlying principle is to traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal number
of nodes. Then we can traverse both the lists in parallel till we come across a common node. Getting a common node is done by comparing the address
of the nodes.
*/

int getIntersectionNode(Node *A1, Node *A2, int d) //A1 and A2 are addresses of the head nodes of the 2 linked lists.
{
    Node *Cur1 = A1;
    Node *Cur2 = A2;
      for(int i = 0 ; i < d ; i++)
        {
            Cur1 = Cur1 -> Next;
        }
      while(Cur1 != NULL && Cur2 != NULL)
        {
            if(Cur1 == Cur2)
              {
                  return Cur1 -> Data;
              }
          //No point in writing else here because it is redundant.
          Cur1 = Cur1 -> Next;
          Cur2 = Cur2 -> Next;
        }
    return -1;
}

int main(void)
{
    Node *Head1 = NULL;
    Node *Head2 = NULL;
/*
    //T1 (c1 > c2)
    //List 1 : 3 6 9 15 30
    //List 2 : 10 15 25
    insertAtEnd(&Head1, 3);
    insertAtEnd(&Head1, 6);
    insertAtEnd(&Head1, 9);
    insertAtEnd(&Head1, 15);
    insertAtEnd(&Head1, 30);
    insertAtEnd(&Head2, 10);
    insertAtEnd(&Head2, 15);
    Head1 -> Next -> Next -> Next = Head2 -> Next; //The address for the data 15 should be same in both the lists.
    insertAtEnd(&Head2, 25);

    //T2 (c1 == c2)
    //List 1 : 3 6 15
    //List 2 : 10 15 25
    insertAtEnd(&Head1, 3);
    insertAtEnd(&Head1, 6);
    insertAtEnd(&Head1, 15);
    insertAtEnd(&Head2, 10);
    insertAtEnd(&Head2, 15);
    Head1 -> Next -> Next = Head2 -> Next; //The address for the data 15 should be same in both the lists.
    insertAtEnd(&Head2, 25);
*/
    //T3 (c1 < c2)
    //List 1 : 3 15
    //List 2 : 10 12 15 35 45 55 65
    insertAtEnd(&Head1, 3);
    insertAtEnd(&Head1, 15);
    insertAtEnd(&Head2, 10);
    insertAtEnd(&Head2, 12);
    insertAtEnd(&Head2, 15);
    Head1 -> Next = Head2 -> Next -> Next; //The address for the data 15 should be same in both the lists.
    insertAtEnd(&Head2, 35);
    insertAtEnd(&Head2, 45);
    insertAtEnd(&Head2, 55);
    insertAtEnd(&Head2, 65);

    cout << "The Data Stored In The Node At The Point Of Intersection Is : " << pointOfIntersection(Head1, Head2) << endl;
    return 0;
}
