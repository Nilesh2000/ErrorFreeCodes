//Header Files
# include <iostream>
# include <algorithm>

using namespace std;

int main(void) //Driver Function
{
    int n, Problems = 0;
    cin >> n;
    int Arr[n];
      for(int i = 0 ; i < n ; i++)
        {
            cin >> Arr[i];
        }
    sort(Arr, Arr + n);
     for(int i = 0 ; i < n ; i+=2)
      {
          Problems += Arr[i + 1] - Arr[i];
      }
    cout << Problems << endl;
    return 0;
}
//End Of Program
