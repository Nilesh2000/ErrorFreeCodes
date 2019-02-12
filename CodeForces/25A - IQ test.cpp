# include <iostream>
using namespace std;
int main()
{
  int n;
  cin >>n;
  int a, LastoddPos, LastevenPos, evenCount=0;
   for(int i=1;i<=n;i++)
    {
      cin >>a;
       if(a%2)
        {
          LastoddPos=i;
          evenCount--;
        }
       else
        {
          LastevenPos=i;
          evenCount++;
        }
    }
  cout <<(evenCount>0 ? LastoddPos : LastevenPos) <<endl;
  //Check if evenCount>0, then display oddPos because count of even numbers will be greater when there is only
  //1 odd number and vice-versa.
  return 0;
}
