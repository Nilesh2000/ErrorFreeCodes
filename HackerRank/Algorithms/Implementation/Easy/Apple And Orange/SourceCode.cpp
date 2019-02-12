# include <iostream>
using namespace std;
int main()
{
    int s, t, a, b, m, n, Num1=0, Num2=0;
    cin >>s >>t;
    cin >>a >>b;
    cin >>m >>n;
    int Apples[m], Oranges[n];
    for(int i=0;i<m;i++)
    {
          cin >>Apples[i];
          Apples[i]+=a;
           if(Apples[i]>=s && Apples[i]<=t)
               Num1++;
    }
    for(int i=0;i<n;i++)
    {
        cin >>Oranges[i];
        Oranges[i]+=b;
         if(Oranges[i]>=s && Oranges[i]<=t)
             Num2++;
    }
    cout <<Num1 <<endl <<Num2;
    return 0;
}
