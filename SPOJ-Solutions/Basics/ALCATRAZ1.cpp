//Header Files
# include <iostream>
# include <string>

using namespace std;

int main()
{
    string s;
    int n;
    cin >>n; //Input Number Of Test Cases
    while(n--)
    {
        int Sum=0;
        cin >>s; //Input String Whose Sum Of Digits Is To Be Calculated
        int Len=s.length();
         for(int i=0;i<Len;i++)
            Sum+=(s[i])-48; //Increment Sum After Subtracting Charcter With 48 As ASCII Code Of '0' is 48.
        cout <<Sum <<endl; //Printing Output
    }
    return 0;
}
