//Header Files
# include <iostream>
# include <algorithm>

using namespace std;

int main(void) //Driver Function
{
  int Arr[4], Count = 0;
    for (int i = 0 ; i < 4; i++)
      {
          cin >> Arr[i];
      }
  sort (Arr, Arr+4); //Sorting is necessary because it helps in check if the adjacent elements are duplicates of each other or not
    for (int i = 0 ; i < 3 ; i++)
      {
                if (Arr[i] == Arr[i+1])
                    {
                        Count++;
                    }
      }
  cout << Count << endl;
  return 0;
}
//End Of Program
