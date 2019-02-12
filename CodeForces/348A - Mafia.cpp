//Header Files
# include <bits/stdc++.h>

# define ll long long

using namespace std;

int main(void) //Driver Function
{
    int a, n, Max = 0;
    long long int Sum = 0;
    cin >> n;
      for(int i = 0 ; i < n ; i++) //Necessary to use for loop because we will be using the value of n in the later part
                                  //of the program. Thus, while(n--) cannot be used.
        {
            cin >> a;
              if(Max < a)
                {
                    Max = a;
                }
            Sum += a;
        }
      if(ceil((double)Sum / (n - 1) < Max))
          cout << Max << endl;
      else
        cout << (int)ceil((double)Sum / (n - 1)) << endl;
    return 0;
}
//End Of Program
//Refer https://codeforces.com/blog/entry/9031 for an excellent explaination.
//https://github.com/Sharknevercries/Online-Judge/blob/master/CodeForce/348A%20Mafia.cpp
