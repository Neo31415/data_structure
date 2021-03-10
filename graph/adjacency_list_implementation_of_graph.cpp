# include<bits/stdc++.h>

using namespace std;

void addAdj(vector<int> adj[],int i,int j)
{
	adj[i].push_back(j);
	adj[j].push_back(i);
}

void print_graph_given_vertex(vector<int> adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		cout<<i<<":{";
		for(int j=0;j<adj[i].size();j++)
		{
			if(j+1==adj[i].size())
				cout<<adj[i][j]<<"";
			else
				cout<<adj[i][j]<<",";
		}
		cout<<"}"<<endl;
	}
}

int main()
{
	int v=4;
	vector<int>  adj[v];
	addAdj(adj,0,1);
	addAdj(adj,0,2);
	addAdj(adj,1,2);
	addAdj(adj,1,3);
	print_graph_given_vertex(adj,v);
	return 0;
}