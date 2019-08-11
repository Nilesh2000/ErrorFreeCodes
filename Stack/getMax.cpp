//A program to calculate the largest element in a stack.
# include <iostream>
# include <stack>

using namespace std;

class Stack
{
    stack <int> mainStack, trackStack;
  public:
    /*
    Create an auxiliary stack, say ‘trackStack’ to keep the track of maximum element
    Push the first element to both mainStack and the trackStack.
    Now from the second element, push the element to the main stack. Compare the element with the top element of the track stack, if the current element is
    greater than top of trackStack then push the current element to trackStack otherwise push the top element of trackStack again into it.
    If we pop an element from the main stack, then pop an element from the trackStack as well.
    Now to compute the maximum of the main stack at any point, we can simply print the top element of Track stack.
    */
    void pushData(int x)
    {
        mainStack.push(x);
        if(mainStack.size() == 1)
        {
            trackStack.push(x);
            return ;
        }

        if(x > trackStack.top())
        {
            trackStack.push(x);
        }
        else
        {
            trackStack.push(trackStack.top());
        }
    }

    void popData()
    {
        mainStack.pop();
        trackStack.pop();
    }

    int getMax()
    {
        return trackStack.top();
    }
};

int main(void)
{
    Stack S;
    S.pushData(10);
    S.pushData(15);
    S.pushData(20);
    cout << S.getMax() << " ";
    S.popData();
    cout << S.getMax() << " ";
    S.pushData(30);
    cout << S.getMax() << " ";
    return 0;
}
