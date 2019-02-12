# include <iostream>
using namespace std;
int main()
{
    long long n, b, w, bc, wc, z, Min_Cost;
    cin >>n;
     while(n--)
     {
      cin >>b >>w >>bc >>wc >>z;
      Min_Cost=(b*min(bc,wc+z))+(w*min(wc,bc+z));
      cout <<Min_Cost <<endl;   
     }
    return 0; 
}
