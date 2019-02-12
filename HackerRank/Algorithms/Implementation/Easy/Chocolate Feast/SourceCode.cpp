# include <iostream>
using namespace std;
int main()
{
    int t, n, c, m;
    cin >>t;
     while(t--)
     {
         cin >>n >>c >>m;
         int Count=0, Wrapper=0;
         Count=Wrapper=n/c;
          while(Wrapper>=m)
          {
              Wrapper-=m;
              Count++;
              Wrapper++;
          }
         cout <<Count <<endl;
     }
    return 0;
}
