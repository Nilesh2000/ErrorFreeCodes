# include <iostream>
# include <string.h>
using namespace std;
int main()
{
    int n, Count=0;
    char s[100], Letter[26]={0};
    cin >>n;
     for(int i=0;i<n;i++)
     {
         cin >>s;
          for(int j=0;j<strlen(s);j++)
          {
              char c=s[j];
               if(Letter[c-'a']==i)
               {
                  Letter[c-'a']++;
                   if(Letter[c-'a']==n)
                       Count++;
               }       
          }
     }
    cout <<Count;
    return 0;
}
