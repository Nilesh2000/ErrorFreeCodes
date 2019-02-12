//Header Files
# include <bits/stdc++.h>

using namespace std;

int main(void) //Driver Function
{
    int n, Height = 0, Cubes = 0;
    cin >> n;
      for(int i = 1 ; ; i++)
        {
            Cubes += i;
            Height += Cubes;
              if(Height > n)
                {
                    cout << i - 1 <<endl;
                     break;
                }
        }
    return 0;
}
//End Of Program
