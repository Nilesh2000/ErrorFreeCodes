//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  int x, n;
  cin >> n;
  int Arr[n];
    for(int i = 0 ; i < n ; i++)
      {
          cin >> Arr[i];
      }
  //A simple implementation of Kadane's algorithm has been used to solve this problem.
  int Max = *max_element(Arr, Arr + n);
  int Ans = 1, Count = 0; //Ans is initialized to least possible length.
    for(int i = 0 ; i < n ; i++)
      {
          if(Arr[i] == Max)
            {
                Count++; //Count is incremented everytime the maximum element is found consecutively in the array as mean will become larger
                          //only if larger elements are used.
            }
          else
            {
                Count = 0;
            }
        Ans = max(Ans, Count);
      }
  cout << Ans << endl;
  return 0;
}
//End Of Program
