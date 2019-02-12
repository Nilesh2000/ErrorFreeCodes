//Header Files
# include <bits/stdc++.h>

using namespace std;

int main(void) //Driver Function
{
    int n, l, r, k;
    string s;
    cin >> s >> n;
      while(n--)
        {
            cin >> l >> r >> k;
            int Len = r - l + 1; //Adding 1 because we are considering a zero-indexed string with Len characters in the
                                  //substring. Len is the length of the substring
            l--; r--; //Decrementing both l and r because inputed it 1-indexed but the string is 0-indexed.
            k %= Len; //Because If The substring is cyclically rotated Len times we will get back the original substring.
            /*
            string substr (size_t pos, size_t len) const;
            Parameters:
            pos: Position of the first character to be copied.
            len: Length of the sub-string.
            size_t: It is an unsigned integral type.
            Return value: It returns a string object.
            */
            string t = s.substr(l, Len); //Creating a substring to store Len number of characters starting from l.
              for(long i = 0 ; i < Len ; i++)
                {
                    s[l + i] = t[(Len - k + i) % Len];
                    //LHS expression l+i increases by one everytime till i < Len. Starting with l+i because the substring
                    //starts from l.
                    //RHS expression starts from the end of string t because the string needs to be rotated in a cyclic
                    //order. Subtracting by k because the string needs to be rotated cyclically k times.
                    //Adding i because if the character is the last, it needs to be brought out in the front.
                    //The remainder term % Len is required if the numerator execeeds the denominator.
                }
        }
    cout << s << endl;
    return 0;
}
//End Of Program
//https://github.com/DionysiosB/CodeForces/blob/master/598B-QueriesOnAString.cpp
