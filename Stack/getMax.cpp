//A program to retrieve the largest element present in a stack.
# include <iostream>
# include <stack>

using namespace std;

stack <int> S;
int maxElement;

/*
Push(x) : Inserts x at the top of stack.

If stack is empty, insert x into the stack and make maxEle equal to x.
If stack is not empty, compare x with maxEle. Two cases arise:
If x is less than or equal to maxEle, simply insert x.
If x is greater than maxEle, insert (2*x – maxEle) into the stack and make maxEle equal to x. For example, let previous maxEle was 3. Now we want to insert 4.
We update maxEle as 4 and insert 2*4 – 3 = 5 into the stack.

Pop() : Removes an element from top of stack.

Remove element from top. Let the removed element be y. Two cases arise:
If y is less than or equal to maxEle, the maximum element in the stack is still maxEle.
If y is greater than maxEle, the maximum element now becomes (2*maxEle – y), so update (maxEle = 2*maxEle – y). This is where we retrieve previous maximum
from current maximum and its value in stack. For example, let the element to be removed be 5 and maxEle be 4. We remove 5 and update maxEle as 2*4 – 5 = 3.
*/

void pushData(int Data)
{
    if(S.empty()) //If the stack is initially empty
    {
        //Just blindly insert the element into the stack and set the maxElement to Data.
        S.push(Data);
        maxElement = Data;
        cout << Data << " is inserted into the stack.\n";
        return ;
    }

    if(Data > maxElement)  //If element to be inserted is greater than maxElement
    {
        S.push(2 * Data - maxElement);
        maxElement = Data;
    }
    else //Else just push into the stack
      S.push(Data);

    cout <<  Data << " is inserted into the stack.\n";
}

void popData()
{
    if(S.empty())
    {
        cout << "\nStack Underflow. No elements to pop.\n";
        return ;
    }

    int Top = S.top();
    S.pop();

    if(Top > maxElement)
    {
        cout << maxElement << " has been popped from the stack.\n";
        maxElement = 2 * maxElement - Top;
    }

    else
    {
        cout << Top << " has been popped from the stack.";
    }
}

void getMax()
{
    if(S.empty())
    {
        cout << "\nStack Underflow. No elements to pop.\n";
        return ;
    }

    cout << maxElement << " is the largest element in the stack.\n";
}

int main(void) //Dirver function
{
    pushData(2);
    pushData(3);
    pushData(1);
    pushData(5);
    getMax();
    popData();
    getMax();
    return 0;
}
//End of program
