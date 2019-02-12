//Header Files
# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
# include <cstring>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  int x, n;
  long long Hours = 0;
  cin >> n >> x;
  long long Arr[n];
    for(int i = 0 ; i < n ; i++)
      {
          cin >> Arr[i];
      }
  sort(Arr, Arr + n);
    for(int i = 0 ; i < n ; i++)
      {
          Hours += (x * Arr[i]);
            if(x > 1)
              x--;
      }
  cout << Hours << endl;
  return 0;
}
//End Of Program
