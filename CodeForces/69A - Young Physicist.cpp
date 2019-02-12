# include <iostream>
using namespace std;
int main()
{
  int xSum=0, ySum=0, zSum=0, n, x, y, z;
  cin >>n;
   while(n--)
   {
     cin >>x >>y >>z;
     xSum+=x;
     ySum+=y;
     zSum+=z;
   }
   if(xSum==0 && ySum==0 &&zSum==0)
    cout <<"YES" <<endl;
   else
    cout <<"NO" <<endl;
  return 0;
}
//Sum of all the three vector components must be zero.
