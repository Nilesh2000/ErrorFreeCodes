# include <iostream>
using namespace std;
int main()
{
    int n, Num1=0, Num2=0;
    cin >>n;
    long long Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
    int Min=Arr[0];
    int Max=Arr[0];
     for(int i=1;i<n;i++)
     {
         if(Arr[i]>Max)
         {
             Max=Arr[i];
             Num1++;
         }
         else if(Arr[i]<Min)
         {
             Min=Arr[i];
             Num2++;
         }
     }
    cout <<Num1 <<" " <<Num2;
    return 0;
}
