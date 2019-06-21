//A program to check if a linked list is palindromic.
# include <iostream>
# include <stack>

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

void isListPalindrome()
{
    Node *Temp = Head; //Set a temporary pointer pointing to the head node
    stack <int> s; //Declare a stack to store the list elements in reverse order.
    bool isPalindrome = true; //Set a counter isPalindrome to true initially.
    while(Temp != NULL)
    {
        s.push(Temp -> Data); //Push data into the stack.
        Temp = Temp -> Next; //Continue to Traverse the linked list.
    }
    Temp = Head;
    while(Temp != NULL)
    {
        int Top = s.top(); //Set a variable Top to to peep into the stack.
        s.pop(); //Pop the topmost element of the stack
        if(Temp -> Data == Top) //Check if the data in the node of the list is the same as the value stored in Top.
        {
            isPalindrome = true; //Make no change to the counter.
        }
        else
        {
            isPalindrome = false; //Set the counter to false and break out of the loop.
             break;
        }
        Temp = Temp -> Next; //Continue to Traverse the linked list.
    }
    if(isPalindrome)
    {
        cout << "\nThe linked list is a palindrome." << endl;
    }
    else
    {
        cout << "\nThe linked list is not a palindrome." << endl;
    }
}

int main(void) //Driver function
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    isListPalindrome();
    return 0;
}
