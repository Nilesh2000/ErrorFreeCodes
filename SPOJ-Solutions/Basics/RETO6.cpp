//Header Files
# include <iostream>
# include <string.h>

using namespace std;

int main()
{
    int n;
    string Ans="I hate", Odd_Word=" that I hate", Even_Word=" that I love", Last_Word=" it";
    cin >>n;
     for(int i=2;i<=n;i++)
     {
         if(i%2==0) //If Condition To Check Whether i Is Even
            Ans+=Even_Word;
         else
           Ans+=Odd_Word;
     }
     cout <<Ans+Last_Word <<endl;
    return 0;
}
//Source
//https://github.com/yular/CCplusplus-Project/blob/master/SPOJ/spoj_28617_RETO6.cpp
