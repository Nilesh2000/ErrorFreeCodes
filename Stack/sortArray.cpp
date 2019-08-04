//A program to sort an array using a stack.
# include <iostream>
# include <stack>

using namespace std;

stack<int> sortStack(stack<int> input)
{
    stack <int> tmpStack;

    while(!input.empty())
    {
        int Temp = input.top(); //Set the top element of the stack as the smallest initially.
        input.pop();

        while(!tmpStack.empty() && tmpStack.top() < Temp) //Run the loop till stack is not empty and the top element is less than stack
        {
            input.push(tmpStack.top()); //Keep pushing elements into the temp stack. (tmpStack will always be sorted)
            tmpStack.pop();
        }
        tmpStack.push(Temp); //Else just push the temporary element into the stack.
    }

    return tmpStack;
}

void pushAndDisplay(int Arr[], int n)
{
    stack <int> input;
    for(int i = 0 ; i < n ; i++)
      input.push(Arr[i]);

    stack<int> newStack = sortStack(input);

    //Store the elements of the stack into the array.
    for(int i = 0 ; i < n ; i++)
    {
        Arr[i] = newStack.top();
        newStack.pop();
    }
}

int main(void)
{
    int Arr[] = {9, 7, 6, 5, 2, 4};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    pushAndDisplay(Arr, n);
    for(int i = 0 ; i < n ; i++)
      cout << Arr[i] << " ";
    return 0;
}
