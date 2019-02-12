//Header Files
# include <bits/stdc++.h>

using namespace std;

int main(void) //Driver Function
{
    int n;
    cin >> n;
    int Arr1[n], Arr2[n], Sum1 = 0, Sum2 = 0, Pos = -1;
      for(int i = 0 ; i < n ; i++)
        {
            cin >> Arr1[i] >> Arr2[i]; //Accepting Input
            Sum1 += Arr1[i]; //Incrementing Sum
            Sum2 += Arr2[i];
        }
    int maxK = abs(Sum1 - Sum2); //Calculating current beauty
      for(int i = 0 ; i < n ; i++)
        {
            //Calculating Sum by Swapping the left and righ columns respectively
            int x = Sum1 - Arr1[i] + Arr2[i];
            int y = Sum2 - Arr2[i] + Arr1[i];
            if(abs(x - y) > maxK)
              {
                  maxK = abs(x - y);
                  Pos = i;
              }
        }
    cout << Pos + 1 << endl;
    return 0;
}
//End Of Program
