# include <iostream>
using namespace std;
int main()
{
    int n, d, Count=0;;
    cin >>n >>d;
    int Arr[n];
     for(int i=0;i<n;i++)
        cin >>Arr[i];
     for(int i=0;i<n;i++)
     {
         for(int j=i+1;j<n;j++)
         {
             if(Arr[j]-Arr[i]==d)
             {
                 for(int k=j+1;k<n;k++)
                 {
                  if(Arr[k]-Arr[j]==d)
                      Count++;
                 }
             }
         }
     }        
    cout <<Count;
    return 0;
}
