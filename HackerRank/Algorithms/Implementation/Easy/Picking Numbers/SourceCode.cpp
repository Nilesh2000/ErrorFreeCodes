#include <iostream>
using namespace std;
int main() 
{
   int n, k, Max = 0;
    cin >>n;
    int a[100]={ };
     for(int i=0;i<n;i++)
     {
        cin >>k;
        a[k]++;
    }
    for(int i = 0;i<n-1;i++)
    {
        if(a[i]+a[i+1]>Max) 
            Max = a[i]+a[i+1];
    }
    cout<<Max;
    return 0;
}
