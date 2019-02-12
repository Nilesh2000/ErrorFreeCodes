# include <iostream>
# include <algorithm>
using namespace std;
int main()
{
  int a, b, c;
  cin >>a >>b >>c;
  int Arr[5];
  Arr[0]=(a+b)*c;
  Arr[1]=a+(b*c);
  Arr[2]=a*(b+c);
  Arr[3]=(a*b)+c;
  Arr[4]=a+b+c;
  Arr[5]=a*b*c;
  sort(Arr, Arr+6);
  cout <<Arr[5] <<endl;
  return 0;
}
