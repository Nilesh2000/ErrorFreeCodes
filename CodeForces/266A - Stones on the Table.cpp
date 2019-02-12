# include <iostream>
# include <cstring>
using namespace std;
int main()
{
  int n, Count=0;
  string s;
  cin >>n >>s;
   for(int i=0;i<n-1;i++)
    {
      if(s[i]==s[i+1])
       Count++;
    }
  cout <<Count <<endl;
  return 0;
}
