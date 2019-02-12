# include <iostream>
using namespace std;
int main()
{
    int b, n, m, Max=-1;
    cin >>b >>n >>m;
    int KeyBoard[n], USB[m];
     for(int i=0;i<n;i++)
         cin >>KeyBoard[i];
    for(int i=0;i<m;i++)
        cin >>USB[i];
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
          int Res=KeyBoard[i]+USB[j];
          if(Res>Max && Res<=b) 
             Max=Res;
         }
     }
    cout <<Max;
    return 0;
}
