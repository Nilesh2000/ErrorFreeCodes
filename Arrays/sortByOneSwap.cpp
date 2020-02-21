#include<iostream>
using namespace std;
void sortByOneSwap(int Arr[], int n)
{
    for(int i=n-1;i>=1;i--)
    {
        if(Arr[i] < Arr[i-1])
        {
            int j=i-1;
            while(j>=0 && Arr[i]>Arr[j])
            {
                j--;
            }
            swap(Arr[i],Arr[j]);
            break;
        }
    }
}

int main(void)
{
    int n;
    cout << "\nEnter the number of elements in the array : ";
    cin >> n;
    int Arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++)
        cin >> Arr[i];
    sortByOneSwap(Arr, n);
    cout << "Sorted Array : ";
    for(int i=0;i<n;i++)
        cout << Arr[i] << " ";
    return 0;
}
