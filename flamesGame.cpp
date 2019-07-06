//A program to implement the FLAMES game.
/*
Given the names of two people, cancel out the common letters (repeated occurrence of a letter is treated separately, so 2A's in one name and one A in the
other would cancel one A in each name), count the total number of remaining letters (n) and repeatedly cut the letter in the word FLAMES which hits at the
nth number when we count from F in cyclic manner.
*/
# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

void flamesGame(string Str1, string Str2)
{
    //Create two integer arrays to store the frequency of each letter.
    int n1[26] = {0}, n2[26] = {0};
    int Len1 = Str1.length(), Len2 = Str2.length();

    //Store the frequency of each letter from Str1.
    for(int i = 0 ; i < Len1 ; i++)
    {
        if(Str1[i] != ' ') //Ignoring the spaces present in the name, if any.
        {
            n1[Str1[i] - 'a']++;
        }
    }

    //Store the frequency of each letter from Str2.
    for(int i = 0 ; i < Len2 ; i++)
    {
        if(Str2[i] != ' ')
        {
            n2[Str2[i] - 'a']++;
        }
    }

    int Ans = 0; //A variable used to calculate the total number of uncommon letters from each word.
    for(int i = 0 ; i < 26 ; i++)
    {
        if(n1[i] != 0 || n2[i] != 0)
        {
            Ans += abs(n1[i] - n2[i]);
        }
    }

    //Create an integer array to store the frequency of each letter of the word FLAMES.
    int f[6] = {1, 1, 1, 1, 1, 1};
    int c = 1, j = 0;
    //The word FLAMES has 6 letters and we have to stop when there is only one letter remaining. Thus, we conduct iterations from 1 to 5 for variable c.
    while(c <= 5)
    {
        int Temp = 0; 
        while(1)
        {
            if(f[j])
                Temp++;
            if(Temp == Ans)
              break;
            j = (j + 1) % 6;
        }
        f[j] = 0;
        j = (j + 1) % 6;
        c++;
    }

    int Last;
    for(int i = 0 ; i < 6 ; i++)
    {
        if(f[i] == 1)
          Last = i;
    }
    switch(Last)
    {
        case 0 : cout << "FRIENDS";
                  break;

        case 1 : cout << "LOVE";
                  break;

        case 2 : cout << "ADORE";
                  break;

        case 3 : cout << "MARRAIGE";
                  break;

        case 4 : cout << "ENEMIES";
                  break;

        case 5 : cout << "SIBLINGS";
                  break;
    }
}

//Driver function
int main(void)
{
    string s1, s2;
    cout << "\nEnter the first name : ";
    cin >> s1;
    cout << "Enter the partner's name : ";
    cin >> s2;
    //transform() her is used to convert the case of a string to lowercase.
    //Syntax : transfor(inputBegin, inputEnd, outputBegin, function)
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    flamesGame(s1, s2);
    return 0;
}
