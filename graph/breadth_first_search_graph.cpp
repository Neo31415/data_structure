#include<bits/stdc++.h>

using namespace std;

void addAdj(vector<int> adj[],int i,int j)
{
	adj[i].push_back(j);
	adj[j].push_back(i);
}

void DFS(vector<int> adj[], int ver)
{
	unordered_set<int> intSet;
	intSet.insert(ver);
	queue<int> que;
	que.push(ver);
	while(!que.empty())
	{
		int ele;
		ele = que.front();
		for(int i=0;i<adj[ele].size();i++)
		{
			if (intSet.find(adj[ele][i]) == intSet.end())
			{
            	intSet.insert(adj[ele][i]);
            	que.push(adj[ele][i]);
			}
		}
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
	DFS(adj,0);
	return 0;


}