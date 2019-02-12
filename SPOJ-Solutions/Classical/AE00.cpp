//Header Files
# include <iostream>
# include <math.h>

using namespace std;

int main() //Main Function
{
    int n, Count=0;
    cin >>n; //Input Number Of Squares
     for(int i=1;i<=sqrt(n);i++)
        for(int j=i+1;i*j<=n;j++)
            Count++; //Increment Number Of Rectangles
    Count+=sqrt(n); //Add Count To The Number Of Possible Squares Which is sqrt(n)
    cout <<Count;
    return 0;
}
//Source:
//http://jiteshsunhala.blogspot.com/2013/08/spoj-problem-4300-ae00.html
