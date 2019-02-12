# include <iostream>
using namespace std;
int main()
{
    int n, k, Num=0;
    cin >>n >>k;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i<j && (Arr[i]+Arr[j])%k==0)
                Num++;
        }
    }
    cout <<Num;
    return 0;
}
