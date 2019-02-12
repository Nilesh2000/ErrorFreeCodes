# include <iostream>
# include<cmath>
using namespace std;
int FormingMagicSquare(int Arr[][3])
{
    int Magic[8][3][3]={{{8,1,6},{3,5,7},{4,9,2}},
                        {{6,1,8},{7,5,3},{2,9,4}},
                        {{4,9,2},{3,5,7},{8,1,6}},
                        {{2,9,4},{7,5,3},{6,1,8}},
                        {{8,3,4},{1,5,9},{6,7,2}},
                        {{4,3,8},{9,5,1},{2,7,6}},
                        {{6,7,2},{1,5,9},{8,3,4}},
                        {{2,7,6},{9,5,1},{4,3,8}}};

    int Store[8];
    for(int k=0;k<8;k++)
    {
     Store[k] = 0;
      for(int i=0;i<3;i++)
      {
        for(int j=0;j<3;j++)
        {
            if(Arr[i][j]!=Magic[k][i][j])
                Store[k]+=abs(Arr[i][j]-Magic[k][i][j]);
         }
      }
    }
    int Min=Store[0];
    for(int i=1;i<8;i++)
     {
        if(Store[i]<Min)
         Min=Store[i];
    }
    return Min;
}
int main()
{
    int Arr[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >>Arr[i][j];
        }
    }
    int Result=FormingMagicSquare(Arr);
    cout <<Result;
    return 0;
}
