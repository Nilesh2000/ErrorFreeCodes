//Header Files 
#include<iostream>

using namespace std;

int main() //Main Function
{
 long long t, a, c, n, first, d, i, b;
 cin >>t; //Input Number Of Test Cases
  while(t!=0)
   {
    cin >>a >>b >>c; //Input 3rd Term, 3rd Term From The Last And The Sum Of The AP
    n=c*2/(a+b); //n=Number Of Terms
    cout <<n <<endl;
    d=(b-a)/(n-5); //d=Common Difference Of The AP
    first=a-(2*d); //first=First Term Of The Term
     for(i=0;i<n;i++)
      {
       cout <<first+(i*d) <<" "; //Displaying All Terms Of The AP/
      }
    t--;
   }
 return 0;
}
//Source
//http://code.cloudkaksha.org/spoj/spoj-ap2-solution
