  #include <iostream>
using namespace std;
//#define max_nodes 100
//#define inf 1e9
const int max_nodes = 100;
const int inf = 1e9; 

struct edge{
	int dest;
	int weight;
};
void dijkstra(edge e[max_nodes][max_nodes], int parent[max_nodes], int distance[max_nodes], int V, int source)
{
	bool visited[max_nodes] = {false};
	for(int i=0; i<V; i++)
	{
		distance[i] = inf;
		parent[i] = -1;
	}
	distance[source] = 0;
	for(int i=0; i<V; i++)
	{
		int u = -1;
		for(int j=0; j<V; j++)
		{
			if(!visited[j] && (u==-1 || distance[j] < distance[u]))
			{
				u=j;
			}
		}
		if(distance[u] == inf)
		{
			break;
		}
		else
		{
			visited[u] = true;
		}
		for(int v=0; v<V; v++)
		{
			if(e[u][v].weight > 0)
			{
				int w = e[u][v].weight;
				if(!visited[v] && distance[u] + w <distance[v])
				{
					distance[v] = distance[u] + w;
					parent[v] = u;
				}
			}
		}
	}
}
void printShortestPath(int parent[max_nodes], int target)
{
	if(parent[target] == -1)
	{
		cout <<"no path to target exist " << endl;
		return;
	}
	int path[max_nodes];
	int pathLength = 0;
	int current = target;
	while(current != -1)
	{
		path[pathLength++] = current;
		current = parent[current];
		
	}
	cout <<"shortest path from source to target" << endl;
	for(int i=pathLength-1; i>=0; i--)
	{
		cout << path[i];
		if(i>0)
		{
			cout <<" -> ";
		}
	}
	cout << endl;
}

int main()
{
	edge e[max_nodes][max_nodes];
	int parent[max_nodes];
	int distance[max_nodes];
	int V, E;
	cout <<"enter the vertices and edges: ";
	cin >> V >> E;   // V =5 & E = 7
	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
		{
			e[i][j].weight = 0;
		}
	}
// src dest wgt
//0 1 4
//0 2 2
//1 2 5
//1 3 10
//2 3 3
//2 4 2
//3 4 8

	for(int i=0; i<E; i++)
	{
		int src, dest, wgt;
		cin >> src >> dest >> wgt;
		e[src][dest].weight= wgt;
	}
	int source, target;
	cout <<"enter the source and target: ";
	cin >> source >> target;  // source = 0 & target = 4
	dijkstra(e, parent, distance, V, source);
	 cout << "Shortest distance from source to target: " << distance[target] << endl;
    printShortestPath(parent, target);

    return 0;
}
