//Header Files
#include <iostream>

using namespace std;

int main() //Main Function
{
  int t,i;
  long long k;
  cin >>t; //Input Number Of Test Cases
  while(t--)
  {
    cin >>k >>i; //Input Number Of Pieces In The Wooden Bottle
    
    if(i==0) //If Condition To Display The Winner Of The Game (Person Who Starts The Game Always Wins The Game.)
      cout<<"Airborne wins."<<endl;
    else
      cout<<"Pagfloyd wins."<<endl;
  }
  return 0;
}
