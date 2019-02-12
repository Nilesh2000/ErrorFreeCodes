# include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, Flag=0, Min=INT_MAX;
    cin >>n;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
     for(int i=0;i<n;i++)
     {
         for(int j=i+1;j<n;j++)
         {
             if(Arr[i]==Arr[j])
             {
                 if(abs(i-j)<Min)
                 {
                     Min=abs(i-j);
                     Flag=1;
                 }   
             }
         }
     }
    if(Flag==0)
       Min=-1;
    cout <<Min;
    return 0;
}
