# include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

Node *Last = NULL; //List is initially empty

void insertAtEnd(int x)
{
    Node *Temp = new Node(); //Allocate memory to create a new node.
    Temp -> Data = x; //Initialize the Data of the node to the parameter passed.

    if(Last == NULL) //If the list is initially empty
    {
        Last = Temp; //Set the last node address to the address of Temp
        Temp -> Next = Last;  //Set Temp -> Next to Last so that a link is created.
    }

    Temp -> Next = Last -> Next; //Set the Next component of the newly created node to Last -> Next which is pointing to the first node.
    Last -> Next = Temp; //Couldn't come up with an explaination for this line. :)))
    Last = Temp; //Temp is now officially the last node.
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
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    printList();
    return 0;
}
