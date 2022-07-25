class Solution {
    
private:
    int solve(int m,int n,int x,int y ,vector<vector<int>>&dp)
    {
        if(x==m && y==n)
            return 1;
        if(x>m || y>n)
            return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        else
            
        return dp[x][y]=solve(m,n,x+1,y,dp)+solve(m,n,x,y+1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        int x=0,y=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m-1,n-1,x,y,dp);
        
    }
};
