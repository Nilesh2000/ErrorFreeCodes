//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void) //Driver Function
{
    int i, Len, k, Arr[26] = {0};
    string s, kString;
    cin >> k >> s;
      for(i = 0 ; i < s.length() ; i++)
        {
          Arr[s[i] - 'a']++; //Fill the array with the number of occurrences of each alphavet of the string
        }
       for(i = 0 ; i < 26 ; i++)
        {
            if(Arr[i] % k !=0) //Checking if each character has enough number of occurrences to form a kString
                               //Necessary to check if remainder is 0 becuase you need to create k number of copies
                               //of the substring in the kString.
              {
                  break;
              }
            else //string& string::append (size_type num, char c)
              {
                  kString.append(Arr[i] / k, 'a' + i); //Appending a charcter ('a' + i) , Arr[i] / k times to one copy
                                                       //of the kString
              }
        }
       if(i == 26) //Checking if the preceeding loop is terminated with i==26
        {
              while(k--)
                {
                    cout <<kString; //Printing the kString string k number of times
                }
            cout <<endl;
        }
       else //False Condition
          {
              cout << -1 << endl;
          }
    return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/5160
