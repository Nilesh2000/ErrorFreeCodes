//Header Files
# include <bits/stdc++.h>

using namespace std;

int main(void) //Driver Function
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int Arr[k] = {0};
    //k represents the first k characters of the alphabet.
    //First we need to find the frequencies of the first k alphabets in the string. Let the minimum frequency among these
    //frequencies be m. Then we cannot select m+1 characters of one kind, and we can definitely select m characters of
    //each kind, hence the answer is given by min(frequency of first k characters) * k
    //Overall Complexity: O(n)
      for(int i = 0 ; i < n ; i++)
        {
            Arr[s[i] - 'A']++;
        }
    int Min = Arr[0];
      for(int i = 1 ; i < k ; i++)
        {
            Min = min(Min, Arr[i]);
        }
    cout << Min * k << endl; //Multiplying by k becuase the length of the longest subsequence should denote the sum of the
                            //frequency of each of the characters.
    return 0;
}
//End Of Program
//https://codeforces.com/problemset/problem/1038/A
