# include <iostream>
using namespace std;
int main()
{
    int n, Num, k, Total;
    cin >>n;
     while(n--)
     {
       Total=0;
       cin >>Num >>k;
       int Arr[Num];
        for(int i=0;i<Num;i++)
          {
            cin >>Arr[i];
              if(Arr[i]<=0)
               Total++;
          }
         if(Total<k)
             cout <<"YES" <<endl;
         else
             cout <<"NO" <<endl;
     }
    return 0;
}
