//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
  int solve(int *a,int n,int range ,int s,vector<vector<int>>&dp)
  {
      if(n==0)
      return abs(range-2*s);
      
      if(dp[n][s]!=-1)
      return dp[n][s];
      else{
          return dp[n][s] = min(solve(a,n-1,range,s+a[n-1],dp),solve(a,n-1,range,s,dp));
      }
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int s =0;
	    int range=0;
	    for(int i=0;i<n;i++)
	    range +=arr[i];
	    vector<vector<int>>dp(n+1,vector<int>(range+1,-1));
	    
	    
	    return solve(arr,n,range,s,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
