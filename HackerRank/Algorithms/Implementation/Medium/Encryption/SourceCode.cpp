# include <iostream>
# include <string>
# include <cmath>
using namespace std;
int main()
{
    string s;
    cin >>s;
    int Len=s.length();
    int Rows=floor(sqrt(Len)), Cols=ceil(sqrt(Len));
     for(int i=0;i<Cols;i++)
      {
        for(int j=i;j<Len;j+=Cols)
        {
            cout <<s[j];
        }
        cout <<" ";
    }
    return 0;
}
