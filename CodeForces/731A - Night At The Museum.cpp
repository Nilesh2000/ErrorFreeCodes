//Header Files
# include <iostream>
# include <cstring>

using namespace std;

const int numOfAlphabets = 26;

int main(void) //Driver Function
{
    string s;
    int Count = 0;
    cin >> s;
    char Ch = 'a'; //Initialization to starting counter
      for(int i = 0 ; i < s.length() ; i++)
        {
            //Compute min of differences on both sides of the circles
            Count += min( abs( s[i] - Ch ) , numOfAlphabets - abs( s[i] - Ch ) );
            Ch = s[i]; //Initialze Ch to the present character for the the next computation.
        }
    cout << Count << endl;
    return 0;
}
//End Of Program
