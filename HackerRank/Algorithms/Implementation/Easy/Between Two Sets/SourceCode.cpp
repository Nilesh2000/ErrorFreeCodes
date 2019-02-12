# include <iostream>
using namespace std;
int main()
{
    int a, b, Count=0;
    cin >>a >>b;
    int Arr1[a], Arr2[b];
     for(int i=0;i<a;i++)
         cin >>Arr1[i];
     for(int i=0;i<b;i++)
        cin >>Arr2[i];
     for(int Num=1;Num<=100;Num++)
     {
        int Flag=1;
        for(int i=0;i<a;i++)
            if(Num%Arr1[i]!=0)
                Flag=0;
        for(int i=0;i<b;i++)
            if(Arr2[i]%Num!=0)
                Flag=0;
        if (Flag==1)
            Count++;
    }
    cout <<Count;
    return 0;
}
