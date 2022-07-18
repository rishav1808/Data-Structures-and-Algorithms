#include <bits/stdc++.h>

using namespace std;

bool subsetSum(int *a,int n ,int sum , vector<vector<int>>&dp)
{
    if(n==0 && sum!=0)
    return false;
    if(sum==0)
    return true;
    
    if(dp[n][sum]!=-1)
    return dp[n][sum];
    else
    {
        if(a[n-1]<=sum)
    {//condition of take
        return dp[n][sum]=(subsetSum(a,n-1,sum-a[n-1],dp) || subsetSum(a,n-1,sum,dp));
    }
    else
    //condition of not take
    return dp[n][sum]=subsetSum(a,n-1,sum,dp);
    }
    
}


int main()
{
    
    int set[] = {3, 34, 4, 12, 5, 2}, sum = 12;
    int n=6;
   vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    
    cout<<subsetSum(set,6,sum,dp);

    return 0;
}

