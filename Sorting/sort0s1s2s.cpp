//A program to sort an array consisting of only 0s, 1s and 2s in ascending order.
//Time Complexity : O(n)
//Space Complexity : O(1)
# include <iostream>

using namespace std;

int swap(int &a, int &b)
{
    int Temp;
    Temp = a;
    a = b;
    b = Temp;
}

/*
The problem was posed with three colours, here `0′, `1′ and `2′. The array is divided into four sections:

a[1..Lo-1] zeroes (red)
a[Lo..Mid-1] ones (white)
a[Mid..Hi] unknown
a[Hi+1..N] twos (blue)
The unknown region is shrunk while maintaining these conditions

Next, traverse the array till  Mid <= High
*/

void sort0s1s2s(int Arr[], int n)
{
    int Low = 0;
    int High = n - 1;
    int Mid = 0;
      while(Mid <= High)
        {
            switch(Arr[Mid])
              {
                  case 0 :
                           swap(Arr[Low++], Arr[Mid++]);
                            break;
                  case 1 :
                           Mid++;
                            break;
                  case 2 :
                           swap(Arr[Mid], Arr[High--]);
                            break;
              }
        }
    cout << "\nSorted Array : ";
    for(int i = 0 ; i < n ; i++)
      cout << Arr[i] << " ";
}

int main(void)
{
    int Arr[] = {0, 0, 2, 1, 2, 1, 2, 1, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    sort0s1s2s(Arr, n);
    cout << endl;
    return 0;
}
