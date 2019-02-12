//Header Files
# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
# include <cstring>

# define pb push_back

using namespace std;

const int numOfAlphabets = 26;

int main(void) //Driver Function
{
  string s;
  cin >> s;
  int Turns = 0, Arr[numOfAlphabets] = {0};
  //Count frequency of each alphabet present in the string
    for(int i = 0 ; i < s.length() ; i++)
      {
          Arr[s[i] - 'a'] ++;
      }
  //If an alphabet has a frequency that is an odd number, then increment the number of turns played, because if an
  //alphabet has a frequency which is an odd number, it is the alphabet which will be deleted by any one of the players
  //when it is their turn because that is the most optimal way possible such that a palindrome is formed before the player
  //plays his turn.
    for(int i = 0 ; i < numOfAlphabets ; i++)
      {
          if(Arr[i] % 2)
            {
                Turns++;
            }
      }
  //Check if the below-mentioned condition is true because, the first person is bound to win if either no turns are played
  //or if the number of alphabets in the string having a frequency as an odd number is actually odd.
    if(Turns % 2 == 1 || Turns == 0)
      {
          cout << "First" << endl;
      }
    else
      {
          cout << "Second" << endl;
      }
  return 0;
}
//End Of Program
//Refer https://codeforces.com/blog/entry/6779 for a mathematical proof.
