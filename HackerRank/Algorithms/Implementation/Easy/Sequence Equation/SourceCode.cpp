# include <iostream>
using namespace std;
int main()
{
    int n, Num;
    cin >>n;
    int Arr[n+1];
     for(int i=1;i<=n;i++)
     {
         cin >>Num;
         Arr[Num]=i;
     }   
    for(int i=1;i<=n;i++)
        cout <<Arr[Arr[i]] <<endl;
    return 0;
}
