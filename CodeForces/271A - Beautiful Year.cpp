# include <bits/stdc++.h>
using namespace std;
int isDistinct(int Num)
{
  bool Arr[10]={false};
   while(Num!=0)
    {
       if(Arr[Num%10])
        return 0;
      Arr[Num%10]=true;
      Num/=10;
    }
   if(Num==0)
    return 1;
}
int main()
{
  int Year;
  cin >>Year;
   while(1)
    {
     Year++;
      if(isDistinct(Year)==0)
       {
        continue;
       }
      else
       {
         cout <<Year <<endl;
         break;
       }
    }
  return 0;
}
