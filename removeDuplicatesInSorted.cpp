//A program to remove duplicate characters from a string and output it in sorted order.
# include <iostream>
# include <set>
# include <string>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    set <char> S;
    for(int i = 0 ; i < str.length() ; i++)
    {
        S.insert(str[i]);
    }
    for(auto it : S)
      cout << it;
}
