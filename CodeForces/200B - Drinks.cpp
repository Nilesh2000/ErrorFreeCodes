//Header Files
# include <iostream>
# include <algorithm>

using namespace std;

int main(void) //Driver Function
{
    int a, n;
    float Sum = 0;
    cin >> n;
      for(int i = 0 ; i < n ; i++)
        {
            cin >> a;
            Sum += a;
        }
    cout.precision(5);
    cout <<fixed << Sum / n << endl; //We need to find the average of all the entered percentages of orange drinks
    return 0;
}
//End Of Program
