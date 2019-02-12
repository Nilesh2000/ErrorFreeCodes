# include <iostream>
using namespace std;
int main()
{
  long long n, k;
  cin >>n >>k;
   if(k<=(n+1)/2) //Adding 1 in the numerator to perform check on odd numbers (Division in C++)
    cout <<k*2-1 <<endl; //Multiplying By 2 Since Array Increments By 2 At Every Position,
                         //Subtracting By 1 Since Result Will Be A Odd Number Always

   else
    cout <<(k-(n+1)/2)*2 <<endl; //Adding One In The Numerator To Perform Check On Odd numbers
                                 //Subtracting From k so that the number obtained in <=n/2
                                 //Multiplying By 2 Because Result Will Always Be An Even Number
  return 0;
}
