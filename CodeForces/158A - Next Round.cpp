# include <iostream>
using namespace std;
int main()
{
  int n, k, Max, Count=0;
  cin >>n >>k;
  int Arr[n];
   for(int i=0;i<n;i++)
    {
     cin >>Arr[i];
      if(i+1==k)
       Max=Arr[i];
    }
   for(int i=0;i<n;i++)
    {
      if(Arr[i]>=Max && Arr[i]>0)
       {
         Count++;
       }
    }
  cout <<Count <<endl;
}
