#include <bits/stdc++.h>

using namespace std;


int countOfSubsetSum(int *a,int n,int sum,int count, vector<vector<int>>&dp)
{
    if(n==0 && sum!=0)
    return 0;
    if(sum==0)
    {
        count++;
        dp[n][sum]=count;
        return dp[n][sum];
    }
    if(dp[n][sum]!=-1)
    return dp[n][sum];
    else
    {
         if(a[n-1]<=sum)
    {
       return dp[n][sum] =countOfSubsetSum(a,n-1,sum-a[n-1],count,dp) + countOfSubsetSum(a,n-1,sum,count,dp);
    }
    else
    return dp[n][sum] = countOfSubsetSum(a,n-1,sum,count,dp);
    }
   
}


int main()
{
   
    int arr[] = {2, 3, 5, 6, 8, 10}, X = 10000  ;
    int n=6;
     vector<vector<int>>dp(n+1,vector<int>(X+1,-1));
    cout<<countOfSubsetSum(arr,n,X,0,dp);

    return 0;
}

