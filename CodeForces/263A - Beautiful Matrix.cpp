# include <iostream>
# include <cstdlib>
using namespace std;
int main()
{
  int Mat[5][5], Row, Col;
   for(int i=0;i<5;i++)
    {
     for(int j=0;j<5;j++)
      {
       cin >>Mat[i][j];
        if(Mat[i][j]==1)
         {
          Row=i+1;
          Col=j+1;
         }
      }
    }
  cout <<abs(Row-3)+abs(Col-3) <<endl;
  return 0;
}
