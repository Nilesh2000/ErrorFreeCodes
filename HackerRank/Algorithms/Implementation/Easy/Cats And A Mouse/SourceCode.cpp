#include <iostream>
using namespace std; 
int main() 
{
    int n; 
    cin >>n;
    while (n--) 
    {
        int x,y,z;
        cin >>x >>y >>z;
        if (abs(x-z) < abs(y-z)) 
         cout <<"Cat A\n";
        else if (abs(x-z)>abs(y-z)) 
         cout <<"Cat B\n";
        else
          cout <<"Mouse C\n";
     }
    return 0;
}
