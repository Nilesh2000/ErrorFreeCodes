# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s;
    int Count=0;
    cin >>s;
     for(int i=0;s[i]!='\0';i++)
     {
      if(isupper(s[i])!=0)
          Count++;
     }
    cout <<Count+1; 
    return 0;
}
