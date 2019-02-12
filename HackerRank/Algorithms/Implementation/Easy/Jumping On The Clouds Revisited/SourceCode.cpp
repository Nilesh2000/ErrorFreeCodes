# include <iostream>
using namespace std;
int main()
{
    int n, k, Energy=100;
    cin >>n >>k;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
    for(int i=0;i<n;i+=k)
        Energy-=(1+(2*Arr[i]));
    cout <<Energy;
    return 0;
}