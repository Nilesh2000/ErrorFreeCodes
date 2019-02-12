# include <iostream>
using namespace std;
int main()
{
    string s;
    int Flag, n;
    cin >>n;
     while(n--)
     {
         cin >>s;
         Flag=0;
          for(int i=1, j=s.length()-1;i<s.length();i++,j--)
          {
              if(abs(s[i]-s[i-1])!=abs(s[j]-s[j-1]))
              {
                  Flag=1;
                   break;
              }
          }   
         if(Flag==1)
             cout <<"Not Funny" <<endl;
         else
             cout <<"Funny" <<endl;
     }   
    return 0;
}
