# include <iostream>
using namespace std;
int main()
{
    int n, Num=0;
    cin >>n;
    long long Arr[n];
     for(int i=0;i<n;i++)
        cin >>Arr[i];
     int Max=Arr[0];
      for(int i=1;i<n;i++)
      {
          if(Arr[i]>Max)
           Max=Arr[i];
      }
      for(int i=0;i<n;i++)
      {
          if(Arr[i]==Max)
            Num++;
      }
      cout <<Num <<endl;
    return 0;
}
