#include <bits/stdc++.h>

using namespace std;
vector<int>adj[100];
vector<int>color(100,-1);

int main()
{
    int v,e;
    bool flag=1;
    cin>>v>>e;
    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // queue<int>q;
    // q.push(0);
    color[0]=1;//1 means red, 0 means blue, -1 means not colored
    // while(!q.empty())
    // {
    //     int parent=q.front();
    //     q.pop();
    for(int i=0;i<v;i++)
    {
        for(auto child:adj[i])
        {
            cout<<i<<" "<<child<<endl;
            if(color[child]==-1)
            {
                if(color[i]==1)
                {
                    color[child]=0;
                }
                else
                {
                    color[child]=1;
                }
              //  q.push(child);
            }
            else if(color[child]==color[i])
            {
                flag=0;
                break;
            }
        }
    }

    if(flag)
    {
        cout<<"BICOLORABLE."<<endl;
        return 0;
    }

    cout<<"NOT BICOLORABLE."<<endl;

    return 0;
}
