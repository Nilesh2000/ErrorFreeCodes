# include <iostream>
using namespace std;
#define CONDITION_1 Arr[i][j]>Arr[i-1][j] && Arr[i][j]>Arr[i][j-1]
#define CONDITION_2 Arr[i][j]>Arr[i+1][j] && Arr[i][j]>Arr[i][j+1]
int main()
{
    int n;
    char Arr[101][101];
    cin >>n;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cin >>Arr[i][j];
    for(int i=1;i<n-1;i++)
     {
      for(int j=1;j<n-1;j++)
       {
        if(CONDITION_1 && CONDITION_2)
          Arr[i][j]='X';
       }
     }
    for(int i=0;i< n;i++)
    {
     for(int j=0;j<n;j++)
        cout <<Arr[i][j];    
     cout <<endl;
    }    
    return 0;
}
