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
         int Len=s.length(), Count=0;
          for(int i=0,j=Len-1;i<Len/2;i++,j--)
             Count+=abs(s[i]-s[j]);
         cout <<Count <<endl;
     }
    return 0;
}
