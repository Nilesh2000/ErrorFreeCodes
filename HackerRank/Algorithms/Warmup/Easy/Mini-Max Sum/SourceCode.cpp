# include <iostream>
using namespace std;
int main()
{
    long long Arr[5], Temp, Min=0, Max=0;
     for(int i=0;i<5;i++)
        cin >>Arr[i];
     for(int i=0;i<4;i++)
      {
        for(int j=(i+1);j<5;j++)
         {
           if (Arr[i]>Arr[j])
            {
                Temp=Arr[i];
                Arr[i]=Arr[j];
                Arr[j]=Temp;
            }
        }
      }
     for(int i=0;i<4;i++)
        Min+=Arr[i];
     for(int i=1;i<5;i++)
        Max+=Arr[i];
    cout <<Min <<" " <<Max;
     return 0;
}
