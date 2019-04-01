//Header Files
# include <bits/stdc++.h>

# define pb push_back

using namespace std;

int main(void) //Driver Function
{
  ios_base::sync_with_stdio(false);
  int n, Num;
  cin >> n;
  int Sum = 0;
  vector <int> Odd, Even;
    while(n--)
      {
          cin >> Num;
          Sum += Num;
            if(Num & 1) //Check if the number is odd using a bitwise operator
              {
                  Odd.pb(Num);
              }
            else
              {
                  Even.pb(Num);
              }
      }
  //Sort both the Odd And Even vectors in descending order
  sort(Odd.begin(), Odd.end(), greater <int>());
  sort(Even.begin(), Even.end(), greater <int>());

  int k = min(Even.size(), Odd.size()); //Determine which one of the vector has lesser elements

  int Rem = Sum; //Set a temporary variable equal to all the elements of the vector.

  //We basically decrement the the maximum possible sum of the vector by subtracting it from k of the largest elements from each of the vectors.
  Rem -= accumulate(Odd.begin(), Odd.begin() + k, 0);
  Rem -= accumulate(Even.begin(), Even.begin() + k, 0);

//Now, an equal number of elements have been deleted from both the vectors. We still have one more computation opportunity pending.

//For the last operation, check which vector has more number of elements than k and delete the Odd[k] or Even[k] element of the vector.
//We delete only the kth element because all elements succeeding the kth element have already been deleted.
//Delete the element basically means decrement it drom Rem.

    if(Odd.size() > k)
      {
          Rem -= Odd[k];
      }
    if(Even.size() > k)
      {
          Rem -= Even[k];
      }
  cout << Rem << endl;
}
//End Of Program
//Source
//https://codeforces.com/blog/entry/66307
