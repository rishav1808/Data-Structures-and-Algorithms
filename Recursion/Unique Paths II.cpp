class Solution {
public:
    
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {        
	int m = size(obstacleGrid),  n = size(obstacleGrid[0]); 
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    
	return solve(obstacleGrid, 0, 0,dp,m,n);   
}
// function to recursively explore all unique paths
int solve(vector<vector<int> >& grid, int i, int j,vector<vector<int>>&dp,int m,int n){
	if(i >= m || j >= n) return dp[i][j]=0;          // bounds checking
	if(grid[i][j]) return dp[i][j]=0;   // if there's obstacle, just return 0 and stop further exploration
	if(i == m - 1 && j == n - 1 && !grid[i][j]) return dp[i][j]=1;     // if we have reached end cell, return 1 if there's no obstacle 
    
    if(dp[i][j]!=-1)
        return dp[i][j];
	return dp[i][j]=solve(grid, i + 1, j,dp,m,n) + solve(grid, i, j + 1,dp,m,n); 
}
    
};
