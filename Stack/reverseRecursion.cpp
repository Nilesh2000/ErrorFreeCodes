//Program to reverse a stack using recursion.
# include <iostream>
# include <stack>

using namespace std;

stack <int> S;

void insertAtBottom(int x)
{
    if(S.size() == 0)
      S.push(x);
    else
    {
      //All items are held in Function Call Stack until we reach end of the stack.
      //When the stack becomes empty, the st.size() becomes 0, the above if  part is executed and the item is inserted at the bottom.
      int a = S.top();
      S.pop();
      insertAtBottom(x);
      //Push allthe items held in Function Call Stack once the item is inserted at the bottom
      S.push(a);
    }
}

void reverseStack()
{
    if(S.size() > 0)
    {
      //Hold all the items in the function stack until we reach the end of the stack.
      int x = S.top();
      S.pop();
      reverseStack();
      //Insert All the items held in the function stack one by one. Insert all the items at the bottom of the stack.
      insertAtBottom(x);
    }
}

int main(void)
{
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    cout << "\nOriginal Stack : 5 4 3 2 1";

    reverseStack();

    cout << "\nReversed Stack : ";
    while(!S.empty())
    {
        int Top = S.top();
        cout << Top << " ";
        S.pop();
    }

    return 0;
}
