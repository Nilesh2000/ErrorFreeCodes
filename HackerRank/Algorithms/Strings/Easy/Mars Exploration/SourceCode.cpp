# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s;
    int Count=0;
    cin >>s;
     for(int i=0;s[i]!='\0';i+=3)
     {
         if(s[i]!='S')
             Count++;
         if(s[i+1]!='O')
             Count++;
         if(s[i+2]!='S')
             Count++;
     }
    cout <<Count;
    return 0;
}
