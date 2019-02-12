# include <iostream>
# include <math.h>
using namespace std;
int main()
{
    int n, Start, End;
    cin >>n;
     while(n--)
     {
         cin >>Start >>End;
         cout <<floor(sqrt(End))-ceil(sqrt(Start))+1 <<endl;
     }
    return 0;
}