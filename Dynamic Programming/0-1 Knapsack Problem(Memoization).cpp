#include <bits/stdc++.h>

using namespace std;

int dp[100][1000];

int knapsack(int *wt,int *val,int w,int n)
{
    
    if(n==0 || w==0)
    return 0;
    
    if(dp[n][w]!=-1)
    return dp[n][w];
    else{
        if(wt[n-1]<=w)
        {
            dp[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
             return dp[n][w];
        }
        else
        {
            dp[n][w]= knapsack(wt,val,w,n-1);
            return dp[n][w];
        }
    }
    
}

int main()
{
    memset(dp,-1,sizeof(dp));
int wt[]={10,20,30};
int val[]={60,100,120};
int n=3;
int w=50;
cout<<knapsack(wt,val,w,n);

    return 0;
}

