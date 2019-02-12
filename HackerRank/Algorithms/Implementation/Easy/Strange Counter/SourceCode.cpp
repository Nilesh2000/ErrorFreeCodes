# include <iostream>
using namespace std;
int main()
{
    long long n, p=3;
    cin >>n;
     while(n>p)
     {
         n-=p;
         p*=2;
     }
    cout <<p-n+1;
    return 0;
}
