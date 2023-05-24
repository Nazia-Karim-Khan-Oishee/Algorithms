 #include<bits/stdc++.h>
using namespace std;
int arr[16][16];
int dp[16][1<<16];
int n;

bool isOn(int N,int pos)
{
    return (bool)(N & (1<<pos)) ;
}
int turnOn(int N,int pos)
{
    return (N |(1<<pos));
}

int bitmask(int i, int mask)
{
    if(mask==(1<<n)-1)
    {
        return 0;
    }
    int ans=dp[i][mask];

    if(ans!=-1)
    {
        return ans=dp[i][mask];
    }
    for(int j=0; j<n; j++)
    {
        if(isOn(mask,j)==0)
        {

            ans= max(ans, arr[i][j]+bitmask(i+1,turnOn(mask,j)));
            dp[i][mask]=ans;

        }
    }

    return ans;
}
int main()
{
    int t;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<bitmask(0,0)<<endl;


    return 0;
}

