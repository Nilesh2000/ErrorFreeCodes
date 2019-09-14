/*
Sort a binary string, it contains 0s and 1s only in O(n)
*/
# include <iostream>
# include <string>

using namespace std;

int main(void)
{
    string s = "01011100", Res = "";
    int Len = s.length(), count0 = 0;
    for(int i = 0 ; i < Len ; i++)
    {
      if(s[i] == '0')
        count0++;
    }
    for(int i = 0 ; i < count0 ; i++)
      Res += '0';
    for(int i = 0 ; i < Len - count0 ; i++)
      Res += '1';
    cout << Res;
    return 0;
}
