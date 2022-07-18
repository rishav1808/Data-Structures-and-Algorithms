//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool fun(int *a,int n,int sum)
    {
        if(n==0 && sum!=0)
        return 0;
        if(sum==0)
        return 1;
        //To take
        if(a[n-1]<=sum)
        {
            return (fun(a,n-1,sum-a[n-1]) || fun(a,n-1,sum));
        }
        else
        return fun(a,n-1,sum);
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
            sum=sum/2;
            return fun(a,n,sum);
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
