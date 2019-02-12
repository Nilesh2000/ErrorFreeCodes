# include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    int Arr[n], Count[n]={0};
     for(int i=0;i<n;i++)
     {
         cin >>Arr[i];
         Count[Arr[i]]++;
     }
    int Max=Count[0], Pos=0;
     for(int i=0;i<n;i++)
     {
         if(Count[i]>Max)
         {
             Max=Count[i];
             Pos=i;
         }
     }
    cout <<Pos;
    return 0;
}