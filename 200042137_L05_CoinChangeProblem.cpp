#include <bits/stdc++.h>

using namespace std;
int n,m;
int dp[1000][1000];
int array_of_coins[1000];

int coin_change(int i,int amount) {
 if(i==m || amount<0)
 {
  return 0;
 }
 if(amount==0)
 {
  return 1;
 }
 if(dp[i][amount]!=-1)
 {
  return dp[i][amount];
 }
return dp[i][amount]=coin_change(i,amount-array_of_coins[i])+coin_change(i+1,amount);
 
}



int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>array_of_coins[i];
    }
    cout<<coin_change(0,n);
}

