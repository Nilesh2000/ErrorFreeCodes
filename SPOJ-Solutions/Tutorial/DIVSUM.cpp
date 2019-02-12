//Header Files
# include <iostream>
#include<math.h>

using namespace std;

int main()
{
    int t;
    cin >>t; //Input Number Of Test Cases
    while(t--)
    {
        int num;
        long long ans=0;
        cin >>num; //Input Number Whose Divisor Summation Is To Be Calculated
        if(num==1) //If Condition To Print 0 If Entered Number Is 1
            cout <<"0" <<endl;
        else
        {
            int i, t=sqrt(num);
            for(i=2;i<=t;i++)
            {
                /*
                The core logic for solving this question is that divisors always exist in pairs. So, for a number ‘t’, if ‘i’ is a 
                divisor then ‘t/i’ is also a divisor.
                And the smaller number of any divisor pair is always less than or equal to the square root of the number.
                */
                if(num%i==0)
                {
                    if(i==num/i)
                        ans+=i;
                    else
                        ans+=i+num/i;
                }
            }
            ans++; //Increment Answer To Also Add 1 to Its List Of Divisors
            cout <<ans <<endl;
        }
    }
    return 0;
}
//Source
//https://codegeeksblog.wordpress.com/2013/06/01/spoj-divsum-divisor-summation/
