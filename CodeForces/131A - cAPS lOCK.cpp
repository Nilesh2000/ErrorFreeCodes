#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool change = true;
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] >= 'a')
        {
            change = false;
            break;
        }
    }
    if (change)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] >= 'a')
            {
                s[i] = toupper(s[i]);
            }
            else
            {
                s[i] = tolower(s[i]);
            }
        }
    }
    cout << s << endl;
    return 0;
}
