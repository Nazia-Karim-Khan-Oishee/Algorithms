#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int x;
    int t,n;

    cout<<"Enter the number of mixtures ";
    cin>>n;
    vector<int> a(n);

    vector<vector<pair<int, int> > > dp(n+1,vector<pair<int, int> >(n+1));

    cout<<"Enter the initial color of mixtures "<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>dp[i][i].second;
        dp[i][i].first=0;
    }

    for(int gap=2;gap<=n;gap++)
    {
        for(i=1;i<=(n-gap+1);i++)
        {
            j=i+gap-1;
            dp[i][j].first=INT_MAX;

            for(k=i;k<j;k++)
            {
                //try for every value of k
                x=dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second;
                if(x<dp[i][j].first)
                {
                    dp[i][j].first=x;
                    dp[i][j].second=(dp[i][k].second+dp[k+1][j].second)%100;
                }

            }


        }
    }

    cout<<"The minimum amount of smoke that will be produced by mixing all the mixtures together is "<<endl;
    cout<<dp[1][n].first<<endl;

    return 0;
}








// Input: n, the number of mixtures
//        a, an array of n integers representing the colors of the mixtures
// Output: the minimum amount of smoke generated

int mixtures(int n, vector<int>& a) {
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> sum(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
        sum[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            sum[i][j] = sum[i][j-1] + a[j];
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (sum[i][k] * sum[k+1][j]));
            }
        }
    }
    return dp[0][n-1];
}
