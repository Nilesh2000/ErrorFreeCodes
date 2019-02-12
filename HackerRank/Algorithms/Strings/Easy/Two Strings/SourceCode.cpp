# include <iostream>
# include <string>
using namespace std;
int main()
{
    int n;
    cin >>n;
    string s1, s2;
     while(n--)
     {
         cin >>s1 >>s2;
         int Letter_1[26]={0}, Letter_2[26]={0}, Flag=0, Len=s1.length();
          for(int i=0;s1[i]!='\0';i++)
              Letter_1[s1[i]-'a']++;
         for(int i=0;s2[i]!='\0';i++)
              Letter_2[s2[i]-'a']++;
         for(int i=0;i<26;i++)
         {
           if(Letter_1[i]<=Letter_2[i] && Letter_1[i]!=0 && Letter_2[i]!=0)
            {
             Flag=1;
              break;
            }  
         }
         if(Flag==1)
             cout <<"YES" <<endl;
         else
             cout <<"NO" <<endl;
     }
    return 0;
}
