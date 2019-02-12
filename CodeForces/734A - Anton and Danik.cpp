# include <iostream>
# include <cstring>
using namespace std;
int main()
{
  string s;
  int n, aCount=0, dCount=0;
  cin >>n>>s;
   for(int i=0;i<n;i++)
    {
      if(s[i]=='A')
       aCount++;
      else
       dCount++;
    }
   if(aCount>dCount)
    cout <<"Anton" <<endl;
   else if(dCount>aCount)
    cout <<"Danik" <<endl;
   else
    cout <<"Friendship" <<endl;
  return 0;
}
