//Header Files
# include <iostream>
# include <algorithm>

using namespace std;

int main(void) //Driver Function
{
  int n, l, r;
  cin >>n >>l;
  int Arr[n];
    for (int i = 0 ; i < n ; i++)
      {
          cin >> Arr[i];
      }
  sort(Arr, Arr + n); //Sorting the input array so that maximum radius can be computed

  //Succeeding statement is necessary becuase there is no area before Arr[0] and there is no area beyond l.
  //Thus, we first need to determine the maximum area to be lit on both sides of the road at the start and end
  //of the road.

  r = max(Arr[0], l - Arr[n-1]) * 2; //Initialize radius to maximum between the 1st element of array and difference
                                    //of the distance of the last lamp and the length of the road, multiplied by 2
                                    //Multiplying by 2 includes both sides of the lantern (forward and backward)

    for (int i = 0; i < n - 1 ; i++) //Go only upto n - 1 because loop body contains an i + 1 term
      {
          r = max (r, Arr[i + 1] - Arr[i]); //Arr[i+1]-Arr[i] is the maximum distance b/w two lanterns

          //Initializing r to maximum of previously computed radius and difference two adjacent elements.
      }
  cout.precision(20);
  cout << fixed << r / 2.0 << endl;
                                    //r / 2.0 tells that how many areas one lantern can glow at a maximum.
  return 0;
}
//End Of Program
//https://discuss.codechef.com/questions/103888/codeforces-b-vanya-and-lanterns
