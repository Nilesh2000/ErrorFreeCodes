# include <iostream>
using namespace std;
int Arr[102][102];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() 
{
    int h, w;
    cin >>h >>w;    
     for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            cin >>Arr[i][j];
    int Ans=2*h*w; //Top+Bottom
      for(int i=1;i<=h;i++)
       {
          for(int j=1;j<=w;j++)
           {
            for(int k=0;k<4;k++) 
            {
                int x=i+dx[k];
                int y=j+dy[k];
                Ans+=max(0, Arr[i][j]-Arr[x][y]);
            }
        }
    }
    cout <<Ans;
    return 0;
}