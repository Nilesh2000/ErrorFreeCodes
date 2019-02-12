# include <iostream>
using namespace std;
int main()
{
    int n, UpDown=0, Res=0;
    cin >>n;
    char Str[n];
     for(int i=0;i<n;i++)
     {
         cin >>Str[i];
          if(Str[i]=='U')
              UpDown++;
          else
              UpDown--;
          if(UpDown==0 && Str[i]=='U')
              Res++;
     }    
     cout <<Res;
    return 0;
}
