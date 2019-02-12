# include <iostream>
using namespace std;
int main()
{
    int n, p;
    cin >>n >>p;
    int c1=p/2;
    int c2=n/2-(p/2);
    if(c1>c2)
      cout <<c2;
    else
       cout <<c1;
    return 0;
}
