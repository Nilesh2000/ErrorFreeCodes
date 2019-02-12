//Header Files
# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
# include <cstring>
# include <set>
# include <cmath>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  int s1, s2, s3, Perimeter;
  cin >> s1 >> s2 >> s3;
  int a = sqrt(s1 * s3 / s2);
  int b = sqrt(s1 * s2 / s3);
  int c = sqrt(s2 * s3 / s1);
  Perimeter = 4 * (a + b + c);
  cout << Perimeter << endl;
  return 0;
}
//End Of Program
/*
Let s1, s2, s3 be the areas of the three sides. Let a, b, c be their lengths.
s1=a*b, s2=b*c, s3=a*c
s1*s2*s3 = a^2*b^2*c^2
root(s1*s2*s3) = a*b*c
root(s1*s2*s3) = a*s2
root(s1*s3/s2) = a
Similarly, arrive at an expression for all the lengths.
*/
