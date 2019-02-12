//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    int a, First, n, Max, Min, Amaze = 0;
    cin >> n;
    cin >> First;
    Max = Min = First;
      while(n != 1)
        {
            cin >> a;
              if(a > Max)
                {
                    Amaze++;
                    Max = a;
                }
              else if(a < Min)
                {
                    Amaze++;
                    Min = a;
                }
            n--;
        }
    cout << Amaze << endl; 
    return 0;
}
//End Of Program
