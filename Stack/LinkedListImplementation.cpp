//A program to exhibit the linked list implementation of a stack.
# include <iostream>

using namespace std;

struct Node
{
  int Data;
  Node *Next;
};

Node *Top = NULL; //Top is initially NULL.

Node* isEmpty() //FUnction to check if stack is empty.
{
    return Top;
}

void Push(int x)
{
    Node *newNode = new Node(); //Allocate memory to create a new node.
    newNode -> Data = x; //Initialize the Data of the node to the parameter passed.
    newNode -> Next = Top; //Set the next field of newNode to Top.
    Top = newNode; //Set the address of top to the topmost node.
    cout << "\n" << x << " is pushed into the stack.";
}

void Pop()
{
    if(!isEmpty()) //Check if the stack is initially empty.
    {
        cout << "\nUnderflow error.";
        return ;
    }
    Node *Temp = Top; //Set a temporary pointer storing the address of the top element of the stack.
    Top = Top -> Next; //Set the address of top to the next element of the stack.
    int popElement = Temp -> Data; //Store the value pf the element to be popped in popElement.
    cout << "\n" << popElement << " has been popped from the stack.";
    delete Temp; //Delete the topmost node from the stack.
}

void Peep()
{
    if(!isEmpty())
    {
        cout << "\nUnderflow error.";
        return ;
    }
    cout << "\n" << Top -> Data << " is at the top of the stack."; //Display the topmost node of the stack.
}

//Driver function
int main(void)
{
    Push(10);
    Push(20);
    Push(30);
    Pop();
    Peep();
    return 0;
}
