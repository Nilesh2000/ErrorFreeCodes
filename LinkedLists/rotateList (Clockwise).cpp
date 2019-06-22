//A program to rotate the elements of a linked list in clockwise fashion.
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

void printList()
{
    Node *Temp = Head;
      while(Temp != NULL)
        {
            cout << Temp -> Data << " ";
            Temp = Temp -> Next;
        }
}

int lengthOfList()
{
  int Count = 0;
  Node *Temp = Head;
    while(Temp != NULL)
      {
          Count++;
          Temp = Temp -> Next;
      }
  return Count;
}

//Function which performs the job.
void rotateList()
{
    Node *Temp = Head, *Prev = NULL;
    while(Temp -> Next != NULL) //We use Temp -> Next because we don't want Prev to go till the last node but only till the 2nd last node.
    {
        Prev = Temp;
        Temp = Temp -> Next;
    }
    Prev -> Next = NULL; //This is done because there are no more nodes after the second last node.
    Temp -> Next = Head; //This is done because new first node now points to the older first node whose address is currentlt stored in Head.
    Head = Temp; //Set Head to the address of Temp as Temp is now the new first node.
}

int main(void)
{
    int n;
    for(int i = 10 ; i <= 60 ; i += 10)
    {
        insertAtEnd(i);
    }
    printList();
    cout << "\nEnter the number of rotations : ";
    cin >> n;
    int k = n % lengthOfList(); //Taking modulo because it is redundant to rotate the list more times than the number of elements in the
                                //list.
    cout << "List after rotating " << n << " time(s) is : ";
    for(int i = 0 ; i < k ; i++)
    {
        rotateList();
    }
    printList();
    cout << endl;
    return 0;
}
