//A program to insert elements at the beginning of a linked list.
# include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node* Next;
};

Node* Head = NULL;

void insertAtBeginning(int x)
{
  Node* Temp = new Node();
  Temp -> Data = x;
  Temp -> Next = Head;
  Head = Temp;
}

void printList()
{
    Node* Temp = Head;
      while(Temp != NULL)
        {
            cout << Temp -> Data << " " ;
            Temp = Temp -> Next;
        }
}

int main(void)
{
    int n;
    cout << "Enter Number Of Elements In The List : ";
    cin >> n;
      for(int i = 0 ; i < n ; i++)
        {
            int Num;
            cin >> Num;
            insertAtBeginning(Num);
        }
    cout << "The List Is:-\n";
    printList();
    return 0;
}
