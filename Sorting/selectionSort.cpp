# include <iostream>

using namespace std;

int main(void)
{
    int Arr[] = {6, 21, 43, 22, -2, 89, 17}, n = sizeof(Arr) / sizeof(Arr[0]);
    int iMin, Temp;
    //We have to go only till n-1 because the array will already be sorted by then, since all the smaller elements must
    //have occupied the first n-2 places. Thus, there is no need to to perform a sort for the last remaining element.
      for(int i = 0 ; i < n - 1 ; i++)
        {
            iMin = i; //Elements from i to n-1 are candidates for sorting.
              for(int j = i + 1 ; j < n ; j++)
                {
                    if(Arr[j] < Arr[iMin]) //If you found a smaller element, update the index of the minimum element.
                      {
                          iMin = j;
                      }
                   Temp = Arr[i];
                   Arr[i] = Arr[iMin];
                   Arr[iMin] = Temp;
                }
        }
      for(int i = 0 ; i < n ; i++)
        {
            cout << Arr[i] << " ";
        }
    return 0;
}
