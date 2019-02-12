# include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
     while(n--)
     {
         int Size, Flag, Arr_Sum, Left_Sum;
         Flag=Arr_Sum=Left_Sum=0;
         cin >>Size;
         int Arr[Size];
          for(int i=0;i<Size;i++)
          {
              cin >>Arr[i]; 
              Arr_Sum+=Arr[i];
          }
         for(int i=0;i<Size;i++)
         {
             Arr_Sum-=Arr[i];
              if(Left_Sum==Arr_Sum)
              {
                  Flag=1;
                   break;
              }
             Left_Sum+=Arr[i];
         }
         if(Flag==1)
             cout <<"YES" <<endl;
         else
             cout <<"NO" <<endl;
     }
    return 0;
}
