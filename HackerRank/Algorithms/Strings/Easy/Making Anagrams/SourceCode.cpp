# include <iostream>
using namespace std;
int main()
{
    string s1, s2;
    int Count=0;
    cin >>s1 >>s2;
    int Letter_1[26]={0}, Letter_2[26]={0};
     for(int i=0;i<s1.length();i++)
         Letter_1[s1[i]-'a']++;
     for(int i=0;i<s2.length();i++)
         Letter_2[s2[i]-'a']++;
    for(int i=0;i<26;i++)
        Count+=abs(Letter_1[i]-Letter_2[i]);
    cout <<Count <<endl;
    return 0;
}
