#include <bits/stdc++.h>
#include <list>
using namespace std;
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int vis[8][8];
int to[8][2]= {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int ex,ey;
int row,col;
struct node
{
    int x;
    int y;
    int step;
};
int judge(int x,int y)
{
    if(x>=0&&y>=0&& x<8&&y<8&& !vis[x][y])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int BFS(string s1, string s2)
{
    int j=0;
        queue<node>q;
        node p,a;
        int ex,ey;
        p.x=s1[0]-'a';
        p.y=s1[1]-'1';
        p.step=0;
        ex=s2[0]-'a';
        ey=s2[1]-'1';
        vis[p.x][p.y]=1;
        q.push(p);
        while(!q.empty())
        {
            a=q.front();
            if(a.x==ex && a.y==ey)
            {
                return a.step;

            }
            for(j=0; j<8; j++)
            {
                node b;
                b=a;
                b.x+=to[j][0];
                b.y+=to[j][1];
               // cout<<b.y<<" ";
                if(judge(b.x,b.y))
                {
                    b.step++;
                    vis[b.x][b.y]=1;
                    q.push(b);
                }
            }
            //cout<<q.front().x;
            q.pop();
        }

}
int main()
{

int i=8;
        string s1,s2;
while(i--){
        cin>>s1;
        cin>>s2;
for(int i=0;i<8;i++)
{
    for(int j=0;j<8;j++)
    {
        vis[i][j]=0;
    }
}
        cout<<"to get from "<<s1<<" to "<<s2<<" "<<"takes "<<BFS(s1,s2)<<" knight moves"<<endl;}
    return 0;
}
