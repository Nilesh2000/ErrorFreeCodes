# include <iostream>
using namespace std;
int main()
{
    int n;
    long Sum=0;
    cin >>n;
    int Arr[n];
     for(int i=0;i<n;i++)
     {
         cin >>Arr[i];
         Sum+=Arr[i];
     }
    cout <<Sum;
    return 0;
}
