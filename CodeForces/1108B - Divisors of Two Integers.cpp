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
  int n;
  cin >> n;
  int Arr[n];
    for(int i = 0 ; i < n ; i++)
      {
          cin >> Arr[i];
      }
  sort(Arr, Arr + n);
  cout << Arr[n - 1] << " "; //Display the largest number present in the array.
    for(int i = n - 1 ; i > 0 ; i--)
      {
        //First condition checks whether the second largest number is actually a factor of the largest number and thus,
        //if it occurs twice. Second Condition displays the next largest number if it is not a factor of the largest
        //number of the array.
          if(Arr[i] == Arr[i - 1] || Arr[n - 1] % Arr[i])
            {
                cout << Arr[i] << endl;
                return 0;
            }
      }
}
//End Of Program
