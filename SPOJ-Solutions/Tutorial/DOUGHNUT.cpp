//Header Files
# include <iostream>

using namespace std;

int main() //Main Function
{
    int n, c, k, w;
    cin >>n; //Input Number Of Test Cases
     while(n--)
     {
         cin >>c >>k >>w; //Input Number Of Cats, Harry's Hoisting Capacity, Weight Of Each Doughnut 
         
          if(c*w>k) //If Condition To Check Whether Harry Is Capable Of Handling The Task
            cout <<"no" <<endl;
          else
            cout <<"yes" <<endl;
     }
     return 0;
}
