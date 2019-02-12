# include <iostream>
using namespace std;
int main()
{
    int Search, n;
    cin >>Search >>n;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
     for(int i=0;i<n;i++)
     {
         if(Arr[i]==Search)
             cout <<i;
     }
    return 0;
}
