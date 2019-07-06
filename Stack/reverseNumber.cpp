//A program to reverse a number using stack operations.
# include <iostream>
# include <stack>

using namespace std;

int reverseNumber(int Num)
{
    stack <int> S;
    while(Num != 0)
    {
        S.push(Num % 10);
        Num /= 10;
    }

    int Rev = 0, i = 1;
    while(!S.empty())
    {
        int p = S.top();
        S.pop();
        Rev += (p * i);
        i *= 10;
    }
    return Rev;
}

//Driver function
int main(void)
{
    int Num = 1234;
    cout << reverseNumber(Num);
    return 0;
}
