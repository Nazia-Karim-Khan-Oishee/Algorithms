#include <bits/stdc++.h>
using namespace std;

bool vis[500][500];
int g[500][500];
int movesx[] = { 0, -1, 1, 0};
int movesy[] = { 1,  0, 0, -1};
int n, m;
bool isValid(int x, int y) {
    if (x < 0 or y<0 or x>n or y > m ) {
        return false;
    }

    if (vis[x][y]) {
        return false;
    }

    if (g[x][y] == 0) {
        return true;
    }

    return true;
}


bool isOnEdge(int x, int y) {
    if (x == 1 or x == n or y == 1 or y == m) {
        return true;
    }
    return false;
}

void dfs(int x, int y, bool &OnEdge) {
    vis[x][y] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int X = x + movesx[i];
        int Y = y + movesy[i];
        if (isValid(X, Y)) {
            vis[X][Y] = 1;
            if (isOnEdge(X, Y)) {
                OnEdge = 1;
            }
            dfs(X, Y, OnEdge);
        }
    }


}


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
int n,m;
cin >>n>>m;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin>>g[i][j];
        }
    }
    int ans=0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            bool onEdge = 0;
            if (isValid(g[i][i], g[i][j])) {

                dfs(g[i][i], g[i][j], onEdge);
                if(!onEdge){
                    //cout<<1;
                    ans++;
                }
            }
        }
    }

cout << ans;
return 0;
}

