#include <bits/stdc++.h>

using namespace std;

int miniSubsetSumDiff(int *a,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];
    int dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    for(int j=1;j<=sum;j++)
    dp[0][j]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i-1]<=j)
            dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
            
        }
    }
   // return dp[n][sum];
    vector<int>possibleSum;
    for(int j=0;j<=sum/2;j++)
    {
        if(dp[n][j]==1)
         possibleSum.push_back(j);
        
    }
    int ans = INT_MAX;
    for(int i=0;i<possibleSum.size();i++)
    {
        ans = min(ans,sum-(2*possibleSum[i]));
    }
    return ans;
   
    
}

int main()
{
    int n=4;
    int a[n]={1,6,11,5};
    cout<<miniSubsetSumDiff(a,n);

    return 0;
}

