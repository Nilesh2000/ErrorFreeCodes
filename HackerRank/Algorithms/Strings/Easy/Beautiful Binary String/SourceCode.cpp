# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s;
    int n, Count=0;
    cin >>n;
    cin >>s;
     for(int i=0;i<n;i++)
     {
         if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='0')
         {
             Count++;
             i+=2;
         }
     }
    cout <<Count <<endl;
    return 0;
}
