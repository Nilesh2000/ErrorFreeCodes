//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    int a, n, h, Count;
    cin >>n >>h;
    Count = n; //Initializing Count to n as minimum width has to be number of people
      while (n--)
        {
            cin >> a;
              if (a > h)
                {
                  Count++; //Incrementing Count Only if a > h
                }
        }
    cout <<Count <<endl;
    return 0;
}
//End Of Program
