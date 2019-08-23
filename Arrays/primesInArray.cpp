//Given a list of n elements, generate all the prime numbers and the product of the prime numbers.
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

void printPrimes(int A[], int n)
{
    int Max = *max_element(A, A + n);
    vector <bool> Prime(Max + 1, true);
    Prime[0] = Prime[1] = false;
    for(int i = 2 ; i * i <= Max ; i++)
    {
        if(Prime[i])
        {
            for(int j = i * i ; j <= Max ; j += i)
            {
                Prime[j] = false;
            }
        }
    }

    int Product = 1;
    cout << "\nThe prime numbers in the array are : ";
    for(int i = 2 ; i <= Max ; i++)
    {
        if(Prime[i])
        {
            cout << i << " ";
            Product *= i;
        }
    }
    cout << "\nThe product of the prime numbers is : " << Product;
}

int main(void)
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int Size = sizeof(Arr) / sizeof(Arr[0]);
    printPrimes(Arr, Size);
    return 0;
}
