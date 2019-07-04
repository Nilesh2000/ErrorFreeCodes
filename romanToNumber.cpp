//A program to convert a roman numeral to a number
# include <iostream>
# include <map>

using namespace std;

int romanToNumber(string s)
{
    //Map to declare a key and value for roman numerals
    map <char, int> M = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int Num = 0, Len = s.length();
    //Loop to iterate through each character of the string.
    for(int i = 0 ; i < Len ; i++)
    {
        if(M[s[i + 1]] <= M[s[i]]) //If the (i+1)th charcter is greater than the ith character, add the corresponding value to Num.
          Num += M[s[i]];
        else //Else, just subtract
          Num -= M[s[i]];
    }
    return Num; //Return the value of Num to main()
}

//Driver function
int main(void)
{
    string s;
    cout << "Enter the number in roman numerals : ";
    cin >> s;
    cout << "The number is : " << romanToNumber(s) << endl;
    return 0;
}
