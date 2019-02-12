# include <iostream>
using namespace std;
int main()
{
    int Num, n, m, s;
    cin >>Num;
     while(Num--)
     {
         cin >>n >>m >>s;
         int Danger=(s+m-1)%n;
          if(Danger==0)
              cout <<n <<endl;
          else
              cout <<Danger <<endl;
     }   
    return 0;
}
