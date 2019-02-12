# include <iostream>
using namespace std;
int getMax(int L, int R)
{
    int Ans;
    if(R-L==1) 
        return 0;
    for(int i=L+1;i<R;i++)
        Ans = max(Ans, min(i-L , R-i));
    return Ans;
}
void Sort_Array(int Arr[], int n)
{
    int Temp;
     for(int i=0;i<n-1;i++)
     {
         for(int j=0;j<n-i-1;j++)
         {
             if(Arr[j]>Arr[j+1])
             {
                 Temp=Arr[j];
                 Arr[j]=Arr[j+1];
                 Arr[j+1]=Temp;
             }
         }
     }
}
int main()
{
    int n, m;
    cin >>n >>m;
    int Arr[m];
    for(int i= 0;i<m;i++)
       cin >>Arr[i];
    Sort_Array(Arr,m);
    int L = 0, R = 0, Ans=Arr[0];
    for(int i=1;i<m;i++)
    {
        L=Arr[i-1];
        R=Arr[i];
        Ans=max(Ans,getMax(L,R));
    }
    cout <<max(Ans, n-Arr[m-1]-1) <<endl;
    return 0;
}