# include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    int Arr[n], Height[n];
     for(int i=0;i<n;i++)
     {
      cin >>Arr[i];
      Height[i]=1;
       for(int j=1;j<=Arr[i];j++)
        {
         if(j%2!=0)
          Height[i]*=2;
         if(j%2==0)
          Height[i]++;   
        }
     }
    for(int i=0;i<n;i++)
        cout <<Height[i] <<endl;
 return 0;
}
    
