# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s;
    int Letter[26]={0}, Flag=0;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
         if(islower(s[i]))
             Letter[s[i]-'a']++;
        else if(isupper(s[i]))
            Letter[s[i]-'A']++;
    }
    for(int i=0;i<26;i++)
    {
        if(Letter[i]==0)
        {
            Flag=1;
            cout <<"not pangram";
             break;
        }
    }
    if(Flag==0)
        cout <<"pangram";
     return 0;    
}
