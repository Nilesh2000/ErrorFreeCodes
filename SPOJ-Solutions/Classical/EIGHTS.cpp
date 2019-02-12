//Header Files
#include <iostream>

using namespace std;

int main() //Main Function
{
    long long n, Num;
    cin >>n; //Input Number Of Test Cases
    while(n--)
    {
        cin >>Num; //Input nth Number To Be Found Out Whose Cube Ends With 888
        cout <<192+(Num-1)*250 <<endl;
    }
    return 0;
}
//Source
//http://codingsiksha.blogspot.com/2015/04/eights-triple-fat-ladies-spoj-solution.html
