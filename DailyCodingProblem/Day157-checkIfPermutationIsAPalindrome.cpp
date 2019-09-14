/*
Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to form racecar, which is a palindrome. daily should return false, since there's no
rearrangement that can form a palindrome.
*/
# include <iostream>
# include <string>
# include <bitset>
# define SIZE 26

using namespace std;

bool checkIfPermutationIsAPalindrome(string s)
{
    bitset <SIZE> bSet(0);
    int Len = s.length();
    for(int i = 0 ; i < Len ; i++)
    {
        bSet.flip(s[i] - 'a');
    }
    return (bSet.count() <= 1);
}

int main(void)
{
    string s;
    cout << "\nEnter a string : ";
    cin >> s;
    bool Res = checkIfPermutationIsAPalindrome(s);
    if(Res)
      cout << "There exists a permuatation of the string which is a palindrome.";
    else
      cout << "There is no permuatation of the string which is a palindrome.";
    cout << "\n";
    return 0;
}
