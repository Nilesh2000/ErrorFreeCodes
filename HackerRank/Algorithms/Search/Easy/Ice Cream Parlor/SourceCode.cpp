# include <iostream>
using namespace std;
int main()
{
    int n, Money, Flavours;
    cin >>n;
     while(n--)
     {
         cin >>Money >>Flavours;
         int Cost[Flavours];
         for(int i=0;i<Flavours;i++)
             cin >>Cost[i];
         for(int i=0;i<Flavours;i++)
         {
             for(int j=i+1;j<Flavours;j++)
             {
                 if(Cost[i]+Cost[j]==Money)
                     cout <<i+1 <<" " <<j+1 <<endl;
             }
         }
         
     }
    return 0;
}
