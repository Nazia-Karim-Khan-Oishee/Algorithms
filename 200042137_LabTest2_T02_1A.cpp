
#include <bits/stdc++.h>
using namespace std;

int arr[16][16];
int n;
int dp[16][1<<16];
const long long mod=1e9+7;

int turnOn(int N,int pos)
{
    return (N |(1<<pos));
}
bool isOn(int N,int pos)
{
    return (bool)(N & (1<<pos)) ;
}
int bitmask(int i,int mask)
{
    if(mask==((1<<n)-1))
    {
        return 1;

    }
    if(dp[i][mask]!=-1)
    {
        return dp[i][mask];
    }
    dp[i][mask]=0;
    for(int j=0; j<n; j++)
    {
        if(!isOn(mask,j) && arr[i][j]==1)
        {
            dp[i][mask]+=(bitmask(i+1,turnOn(mask,j))%mod);
        }
    }
    return dp[i][mask]%mod;
}

int main()
{

    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<bitmask(0,0)<<endl;
    return 0;
}
