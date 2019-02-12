//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void) //Driver Function
{
    int Count = 0; //Count is the length of the longest common suffix of s and t
    string s, t;
    cin >> s >> t;
      while(true)
       {
         //Starting with i and j from the last character of the string because deletion is permitted only from the
         //beginning of the string.
         int i = s.length() - Count - 1;
         int j = t.length() - Count - 1;
          if( i >= 0 && j >= 0 && s[i] == t[j] )
            Count++;
          else
            break;
       }
    cout << s.length() + t.length() - 2 * Count <<endl;
    //Summing up the lengths so that the number of characters to be deleted can be computed.
    //Subtracting with 2*Count so that the length of longest common suffix from both the strings can be omitted. 
    return 0;

}
//End Of Program
