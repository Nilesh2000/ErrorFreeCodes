//A program to sort a stack using another temporary stack.
# include <iostream>
# include <stack>

using namespace std;

/*
The idea here is to maintain two stacks. Initially the second stack is empty.
While input stack is NOT empty do this:
    ->Pop an element from input stack call it temp.
    ->while temporary stack is NOT empty and top of temporary stack is greater than temp:
      ->pop from temporary stack and push it to the input stack
    ->push temp in temporary stack
*/
stack <int> sortStack(stack <int> &input)
{
    stack <int> tmpStack;
    while(!input.empty())
    {
        int Tmp = input.top();
        input.pop();
        while(!tmpStack.empty() && tmpStack.top() > Tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(Tmp);
    }
    return tmpStack;
}

int main(void)
{
    stack <int> S;
    S.push(34);
    S.push(3);
    S.push(31);
    S.push(98);
    S.push(92);
    S.push(23);
    stack <int> sortedStack = sortStack(S);
    cout << "\nSorted elements : ";
    while(!sortedStack.empty())
    {
        int p = sortedStack.top();
        sortedStack.pop();
        cout << p << " ";
    }
    return 0;
}
