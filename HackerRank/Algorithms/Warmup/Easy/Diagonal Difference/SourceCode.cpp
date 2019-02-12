# include <iostream>
using namespace std;
int main()
{
    int n, Diag1=0, Diag2=0, Diff;
    cin >>n;
    int Arr[n][n];
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             cin >>Arr[i][j];
             if(i==j && i+j==n-1)
             {
                 Diag1+=Arr[i][j];
                 Diag2+=Arr[i][j];
             }
              else if(i==j)
                Diag1+=Arr[i][j];
               else if(i+j==n-1)
                Diag2+=Arr[i][j];
         }
     }
    Diff=Diag1-Diag2;
     if(Diff<0)
         Diff*=-1;
    cout <<Diff;
    return 0;
}
