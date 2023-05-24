#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)

#define endl "\n"

using namespace std;

bool vis[12];
vector<int>v[12];
vector<int>parent(12,-1);
stack<int> s;
void dfs(int node,int par){
    vis[node]=true;
    parent[node]=par;
    for(auto u:v[node]){
        if(!vis[u]){
            dfs(u,node);
        }
    }
    //s.push(v[node]);

}

int main()
{
    fastio;
    int a,b;
    for(int i=0;i<3;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    for(int i=1;i<5;i++){
        cout<<i<<" "<<parent[i]<<"\n";
    }
    return 0;
}