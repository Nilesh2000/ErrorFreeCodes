# include <iostream>
using namespace std;
int main()
{
  int a, n;
  cin >>n >>a;
  int maxA=a, minA=a, maxI=0, minI=0;
   for(int i=1;i<n;i++)
    {
     cin >>a;
      if(a>maxA) //Finding biggest array element
       {
         maxA=a;
         maxI=i;
       }
      if(a<=minA) //Finding smallest array element
       {
         minA=a;
         minI=i;
       }
    }
  cout <<maxI+(n-1-minI) - (minI<maxI?1:0) <<endl;
  //minI and maxI are zero-indexed, thus 1 is subtracted in the formula.
  //(n-1-minI) denotes the number of swaps required to take the smallest number from any position to a[0]
  //1 is subtracted because computers start counting from 0 and size of an array(n) is not zero-indexed.
  //Adding maxI denotes number of swaps required to take the largest number from any position to a[sizeof(a)]
  //Condition checks if 1 is subtracted or not when minI<maxI.
  return 0;
}
