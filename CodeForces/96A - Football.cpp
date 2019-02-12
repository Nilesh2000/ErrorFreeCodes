# include <iostream>
using namespace std;
int main()
{
  string s;
  int Count=1;
  cin >>s;
   for(int i=1;i<s.length();i++)
    {
      if(s[i]==s[i-1])
       {
         Count++;
          if(Count==7)
           {
             cout <<"YES" <<endl;
             return 0;
           }
       }
      else
       Count=1;
    }
  cout <<"NO" <<endl;
  return 0;
}
