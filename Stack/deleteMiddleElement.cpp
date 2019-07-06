//A program to delete the middle element of a stack.
# include <iostream>
# include <stack>

using namespace std;

//Curr is a variable used to check the number of elements traversed in the stack.
void deleteMidElement(stack <char> &S, int n, int Curr = 0) //Stack has to be passed by reference.
{
    if(S.empty() || Curr == n) //Check if stack is empty or if all elements are traversed.
      return ;

    char x = S.top(); //Variable to store the topmost element.
    S.pop(); //Delete the topmost element
    deleteMidElement(S, n, Curr + 1); //Recursive Call to function

    if(Curr != n / 2) //If the element to be traversed is not the middle element, push it into the stack.
      S.push(x);
}

void printStack(stack <char> S)
{
    while(!S.empty())
    {
        char n = S.top();
        S.pop();
        cout << n << " ";
    }
}

int main(void)
{
    stack <char> S;
    S.push('1');
    S.push('2');
    S.push('3');
    S.push('4');
    S.push('5');
    deleteMidElement(S, S.size());
    printStack(S);
    return 0;
}
