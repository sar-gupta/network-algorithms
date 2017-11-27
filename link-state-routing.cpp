#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int> > dm, int src)
{
  vector<int> dist;
  vector<bool> vis;
  for(int i=0;i<dm.size();i++)
  {
    dist.push_back(INT_MAX);
    vis.push_back(false);
  }
  dist[src] = 0;
  for(int i=0;i<dm.size()-1;i++)
  {
    int u, min=INT_MAX;
    for(int j=0;j<dist.size();j++)
    {
      if(vis[j] == false && dist[j]<min)
      {
        min = dist[j];
        u = j;
      }
    }
    vis[u] = true;
    for(int v=0;v<dm.size();v++)
    {
      if(!vis[v] && dm[u][v] && dist[u] != INT_MAX && dist[u] + dm[u][v] < dist[v])
      {
        dist[v] = dist[u] + dm[u][v];
      }
    }
  }
  for(int i=0;i<dist.size();i++)
  {
    cout<<i<<"\t"<<dist[i]<<endl;
  }

}

int main()
{
  vector<vector<int> > graph {{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0, 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 14, 10, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0}
	};

	dijkstra(graph, 0);

	return 0;
}