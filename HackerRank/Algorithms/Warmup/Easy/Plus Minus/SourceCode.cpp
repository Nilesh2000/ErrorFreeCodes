# include <iostream>
using namespace std;
int main()
{
    int n;
    float Pos, Neg, Zero;
    Pos=Neg=Zero=0;
    cin >>n;
    int Arr[n];
     for(int i=0;i<n;i++)
     {
     cin >>Arr[i];
         if(Arr[i]>0)
             Pos++;
         else if(Arr[i]<0)
             Neg++;
         else
             Zero++;
     }
    cout <<Pos/n <<endl
         <<Neg/n <<endl
         <<Zero/n <<endl;
    return 0;
}
