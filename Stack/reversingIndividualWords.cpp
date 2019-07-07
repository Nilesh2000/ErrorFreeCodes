//A program to reverse the individual words of a string using a stack.
# include <iostream>
# include <stack>

using namespace std;

void reverseIndividualWords(string str)
{
    int Len = str.length(); //Variable to store string length
    stack <char> S;
    for(int i = 0 ; i < Len ; i++) //Iterate through each character of the string
    {
        if(str[i] != ' ') //If the character is not a space, push it into the stack.
        {
            S.push(str[i]);
        }
        else //When you encounter a space, print all elements of the stack.
        {
            while(!S.empty())
            {
                cout << S.top();
                S.pop();
            }
        cout << " ";
        }
    }
    while(!S.empty()) //This loop is used to print the last word because the last word may not have any space after it.
    {
        cout << S.top();
        S.pop();
    }
}

//Driver function
int main(void)
{
    string Str = "Geeks For Geeks";
    reverseIndividualWords(Str);
    return 0;
}
