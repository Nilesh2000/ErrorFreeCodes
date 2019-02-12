# include <iostream>
using namespace std;
int main()
{
    int n, k, Doses=0;;
    cin >>n >>k;
    int Temp=k;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
     for(int i=0;i<n;i++)
     {
         if(Arr[i]>Temp)
          Temp=Arr[i];
     }
     if(Temp>k)
       cout <<Temp-k;
     else
        cout <<0;
    return 0;
}
