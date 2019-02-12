# include <iostream>
using namespace std;
int main()
{
    int n, k, Count=0, Page=1;
    cin >>n >>k;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=Arr[i];j++)
        {
            if(j==Page)
                Count++;
            if(j==Arr[i] || j%k==0)
                Page++;
        }
    }
    cout <<Count;
    return 0;
}
