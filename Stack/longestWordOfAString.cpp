//A program to find the longest word present in a sentence
# include <iostream>
# include <stack>

using namespace std;

void longestWord(string str)
{
    stack <char> S;
    char longestWord[100];
    int Len = str.length(), maxLen = 0; //Set maxLen initially to 0 and store the length of the string in Len.
    for(int i = 0 ; i < Len ; i++) //Traverse each character of the string.
    {
        if(str[i] != ' ') //If the character is not a string, push into the stack.
        {
            S.push(str[i]);
        }
        else
        {
            if(S.size() > maxLen) //Check if the length of the pushed word into the stack is greater than the maxLen
            {
                maxLen = S.size(); //Set maxLen to the length of the word in the stack.
                int j = maxLen - 1;
                //Store the elements of the stack in a new string.
                while(!S.empty())
                {
                    longestWord[j] = S.top();
                    S.pop();
                    j--;
                }
                longestWord[maxLen] = '\0'; //Set the last character of longestWordm to '\0'.
            }
            else //If the length of the word in the stack is shorter than maxLen, empty the stack and Traverse the next word.
            {
                while(!S.empty())
                  S.pop();
            }
        }
    }
    cout << "\nThe longest word of the sentence is : " << longestWord << " and it's length is : " << maxLen;
}

//Driver function
int main(void)
{
    string Str = "Sri Venkateswara College Of Engineering";
    longestWord(Str);
    return 0;
}
//End of program
