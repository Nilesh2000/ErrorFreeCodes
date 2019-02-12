# include <iostream>
# include <string>
using namespace std;
int main()
{
    int n;
    cin >>n;
     while(n--)
     {
         string s;
         cin >>s;
         int Len=s.length();
          if(Len%2!=0)
          {
              cout <<"-1" <<endl;
              continue;
          }
         int Letter[26]={0}, Count=0;
          for(int i=0;i<Len/2;i++)
              Letter[s[i]-'a']++;
         for(int i=Len/2;i<Len;i++)
              Letter[s[i]-'a']--;
         for(int i=0;i<26;i++)
              Count+=abs(Letter[i]);
         cout <<Count/2 <<endl;
     }
    return 0;
}
