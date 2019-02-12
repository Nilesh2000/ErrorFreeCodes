//Header Files
# include <bits/stdc++.h>

# define ll long long
# define pb push_back

using namespace std;

int main(void) //Driver Function
{
    int n;
    cin >> n;
    int Height[n], addFloors[n];
    //This problem can be solved in the following way. Let's iterate on given array from the right to the left and will
    //store in variable maxH the maximal height if house which we have already considered.Then the answer to house number
    //i is number max(0, maxH + 1 - hi), where hi number of floors in house number i.
    //Asymptotic behavior of this solution — O(n), where n — number of houses.
      for(int i = 0 ; i < n ; i++)
        {
            cin >> Height[i];
        }
    int Max = 0;
      for(int i = n - 1 ; i >= 0 ; i--)
        {
          //If the height of the ith floor exceeds the height of the floors to the right of it, then no need to add any floors.
          //Else
          //Basically, we are adding as many floors to the ith tower as that of the maximum number of floors on the towers are
          //present on the right to it. Adding 1 so that the number of floors on the tower exceeds the number of floors on
          //all the other towers and does not remain equal to it.
          addFloors[i] = Height[i] > Max ? 0 : Max - Height[i] + 1;
          Max = max(Max, Height[i]);
        }
       for(int i = 0 ; i < n ; i++)
        {
            cout << addFloors[i] << " ";
        }
    return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/20508
