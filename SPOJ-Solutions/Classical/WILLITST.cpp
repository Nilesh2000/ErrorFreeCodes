//Header Files
# include <iostream>

using namespace std;

int main() //Main Function
{
    long long n;
    cin >>n; //Input The Number
     while(n%2==0) //Loop To Check If The Input Is A Power Of 2
      n/=2;
    if(n==1) 
      cout<<"TAK"; //Print TAK If The Entered Number Is A Power Of 2
    else
     cout<<"NIE";
    return 0;
}
//Source
//https://www.quora.com/How-does-one-deduce-the-solution-for-WILLITST-problem-on-SPOJ-com
