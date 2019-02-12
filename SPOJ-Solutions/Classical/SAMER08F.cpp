//Header Files
# include <iostream>

using namespace std;

int main() //Main Function
{
    int n;
    long long Squares;
     while(1)
     {
         cin >>n; //Input Length Side Of Square
          if(n==0)
            break;
         Squares=(n*(n+1)*(2*n+1))/6; //Compute Total Number Of Squares In The Grid
         cout <<Squares <<endl; //Display Output
     }
     return 0;
}
