//A program to insert nodes in a sorted fashion in a linked list.
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

Node *Head = NULL; //List is initially empty.

void sortedInsert(int x)
{
    Node *newNode = new Node();
    newNode -> Data = x;
    newNode -> Next = NULL;

    if(Head == NULL)
    {
        Head = newNode;
        return ;
    }

    if(Head -> Data > x)
    {
        newNode -> Next = Head;
        Head = newNode;
        return ;
    }

    Node *Cur = Head;

    while(Cur -> Next != NULL && Cur -> Next -> Data < x)
    {
        Cur = Cur -> Next;
    }

    newNode -> Next = Cur -> Next;
    Cur -> Next = newNode;
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
    sortedInsert(2);
    sortedInsert(1);
    sortedInsert(5);
    sortedInsert(4);
    printList();
    return 0;
}
