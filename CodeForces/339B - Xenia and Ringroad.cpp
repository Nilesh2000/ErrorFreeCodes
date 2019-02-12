//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    long long a, n, m, Start=1, Count = 0; //House numbers start from 1 on the ringroad
    cin >> n >> m;
      while(m--)
        {
            cin >> a;
              if(a > Start)
                {
                    Count += (a - Start);
                }
              else if (a < Start) //Need to use elese if ladder in order to check for the test case if Start becomes equal to a
                {
                    Count += (n - Start + a);
                }
            Start = a;
        }
    cout <<Count <<endl;
    return 0;
}
//End Of Program
