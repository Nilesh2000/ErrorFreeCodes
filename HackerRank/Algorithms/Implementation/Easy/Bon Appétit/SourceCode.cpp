# include <iostream>
using namespace std;
int main()
{
    int n, k, b, Sum=0;
    cin >>n >>k;
    int Bill[n];
     for(int i=0;i<n;i++)
     {
         cin >>Bill[i];
         Sum+=Bill[i];
     }    
     cin >>b;
     int Fake_Amount=Sum/2;
     int Real_Amount=(Sum-Bill[k])/2;
     if(b==Real_Amount)
         cout <<"Bon Appetit";
    else if(b>Real_Amount)
        cout <<b-Real_Amount;
    return 0;
}
