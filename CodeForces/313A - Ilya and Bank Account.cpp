//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    long long n;
    cin >> n;
      if(n >= 0)
        {
            cout << n << endl;
        }
      else
        {
            int firstDigit = n / 10;
            int secondDigit = (n / 100) * 10 + (n % 10);
            cout <<max(firstDigit, secondDigit);
        }
    return 0;
}
//End Of Program
