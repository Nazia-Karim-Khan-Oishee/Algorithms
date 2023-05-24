#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
#define N 105
#define INF 999999
int graph[N][N];
int dist[N][N];

void build_graph(int v){
  for(int i=1;i<=v;i++){
      for(int j=1;j<=v;j++){
        if(i==j){
          dist[i][j]=0;
        }
        else if(graph[i][j]!=0)dist[i][j]=graph[i][j];
        else dist[i][j]=INF;
      }
    }
}

void floyd_warshall(int v){
  for(int k=1;k<=v;k++){
    for(int j=1;j<=v;j++){
      for(int i=1;i<=v;i++){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
}

int main()
{
    fastio;
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
      int a,b,c;// a -> b has a weight of c
      cin>>a>>b>>c;
      graph[a][b]=c;
      graph[b][a]=c;
    }
    build_graph(v);
    floyd_warshall(v);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    for(int i=1;i<=v;i++){
      int sum=0;
      for(int j=1;j<=v;j++){
        sum+=dist[i][j];
      }
      p.emplace(sum,i);
    }
    int distMin=p.top().first;
    while(p.top().first==distMin){
      cout<<p.top().second<<" ";
      p.pop();
    }
    return 0;
}