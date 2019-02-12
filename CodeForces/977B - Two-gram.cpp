//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void) //Driver Function
{
    int n, Res = 0;
    string s, Ans; //Ans is used to store the resultant two-gram strinf
    cin >> n >> s;
      for(int i = 0 ; i < n - 1 ; i++)
        {
          int Cur = 0;
            for(int j = 0 ; j < n - 1 ; j++) //Nested for loop to check if the ith and (i+1)st characters are always
                                            //the same to jth and (j+1)st characters respectively
              {
                  if(s[i] == s[j] && s[i + 1] == s[j + 1]) //If true, then increment the number of times a particular
                                                            //two-garm substring appears.
                    {
                        Cur++;
                    }
                  if(Res < Cur) //Check if the count of the next computed two-gram character is greater than the previous
                                //computed one.
                    {
                        Res = Cur;
                        Ans = string(1, s[i]) + string(1, s[i + 1]); //Create a string by initializing s[i] to be stored once
                                                                    // and s[i+1] to be also stored once.
                    }
              }
        }
    cout << Ans << endl; //Print the two-gram substring
    return 0;
}
//End Of Program
