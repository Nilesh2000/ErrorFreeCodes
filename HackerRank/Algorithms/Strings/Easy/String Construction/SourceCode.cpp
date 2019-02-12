# include <iostream>
# include <string>
using namespace std;
int main()
{
    int n;
    string s;
    cin >>n;
     while(n--)
     {
         cin >>s;
         int Arr[26]={0}, Count=0;
          for(int i=0;i<s.length();i++)
              Arr[s[i]-'a']=1;
          for(int i=0;i<26;i++)
            if(Arr[i]!=0)
                Count++;
         cout <<Count <<endl;
     }
    return 0;
}
