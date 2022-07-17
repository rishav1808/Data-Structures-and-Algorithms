#include <iostream>

using namespace std;

int knapsack(int *wt,int *val,int w,int n)
{
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int j=0;j<=w;j++)
    dp[0][j]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                
            }
            else{
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }
    return dp[n][w];
}

int main()
{
    int wt[]={10,20,30};
    int val[]={60,100,120};
    int n=3;
    int w=50;
    cout<<knapsack(wt,val,w,n);

    return 0;
}

