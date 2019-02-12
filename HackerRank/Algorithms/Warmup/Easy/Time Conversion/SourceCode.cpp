# include <iostream>
# include <string>
using namespace std;
void Print_Time(string Str)
{
    int h1 = (int)Str[1] - '0';
    int h2 = (int)Str[0] - '0';
    int hh = (h2 * 10 + h1 % 10);
    if (Str[8] == 'A')
    {
        if (hh == 12)
        {
            cout << "00";
            for (int i=2; i <= 7; i++)
                cout << Str[i];
        }
        else
        {
            for (int i=0; i <= 7; i++)
                cout << Str[i];
        }
    }
    else
    {
        if (hh == 12)
        {
            cout << "12";
            for (int i=2; i <= 7; i++)
                cout << Str[i];
        }
        else
        {
            hh+=12;
            cout << hh;
            for (int i=2; i <= 7; i++)
                cout << Str[i];
        }
    }
}

int main()
{
   string Str;
   cin >>Str;
   Print_Time(Str);
   return 0;
}
