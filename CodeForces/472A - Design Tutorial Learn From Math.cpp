/Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
  int n;
  cin >>n;
    if (n % 2)
      {
          cout << "9 "  << (n - 9) <<endl;
      }
    else
      {
          cout << "8 " << (n - 8) <<endl;
      }
  return 0;
}
//End Of Program
