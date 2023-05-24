#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
string str;
int get_ways(int i, int size)
{
if(i>size)
{
    return 0;
}
if(dp[i][size]!=-1)
{
    return dp[i][size];
}
if(str[i]==str[size])
{
    return dp[i][size]=get_ways(i+1, size-1);
}
return dp[i][size]=min(1+get_ways(i, size-1), 1+get_ways(i+1, size));
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int size;
    cin>>size;
    cin>>str;
    cout<<get_ways(0,size-1);
    return 0;
}