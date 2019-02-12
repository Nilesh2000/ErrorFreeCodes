# include <iostream>
using namespace std;
int main()
{
    int n, Count=0, Flag=0;
    cin >>n;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
    for(int i=0;i<n-1;i++)
    {
        if(Arr[i]%2!=0)
        {
            Arr[i]++;
            Arr[i+1]++;
            Count+=2;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(Arr[i]%2!=0)
        {
            cout <<"NO";
            Flag=1;
             break;
        }
    }
    if(Flag==0)
        cout <<Count;
    return 0;
}
