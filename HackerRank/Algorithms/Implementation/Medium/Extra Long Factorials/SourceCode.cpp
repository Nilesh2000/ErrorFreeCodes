#include<iostream>
using namespace std;
int main()
{  
        int num;
        int k=0, carry=0, Arr[1000]={1};
        cin >>num;
        for(int i=1;i<=num;i++)
        {
            for(int j=0;j<=k;j++)
             {
                Arr[j]=Arr[j]*i+carry;
                carry=Arr[j]/10;
                Arr[j]%=10;
             }
             while(carry)
             {
                 k++;
                 Arr[k]=carry%10;
                 carry/=10;
             }
         }
         for(int i=k;i>=0;i--)
          cout <<Arr[i];
        cout <<endl;
    return 0;
}
