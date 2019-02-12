//Header Files
# include <iostream>
# include <stdlib.h>
# include <math.h>

using namespace std;

int isPrime(int n) //Function To Check If Passed Number Is Prime Or Not
{
    int Flag=0;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0) //If Condition To Check If n Is Divisible By i 
        {
            Flag=1;
            return 0;
        }
    }
    if(Flag==0) //If Condition To Return 1 If The Passed Number Is Prime
        return 1;
}
int nextPrime(int k) //Function To Compute Next Prime Number
{
    ++k;
    if(k==2)
        return k;
    if(k%2==0) //If Condition To Check Whether The Incremented Number Is Divisble By 2
     ++k;
    while(!isPrime(k))
        k+=2; //Increment k by 2 if isPrime(int) returns 0
    return k;
}
void printSeq(int n) //Function To Print The Required Sequence
{
    int a, b, c=1;
    while(n--)
     {
        a = nextPrime(c);
        b = nextPrime(a);
        c = nextPrime(b);
        cout<<a*b+c <<" "; //Display Required Output
    }
}
int main() //Main Function
{
    int t, n;
    cin>>t; //Input Number Of Test Cases
    while(t--)
    {
       cin >>n; //Input The Term Until Which You Want To Print The Series
       printSeq(n); 
       cout<<'\n';
    }
    return 0;
}
//Source
//https://github.com/GokulNC/Programming_Practice/blob/master/SPOJ/Solutions-in-C-for-SPOJ-Basics/SERI07%20(Strange%20But%20Easy).cpp
