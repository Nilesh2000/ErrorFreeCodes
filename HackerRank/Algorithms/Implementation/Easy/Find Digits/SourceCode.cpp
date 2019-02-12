# include <iostream>
using namespace std;
int Split_Digit(int Num)
{
    int Temp=Num, Digit, Divisor=0;
    while(Temp!=0)
    {
        Digit=Temp%10;
         if(Digit!=0 && Num%Digit==0)
             Divisor++;
        Temp/=10;
    }
    return Divisor;
}
int main()
{
    int n;
    cin >>n;
    int Arr[n];
     for(int i=0;i<n;i++)
     {
         cin >>Arr[i];
         cout <<Split_Digit(Arr[i]) <<endl;
     }   
    return 0;
}
