//Header Files
# include <iostream>
# include <algorithm>
# include <array>

using namespace std;

int binarySearch(int Arr[], int n, int x) //Basically using this function to find the lower bound of the worm in the array
{
    int Ans = 0, First = 0, Last = n-1, Mid;
      while(First <= Last)
        {
            Mid = (First + Last) / 2;
              if(x <= Arr[Mid])
                {
                    Ans = Mid;
                    Last = Mid - 1;
                }
              else
                {
                    First = Mid + 1;
                }
        }
    return Ans;
}

int main(void) //Driver Function
{
    int m, n, Worm;
    cin >> n;
    int Pile[n];
    cin >> Pile[0];
      for(int i = 1 ; i < n ; i++)
        {
            cin >> Pile[i];
            Pile[i] += Pile[i-1]; //Creating a consecutive array
        }
    cin >> m;
      while(m--)
        {
            cin >> Worm;
            int Ans = binarySearch(Pile, n, Worm);
            cout << Ans + 1 << endl; //Incrementing answer by 1 since I am using a 0-indexed array
        }
    return 0;
}
//End Of Program
