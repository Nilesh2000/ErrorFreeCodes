//Floyd Warshall Algorithm For All Pairs Shortest Path Problem
# include <iostream>
# define INF 9999

using namespace std;

void allSourceShortestPath(int n, int Graph[][10], int Dist[][10])
{
  for(int i = 0 ; i < n ; i++)
  {
    for(int j = 0 ; j < n ; j++)
    {
      Dist[i][j] = Graph[i][j];
    }
  }
  
  for(int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (Dist[i][k] + Dist[k][j] < Dist[i][j])
        {
          Dist[i][j] = Dist[i][k] + Dist[k][j];
        }
      }
    }
  }
}

int main(void)
{
  int n;
  printf("Enter number of nodes : ");
  scanf("%d", &n);
  int Graph[10][10], Dist[10][10];

  for(int i = 0; i < n ; i++)
  {
    for(int j = 0 ; j < n ; j++)
    {
      cout << "Distance[" << i <<"][" << j << "]";
      cin >> Graph[i][j];
      if(Graph[i][j] == 0 && i != j)
        Graph[i][j] = INF;
    }
  }

  cout << "\n";
  allSourceShortestPath(n, Graph, Dist);
  cout << "\t";
  for(int i = 0 ; i < n ; i++)
    cout << '\t' << i;
  cout << "\n";
  for(int i = 0; i < n; i++)
  {
    cout << '\t' << i;
    for (int j = 0; j < n; j++)
    {
      if(Dist[i][j] == INF)
        cout << "INF" << '\t';
      else 
        cout << Dist[i][j] << '\t';
    }
    cout << "\n";
  }
  return 0;
}
//End of program
