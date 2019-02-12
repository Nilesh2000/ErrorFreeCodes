# include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    string s;
     while(n--)
     {
         cin >>s;
         int Count=0;
          for(int i=0;s[i]!='\0';i++)
          {
              if(s[i]==s[i+1])
                  Count++;
          }
         cout <<Count <<endl;
     }
    return 0;
}
