# include <iostream>
using namespace std;
int main()
{
    int n, Max=0;
    cin >>n;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
    for(int i=0;i<n;i++)
    {
        int Count=0;
        for(int j=0;j<n;j++)
        {
            if(Arr[i]==Arr[j])
                Count++;
        }
        if(Count>Max)
            Max=Count;
    }
    cout <<n-Max;
    return 0;
}
