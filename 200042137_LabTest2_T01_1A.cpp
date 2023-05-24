#include <bits/stdc++.h>

using namespace std;
vector<int>v;
int ans;
int n;
int dp[100][100];
int matrix_mult(int left, int right)
{
    if (left >= right)
    {
        dp[right][right]=v[right];
        return 0;
    }

    long long val = 1e9;
    for (int i = left; i < right; i++)
    {
        int l=matrix_mult(left,i);
        int r=matrix_mult(i+1,right);
        if(dp[left][i]*dp[i+1][right]+l+r<val){
            dp[left][right]=(dp[left][i]+dp[i+1][right])%100;
            val=(dp[left][i]*dp[i+1][right])+l+r;
        }

    }
    return val;
 
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    while (cin >> n)
    {
        v.clear();
        ans = 1e9;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        cout<<matrix_mult(0, n - 1)<<endl;
        
      }
    return 0;
}