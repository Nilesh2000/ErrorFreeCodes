// C++ program to print DFS traversal from a given vertex in a given graph
# include <iostream>
# include <list>
using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph
{
	int V; //No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists

public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void DFS(int v, bool *visited);
};

Graph::Graph(int V)
{
	this -> V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// DFS traversal of the vertices reachable from v.
void Graph::DFS(int v, bool *visited)
{
	// Mark all the vertices as not visited
	visited[v] = true;
	cout << v << " ";
	//Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin() ; i != adj[v].end() ; i++)
	{
			if (!visited[*i])
			{
				DFS(*i, visited);
			}
  }
}

int main()
{
	// Create a graph given in the above diagram
	int V = 4;
	Graph g(V);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
	g.DFS(2, visited);
	return 0;
}
