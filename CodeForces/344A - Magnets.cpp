# include <iostream>
using namespace std;
int main()
{
  int n, Groups=0;
  char Str[3], Ch='\0';
  cin >>n;
   while(n--)
    {
      cin >>Str;
       if(Str[0]!=Ch)
        Groups++;
      Ch=Str[0];
    }
  cout <<Groups <<endl;
  return 0;
}
