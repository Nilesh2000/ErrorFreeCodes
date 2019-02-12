# include <iostream>
# include <cstring>
using namespace std;
int main(void)
{
  int n, r = 1;
  string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  cin >> n;
    while(r * 5 < n)
      {
        n -= (r * 5); //Decrementing n by r*5 since number of people in the queue are 5
        r *= 2; //Multilying n by 2 since a person doubles after drinking a glass of cola
      }
  cout << names[(n - 1) / r] << endl; //Subtracting 1 in the string index because an array is 0-indexed.
  return 0;
}
//https://github.com/fuwutu/CodeForces/blob/master/82A%20-%20Double%20Cola.cpp
