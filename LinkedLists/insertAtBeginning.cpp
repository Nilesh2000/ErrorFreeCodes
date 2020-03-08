//A program to insert elements at the beginning of a linked list.
#include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

Node *Head = NULL; //List is initially empty

void insertAtBeginning(int x)
{
  Node *Temp = new Node(); //Allocate memory to create a new node.
  Temp->Data = x;          //Initialize the Data of the node to the parameter passed.
  Temp->Next = Head;       //Store the address of the first node in the newly created node which will therafter be the first node.
  Head = Temp;             //The address of the new first node is stored in Head.
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

int main(void)
{
  int n;
  cout << "Enter Number Of Elements In The List : ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int Num;
    cin >> Num;
    insertAtBeginning(Num);
  }
  cout << "The List Is:-\n";
  printList();
  return 0;
}
