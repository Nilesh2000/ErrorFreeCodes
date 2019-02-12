# include <iostream>
using namespace std;
int main()
{
    int n, Jumps=0;
    cin >>n;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
    for(int i=1;i<n;Jumps++)
    {
        if(Arr[i+1]!=1 && i<n-1)
            i+=2;
        else
           i++;
    }
    cout <<Jumps;
    return 0;
}
