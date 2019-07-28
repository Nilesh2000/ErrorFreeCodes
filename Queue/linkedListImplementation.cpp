//A program to implement a queue using a linked list.
# include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

class Queue
{
    Node *Front, *Rear;

  public:

    Queue() //Constructor to set initial values of Front and Rear to NULL.
    {
        Front = Rear = NULL;
    }

    void Q_Insert(int x)
    {
        Node *Temp = new Node(); //Allocate memory to create a new node.
        Temp -> Data = x; //Initialize the Data of the node to the parameter passed.

        if(Front == NULL && Rear == NULL) //If the queue is initially empty.
        {
            Front = Rear = Temp; //Set front and rear both to the first node.
        }
        else
        {
            Rear -> Next = Temp; //Else, set the next pointer of the last node to the new node.
            Rear = Temp; //Set the rear node to be temp.
        }
        cout << x << " is inserted into the queue.\n";
    }

    void Q_Delete()
    {
        if(Front == NULL) //If the list is initially empty.
        {
            cout << "Deletion not possible. Queue is empty.\n";
            return ;
        }

        if(Front == Rear) //If the node to be deleted is the first node.
        {
            cout << Front -> Data << " has been deleted.\n";
            Front = Rear = NULL; //Set both front and Rear to NULL again.
        }

        else
        {
            Node *Temp = Front; //Declare a temporary pointer pointing to Front initially
            cout << Front -> Data << " has been deleted.\n";
            Front = Front -> Next; //Else, just move Front ahead by one node.
            delete Temp; //Delete the temporary variable that was initially storing the address of Front
        }
    }

    void Q_Display()
    {
        if(Front == NULL) //If the queue is initially empty,
        {
          cout << "Deletion not possible. Queue is empty.\n";
          return ;
        }

        Node *Temp = Front; //Declare a temporary pointer pointing to Front initially
        cout << "The elements of the queue are : ";
        while(Temp != NULL) //Traverse the queue till the last node
        {
            cout << Temp -> Data << " ";
            Temp = Temp -> Next; //Move ahead by one node at a time.
        }
        cout << endl;
    }

};

int main(void) //Driver function
{
    Queue Obj;
    Obj.Q_Delete();
    Obj.Q_Insert(1);
    Obj.Q_Insert(2);
    Obj.Q_Insert(3);
    Obj.Q_Delete();
    Obj.Q_Display();
    Obj.Q_Insert(5);
    return 0;
}
//End of program.
