//Adjacency List representation of a graph
# include <iostream>
# include <vector>

using namespace std;

//While adding an edge, we have to make sure that a and b are connected and b and a are also connected
void addEdge(vector <int> V[], int u, int v)
{
    V[u].push_back(v);
    V[v].push_back(u);
}

void printGraph(vector <int> V[], int numOfVertices)
{
    for(int i = 0 ; i < numOfVertices ; i++) //Iterate over the number of rows, that is the number of vertices
    {
        cout << i << " ";
        for(auto x : V[i]) //Iterate over each element in each row
          cout << "->" << x;
        cout << "\n";
    }
}

int main(void)
{
    int V = 5;
    vector <int> Adj[V]; //Craete a 2D vector with the number of rows equal to the number of vertices
    addEdge(Adj, 0, 1);
    addEdge(Adj, 0, 4);
    addEdge(Adj, 1, 2);
    addEdge(Adj, 1, 3);
    addEdge(Adj, 1, 3);
    addEdge(Adj, 1, 4);
    addEdge(Adj, 2, 3);
    addEdge(Adj, 3, 4);
    cout << "\nAdjacency List of the matrix : \n";
    printGraph(Adj, V);
    return 0;
}
