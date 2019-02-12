# include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    long int Arr[n], Sum=0;
    for(int i=0;i<n;i++)
    {
    cin >>Arr[i];
    Sum+=Arr[i];
    }
    cout <<Sum;
}
