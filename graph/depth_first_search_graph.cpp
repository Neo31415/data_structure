#include<bits/stdc++.h>

using namespace std;

#define V 6

bool visited[V] = {false};

void addEdge(vector<int> adj[],int i, int j)
{
	adj[i].push_back(j);
	adj[j].push_back(i);
}

void DFS(vector<int> adj[], int s)
{
	visited[s] = true;
	cout<<s<<" ";
	for (int i = 0; i < adj[s].size(); ++i)
	{
		if(visited[adj[s][i]]==false)
		{
			visited[adj[s][i]] = true;
			DFS(adj,adj[s][i]);	
		}

	}
}



int main()
{
	int v=V;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,1,4);
	addEdge(adj,4,5);
	addEdge(adj,0,2);
	addEdge(adj,2,3);
	addEdge(adj,3,1);
	DFS(adj,0);
	return 0;
}