# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s;
    cin >>s;
    int Flag=0, Odd_Letter=0, Len=s.length(), Arr[26]={0};  
    for(int i=0;i<Len;i++)
        Arr[s[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        if(Arr[i]%2!=0)
            Odd_Letter++;
    }
    if(Odd_Letter>1)
        cout<<"NO";
    else 
        cout<<"YES";
    return 0;
}
