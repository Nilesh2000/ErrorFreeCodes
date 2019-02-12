# include <iostream>
using namespace std;
int main()
{
  long long n;
  cin >>n;
   if(n%2==0)
    cout <<n/2 <<endl;
  else
    cout <<n/2-n; //Basically half of -(n+1)
  return 0;
}

/*
You can pair every two consecutive numbers because their sum is always 1. The number of this pairs is exactly n / 2
(integer division). If n is odd, the last number doesn't have pair. Because the sequence starts with negative value,
this number will be negative as well. So last number of sequence is n and in case n is odd (n doesn't have pair),
you must subtract it from n / 2.
*/
