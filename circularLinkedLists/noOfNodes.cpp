//A program to count the number of nodes in a circular linked list.
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

//Funnction to count number of nodes in the circular linked list.
int noOfNodes()
{
    int Count = 0; //Set count of nodes initially to zero.
    Node *Temp = Last; //Set a temporary pointer pointing to the variable which contains the address of the first node.
    //It is essential to use a do-while loop because we need to make sure the loop is executed atleast once before termination.
    if(Last != NULL)
    {
      do
      {
          Temp = Temp -> Next;
          Count++;
      }while(Temp != Last);
    }
    return Count;
}

int main(void)
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    cout << "\nNumber of elements in the circular linked list is : " << noOfNodes();
    return 0;
}
