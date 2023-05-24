#include<bits/stdc++.h>
using namespace std;

int bfs(int src,int des)
{
    int vis[110]= {0};
    vis[src]=1;
    parent[src]=-1;
    queue<int>Q;
    Q.push(src);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=1; i<=n; i++)
        {
            if(vis[i] or capacity[u][i]<=0) continue;
            Q.push(i);
            vis[i]=1;
            parent[i]=u;

        }
    }

    return vis[des];
}
int maxFlow(int src,int des)
{
    int f=0;
    while(bfs(src,des))
    {

        int path=1e9;
        for(int i=des; i!=src; i=parent[i])
        {
            path=min(path,capacity[parent[i]][i]);
        }

        for(int i=des; i!=src; i=parent[i])
        {

            int u=parent[i];
            int v=i;

            capacity[u][v]-=path;
            capacity[v][u]+=path;

        }

        f+=path;

    }
    return f;
}



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> capacities(n);
        for (int i = 0; i < n; i++)
        {
            cin >> capacities[i];

        }
        vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
        adj_matrix[0][0]=0;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y, c;
            cin >> x >> y >> c;
            adj_matrix[x][y] = c;
        }
        int b, d;
        cin >> b >> d;
        vector<int> entry_points(b), exit_points(d);
        for (int i = 0; i < b+d; i++)
        {
            int x;
            cin >> x;
            if (i < b)
            {
                entry_points[i] = x;
            }
            else
            {
                exit_points[i-b] = x;
            }
        }

        return 0;
    }








