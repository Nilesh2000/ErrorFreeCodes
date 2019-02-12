# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s;
    int Heights[26];
     for(int i=0;i<26;i++)
         cin >>Heights[i];
    cin >>s;
    int Len=s.length();
    int Max_Height=-1;
     for(int i=0;i<Len;i++)
     {
         if(Heights[s[i]-'a']>Max_Height)
             Max_Height=Heights[s[i]-'a'];
     }
    cout <<Len*Max_Height <<endl;
    return 0;
}
