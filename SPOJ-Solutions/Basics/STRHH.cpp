//Header Files
#include <iostream>
#include <string.h>

using namespace std;

int main() //Main Function
{
  int n, k, i=0;
  cin >>n; //Input Number Of Test Cases
   while(n--)
    {
     string s;
     cin >>s; //Input The String Whose First Half Of The Alternate Characters Are To Be Displayed
     k=s.length()/2; //Divide The String Into Two Halves
      while(i<k)
       {
        cout << s[i];
	i+=2; //Increment By 2 Since You Have To Print Every Alternate Character
       }
	 cout << endl;
	 i=0;
    }
  return 0;  
}
