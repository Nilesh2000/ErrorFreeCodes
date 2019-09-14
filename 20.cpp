# include <iostream>

using namespace std;

int main()
{
    int n, k;
    cout << "\nEnter a number and precision : ";
    cin >> n >> k;
    float Ans; //Variable to store the square root.
    int Start = 0, End = n;

    while(Start <= End)
    {
        int Mid = ((Start + End) / 2);
        if(Mid * Mid == n)
        {
            Ans = Mid;
             break;
        }
        else if(Mid * Mid < n)
        {
            Start = Mid + 1;
            Ans = Mid;
        }
        else
        {
            End = Mid - 1;
        }
    }

    float Increment = 0.1;
    for(int i = 0 ; i < k ; i++)
    {
        while(Ans * Ans <= n)
        {
            Ans += Increment;
        }
        Ans -= Increment;
        Increment /= 10;
    }
    cout << Ans;
}
