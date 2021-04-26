#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int i,int j)
{
	adj[i].push_back(j);
	adj[j].push_back(i);
}

void BFS(vector<int> adj[], int v, int s)
{
	bool visited[v+1] = {false};
	queue<int> que;
	que.push(s);
	visited[s] = true;
	while(!que.empty())
	{
		int ele=que.front();
		for (int i = 0; i < adj[ele].size(); ++i)
		 {
		 	if(visited[adj[ele][i]]==false)
		 	{
		 		que.push(adj[ele][i]);
		 		visited[adj[ele][i]] = true;
		 	}
		 }
		 // if(ele!=s)
		 cout<<ele<<" ";
		 que.pop();
	}

}



int main()
{
	int v=7;
	vector<int> adj[v];
	bool visited[v];
	// unordered_set<int> intSet;
	addEdge(adj,0,1);
	addEdge(adj,0,5);
	addEdge(adj,0,2);
	addEdge(adj,1,3);
	addEdge(adj,2,4);
	addEdge(adj,3,5);
	addEdge(adj,4,5);
	BFS(adj,v,0);
	return 0;
}

// int main() 
// { 
// 	int V=7;
// 	vector<int> adj[V];
// 	addEdge(adj,0,1); 
// 	addEdge(adj,0,2); 
// 	addEdge(adj,2,3); 
// 	addEdge(adj,1,3); 
// 	addEdge(adj,4,5);
// 	addEdge(adj,5,6);
// 	addEdge(adj,4,6);

// 	cout << "Following is Breadth First Traversal: "<< endl; 
// 	BFSDin(adj,V); 

// 	return 0; 
// } 