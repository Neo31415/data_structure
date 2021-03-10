#include<bits/stdc++.h>

using namespace std;

void addAdj(vector<int> adj[],int i,int j)
{
	adj[i].push_back(j);
	adj[j].push_back(i);
}

void BFS(vector<int> adj[], int v, int s)
{
	bool visited[v+1];
	for (int i = 0; i < v; ++i)
		visited[i]=false;
	queue<int> que;
	que.push(s);
	visited[s] = true; 
	while(!que.empty())
	{
		int ele;
		ele = que.front();
		for (int i = 0; i < adj[ele].size(); ++i)
		{
			if (visited[adj[ele][i]]==false)
			{
				visited[adj[ele][i]] = true;
				que.push(adj[ele][i]);
			}
		}
		visited[ele] = true;
		cout<<ele<<" ";
		que.pop();
	}
}

int main()
{
	int v=6;
	vector<int> adj[v];
	unordered_set<int> intSet;
	addAdj(adj,0,1);
	addAdj(adj,0,2);
	addAdj(adj,0,5);
	addAdj(adj,1,3);
	addAdj(adj,2,4);
	addAdj(adj,3,5);
	addAdj(adj,4,5);
	BFS(adj,v,0);
	return 0;


}