# include <iostream>
using namespace std;
int main()
{
    int n, Result=2, Like=2;
    cin >>n;
     for(int i=2;i<=n;i++)
     {
         Like*=3;
         Like/=2;
         Result+=Like;
     }
    cout <<Result;
    return 0;
}
