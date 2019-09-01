/*
Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to form racecar, which is a palindrome. daily should return false, since there's no
rearrangement that can form a palindrome.
*/
# include <iostream>
# include <string>
# define noOfChars 256

using namespace std;

bool checkIfPermutationIsAPalindrome(string s)
{
    int Count[noOfChars] = {0};
    int Len = s.length();

    for(int i = 0 ; i < Len ; i++)
    {
        Count[s[i]]++; //Storing the coutn of occurence of each charcter of the string in a Count Array.
    }

    int oddOccurence = 0; //Keep track of the number of characters which occur an odd number of times in the string

    for(int i = 0 ; i < noOfChars ; i++) //Traverse the whole Count Array.
    {
        if(Count[i] % 2) //If Count[i] is Odd
        {
            oddOccurence++;
        }
        if(oddOccurence > 1)
        {
            return false; //If odd count exceeds 1, then the string cannot have a permutation which is a palindrome.
        }
    }
    return true; //Return true if the odd count is 0 or 1.
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
