//Header Files
# include <iostream>
# include <cstring>

using namespace std;

const int numOfAlphabets = 26;
int main(void) //Driver Function
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int Flag = 0, Arr[numOfAlphabets] = {0};
      for (int i = 0 ; i < s1.length() ; i++)
        {
            Arr[s1[i] - 'A']++;
        }
      for (int i = 0 ; i < s2.length() ; i++)
        {
            Arr[s2[i] - 'A']++;
        }
      for (int i = 0 ; i < s3.length() ; i++)
        {
            Arr[s3[i] - 'A']--;
        }
      for (int i = 0 ; i < numOfAlphabets ; i++)
        {
            if (Arr[i] != 0)
              {
                  Flag = 1;
                   break;
              }
        }
      if (Flag == 0)
        {
            cout << "YES" << endl;
        }
      else
        {
            cout << "NO" << endl;
        }
    return 0;
}
//End Of Program
