//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool fun(int *a,int n,int sum, vector<vector<int>>&dp)
    {
        if(n==0 && sum!=0)
        return 0;
        if(sum==0)
        return 1;
        if(dp[n][sum]!=-1)
        return dp[n][sum];
       
        //To take
         if(a[n-1]<=sum)
        {
            return dp[n][sum]=(fun(a,n-1,sum-a[n-1],dp) || fun(a,n-1,sum,dp));
        }
        else
        return  dp[n][sum]=fun(a,n-1,sum,dp);
       
    }

    int equalPartition(int n, int a[])
    {
        int sum = 0;
        for(int i=0;i<n;i++)
        sum+=a[i];
        if(sum%2!=0)
        return 0;
        else
        {
            vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
            sum=sum/2;
            return fun(a,n,sum,dp);
        }
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
