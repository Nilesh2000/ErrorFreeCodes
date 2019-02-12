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
         int Count=0;
          for(int i=1;;i++)
          {
              if(i*i>End)
                  break;
              else if(i*i>=Start && i*i<=End)
                  Count++;
          }
         cout <<Count <<endl;
     }
    return 0;
}