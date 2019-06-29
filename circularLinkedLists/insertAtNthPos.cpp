# include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

Node *Last = NULL; //List is initially empty

void insertAtNthPos(int x, int n)
{
    Node *Temp = new Node(); //Allocate memory to create a new node.
    Temp -> Data = x; //Initialize the Data of the node to the parameter passed.

    if(Last == NULL) //If the list is initially empty
    {
        Last = Temp; //Set the last node address to the address of Temp
        Temp -> Next = Last; //Set Temp -> Next to Last so that a link is created.
        return ;
    }

    Node *Cur = Last;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        Cur = Cur -> Next;
    }
    Temp -> Next = Cur -> Next;
    Cur -> Next = Temp;
}

//The idea behind printing the elements of a circular linked list is to initialize a temporary Node pointer to Last -> Next.
//Then, run a do-while loop until Temp once again reached Last-> Next. Inside the loop, keep moving the pointer by one node.
//It is necessary to use a do-while loop because we have to make sure the loop is executed atlest once before termination.
void printList()
{
    Node *Temp = Last -> Next;
     do{
          cout << Temp -> Data << " ";
          Temp = Temp -> Next;
       }while(Temp != Last -> Next);
}

int main(void)
{
    insertAtNthPos(2, 1);
    insertAtNthPos(3, 2);
    insertAtNthPos(4, 1);
    insertAtNthPos(5, 2);
    printList();
    return 0;
}
