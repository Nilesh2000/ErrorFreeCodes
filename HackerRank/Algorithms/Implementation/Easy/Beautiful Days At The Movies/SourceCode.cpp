# include <iostream>
using namespace std;
int Reverse(int Num)
{
    int Rev=0, Rem;
     while(Num!=0)
     {
         Rem=Num%10;
         Rev=Rev*10+Rem;
         Num/=10;
     }
    return Rev;
}
int main()
{
    int i, j, k, Total=0;
    cin >>i >>j >>k;
     for(int Num=i;Num<=j;Num++)
     {
         int Rev=Reverse(Num);
          if(abs((Num-Rev))%k==0)
              Total++;
     }
    cout <<Total;
    return 0;
}
