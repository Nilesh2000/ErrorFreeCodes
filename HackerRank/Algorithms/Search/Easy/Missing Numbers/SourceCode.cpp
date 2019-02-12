# include <bits/stdc++.h>
using namespace std;
int main()
{
    int Num, Size1, Size2, Res[10001]={0}, Max=INT_MIN, Min=INT_MAX;
    cin >>Size1;
     for(int i=0;i<Size1;i++)
     {
         cin >>Num;
         Res[Num]--;
     }
    cin >>Size2;
     for(int i=0;i<Size2;i++)
     {
         cin >>Num;
         Res[Num]++;
         if(Num<Min)
             Min=Num;
         if(Num>Max)
            Max=Num;
     }
    for(int i=Min;i<=Max;i++)
        if(Res[i]>0)
            cout << i << " ";
    return 0;
}
