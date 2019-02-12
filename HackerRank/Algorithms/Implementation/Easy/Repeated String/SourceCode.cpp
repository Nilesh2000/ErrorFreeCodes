# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s;
    long long n, Cnt=0, RemCnt=0, Rem, Rept;
    cin >>s >>n;
    long long Len=s.length();
    Rem=n%Len;
    Rept=n/Len;
     for(int i=0;i<Len;i++)
     {
      if(s[i]=='a')
        Cnt++;
      if(s[i]=='a' && i<Rem)
         RemCnt++;  
     }
    cout <<(Rept*Cnt)+RemCnt;
    return 0;
}
