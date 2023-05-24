/*
#include <bits/stdc++.h>
using namespace std;

int adj[1000]={0};
int edge[1000][1000]={0};
int total_distance[1000]={0};
priority_queue<pair<int,int> > Queue;
pair <int,int> edge_distance;
pair<int,int> PAIR;
int main()
{
  int n,m,x,y,dist;
  int edgecount=0;
  //int total_distance=0;
  cin>>n>>m;
  while(m--)
  {
      cin>>x>>y>>dist;
      adj[x]=adj[x]+dist;
      adj[y]=adj[y]+dist;
      //adj[y][x]=dist;
      edge[x][y]=1;
      //cout<<edge[x][y];
      edge[y][x]=1;
     // cout<<edge[y][x];
  }
  for(int i=0; i<n;i++)
  {
      for(int j=0;j<n;i++)
      {

          if(edge[i][j]==1)
          {
              edgecount++;
            //cout<<edgecount<<endl;
             int distance=adj[i];
            total_distance[i] = total_distance[i]+distance;
          }
      }
      Queue.push({ edgecount, i });
      edgecount=0;
  }
  while(!Queue.empty())
  {
      int house=Queue.top().second;
      cout<<Queue.top().second;
  }
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int graph[105][105];
int dist[105][105];

int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=0; i<e; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
            }
            else if(graph[i][j]!=0)
            {
            dist[i][j]=graph[i][j];
            }
            else
            {
            dist[i][j]=1000000;
            }
        }
    }

    for(int k=1; k<=v; k++)
    {
        for(int j=1; j<=v; j++)
        {
            for(int i=1; i<=v; i++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    // for(int i=1;i<=v;i++)
    // {
    //     for(int j=1; j<=v; j++)
    //        {
    //          cout<<dist[i][j]<<" ";
    //        }
    //  cout<<endl;
    // }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;//default max heap
    for(int i=1; i<=v; i++)
    {
        int sum=0;
        for(int j=1; j<=v; j++)
        {
            sum=sum+dist[i][j];
        }
        que.push({sum,i});
    }
    int min_dist=que.top().first;
    while(que.top().first==min_dist)
    {
        cout<<que.top().second<<" ";
        que.pop();
    }
    return 0;
}
