# include <iostream>
using namespace std;
int main()
{
    int n, k, q, Query;;
    cin >>n >>k >>q;
    int Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
    k%=n;
   while(q--)
   {
       cin >>Query;
       Query-=k;
        if(Query<0)
            Query+=n;
       cout <<Arr[Query] <<endl;
   }
    return 0;
}
