//Header Files
# include <iostream>
# include <cmath>
# define LIMIT 1000000 //10 Lakhs

using namespace std;

long long Prime[LIMIT] = {0};

void sieveOfEratosthenes() //Implementation of the algorithm
{
    Prime [0] = Prime [1] = 1;
      for(int i = 2 ; i <= sqrt(LIMIT) ; i++)
        {
            if(Prime[i] == 0)
              {
                for(int j = 2 ; i * j <= LIMIT ; j++)
                  {
                      Prime[i * j] = 1;
                  }
              }
        }
}

int checkPerfectSquare(long long n)
{
    double sqrRoot = sqrt(n);
      if(sqrRoot == int(sqrt(n)))
        return 1;
    return 0;
}

int main(void) //Driver Function
{
  sieveOfEratosthenes();
  long long a;
  int n;
  cin >>n; //Input Number of test cases
    while (n--)
      {
          cin >> a;
            if(checkPerfectSquare(a) == 1 && Prime[int(sqrt(a))] == 0)
              cout << "YES" << endl;
            else
              cout << "NO" << endl;
      }
  return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/5437
