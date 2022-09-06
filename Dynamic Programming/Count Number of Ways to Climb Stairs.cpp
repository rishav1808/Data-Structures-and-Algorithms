
 int mod = 1000000007;
int solve(int nStairs,vector<int>&dp)
{
    if(nStairs==0 || nStairs==1)
    {
        
        return 1;
    }
    if(nStairs<0)
        return 0;
    if(dp[nStairs]!=-1)
        return dp[nStairs]%mod;
    else
    {
        dp[nStairs]=solve(nStairs-1,dp) + solve(nStairs-2,dp);
        return dp[nStairs]%mod;
    }
    
}

int countDistinctWays(int nStairs) {
    
    vector<int>dp(nStairs+1,-1);
    return solve(nStairs,dp);
}
