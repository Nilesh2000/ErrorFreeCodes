# include <iostream>
using namespace std;
void Sort_Array(int Arr[], int n)
{
    int Temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(Arr[i]>Arr[j])
            {
                Temp=Arr[i];
                Arr[i]=Arr[j];
                Arr[j]=Temp;
            }
        }
    }
}
int main()
{
    int n;
    cin >>n;
    int Remain=n, Arr[n];
     for(int i=0;i<n;i++)
         cin >>Arr[i];
    Sort_Array(Arr,n);
    int Shortest=Arr[0];
    cout <<Remain <<endl;
     for(int i=1;i<n;i++)
     {
        if(Arr[i]!=Shortest)
        {
            Shortest=Arr[i];
            Remain=n-i;
            cout <<Remain <<endl;
        }
    }
    return 0;
}
