//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void) //Driver Function
{
    int Len, n;
    string s;
    cin >> n;
      while(n--)
        {
            cin >> Len >> s;
            bool Flag = true;
            //If some string can't be transformed to palindrome then it has some pair of positions (i, n − i + 1) with
            //different letters on them (as no such pair affects any other pair). Thus you need to check each pair for
            //i from 1 to n / 2 and verify that the distance between the corresponding letters is either 0 or 2.
              for(int i = 0 ; i < Len / 2 ; i++)
                {
                    int Diff = abs(s[i] - s[Len - i - 1]);
                      if(Diff != 0 && Diff != 2) //Checking for both 0 and 2 since the charcters in the string can either
                                                  //be incremented or decremented
                        {
                            Flag = false;
                            cout << "NO" << endl;
                             break;
                        }
                }
              if(Flag)
                  {
                      cout << "YES" <<endl;
                  }
        }
    return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/61311
