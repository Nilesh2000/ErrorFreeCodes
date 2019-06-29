# include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

Node *Last = NULL; //List is initially empty

void insertAtBeginning(int x)
{
    Node *Temp = new Node(); //Allocate memory to create a new node.
    Temp -> Data = x; //Initialize the Data of the node to the parameter passed.

    if(Last == NULL) //If the list is initially empty
    {
        Last = Temp; //Set the last node address to the address of Temp
        Temp -> Next = Last; //Set Temp -> Next to Last so that a link is created.
        return ;
    }
    //If the list is not empty
    Temp -> Next = Last -> Next; //Set Temp -> Next to Last -> Next which is initially pointing to the address of the first node.
    Last -> Next = Temp; //Set Last-> Next to address of Temp so that the link is created.
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
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);
    printList();
    return 0;
}
