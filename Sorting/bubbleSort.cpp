//The bubble sort algorithm
//Time Complexity : O(n ^ 2)
# include <iostream>
using namespace std;

void bubbleSort(int Arr[], int n)
{
  int Temp;
  for(int i = 0 ; i < n - 1 ; i++)
  {
      for(int j = 0 ; j < n - i - 1; j++)
      {
          if(Arr[j] > Arr[j + 1])
          {
              Temp = Arr[j];
              Arr[j] = Arr[j + 1];
              Arr[j + 1] = Temp;
          }
      }
  }
}

int main(void)
{
    int Arr[] = {-3, 2, 1, 0, 5, -9, 6};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << "\nInitial Array : ";
    for(int i = 0 ; i < n ; i++)
      cout << Arr[i] << " ";
    bubbleSort(Arr, n);
    cout << "\nSorted Array : ";
    for(int i = 0 ; i < n ; i++)
        cout << Arr[i] << " ";
    return 0;
}
//End of program
