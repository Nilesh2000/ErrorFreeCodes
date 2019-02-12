//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void) //Driver Function
{
    int n, Penalty, Short = 0, shortOrEqual = 0, worstTime, bestTime;
    cin >> n >> Penalty;
    string s[n], Password;
      for(int i = 0 ; i < n ; i++)
        {
            cin >> s[i];
        }
    cin >> Password;
      for(int i = 0 ; i < n ; i++)
        {
            if(s[i].length() < Password.length())
              {
                  Short++;
              }
             if(s[i].length() <= Password.length())
              {
                    shortOrEqual++;
              }
        }
    bestTime = Short + (Short / Penalty) * 5 + 1;
    worstTime = shortOrEqual + ( (shortOrEqual - 1) / Penalty ) * 5;
    cout << bestTime << " " << worstTime <<endl;
    return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/47457
