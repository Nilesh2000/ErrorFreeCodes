# include <iostream>
using namespace std;
int main()
{
    int Test, n, Entry, Exit;
    cin >>n >>Test;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
     while(Test--)
     {
         cin >>Entry >>Exit;
         int Max=Arr[Entry];
          for(int i=Entry;i<=Exit;i++)
          {
              if(Arr[i]<Max)
                  Max=Arr[i];
                         
          }
         cout <<Max <<endl;
     }
    return 0;
}