# include <iostream>
using namespace std;
int main()
{
    int Arr1[5], Arr2[5], Res[5]={0,0};
     for(int i=0;i<3;i++)
     cin >>Arr1[i];
    for(int i=0;i<3;i++)
        cin >>Arr2[i];
    for(int i=0;i<3;i++)
    {
        if(Arr1[i]>Arr2[i])
            Res[0]++;
        else if(Arr1[i]<Arr2[i])
            Res[1]++;
    }
    for(int i=0;i<2;i++)
        cout <<Res[i] <<" ";
    return 0;
}
