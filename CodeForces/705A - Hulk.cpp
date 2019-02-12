//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void ) //Driver function
{
    int n;
    string Ans="I hate", Odd_Word=" that I hate", Even_Word=" that I love", Last_Word=" it";
    cin >> n;
      for(int i = 2; i <= n; i++)
        {
          if(i % 2) //If Condition To Check Whether i Is Even
            Ans += Odd_Word;
          else
            Ans += Even_Word;

        }
    cout << Ans + Last_Word << endl;
    return 0;
}
//End Of Program
