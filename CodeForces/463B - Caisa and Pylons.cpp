//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    int a, n, Energy = 0, Res = 0, Pylon = 0;
    //Start with Pylon = 0 since height of the 0th tower is 0.
    //Res here is the variable that stores the minimal height of the first tower.
    cin >> n; //Number of towers
      while(n--)
        {
            cin >> a; //Height of each tower
            Energy += (Pylon - a); //Energy require to jump from n th to (n+1)st tower
              if(Energy < 0) //Check if energy required is negative
                {
                    Res += -Energy; //Increment Res by energy required
                    Energy = 0; //Initialization because Res now has enough energy and has to start once again from 0.
                }
            Pylon = a; //Initialization for computation of difference of successive elements
        }
    cout << Res << endl;
    return 0;
}
//End Of Program
//Greedy approach was used to solve this problem.
//Objective of this problem is to make sure the energy remains non-negative.
