//Header Files
# include <bits/stdc++.h>

using namespace std;

int main(void) //Driver Function
{
    int n;
    string s, newStr;
    cin >> n >> s;
    //To find the answer we can iterate through the given string from the left to the right and add each letter in the
    //answer string — one letter to the begin, next letter to the end, next letter to begin and so on.
    //The length of the string is the deciding factor in the program.
        for(int i = 0 ; i < n ; i++) //Iterate through the string from 0 to n
          {
              if((n - i) % 2) //If n-i is odd, add character to the end of the string
                {
                    newStr += s[i];
                }
              else //If n-i is even, add character to the beginning of the string
                {
                    newStr = s[i] + newStr;
                }
          }
    cout << newStr << endl;
    return 0;
}
//End Of Program
//http://programming-jinnatul.blogspot.com/2018/10/codeforces-decoding-746b.html
