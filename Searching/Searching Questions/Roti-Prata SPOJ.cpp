#include <bits/stdc++.h>
 
using namespace std;
int solve(int *a,int n,int par,int mid)
{
    int timee=0,paratha=0,j=1;
    for(int i=0;i<n;i++)
    {
        timee=a[i];
        j=2;
        while(timee<=mid)
        {
            paratha++;
            timee+=j*a[i];
            j++;
        }
        if(paratha>=par)
        return 1;
        
    }
    return 0;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int par;
        cin>>par;
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int lb=0;
        int ub=1e8;
        int ans=0;
        while(lb<=ub){
            int mid=(lb+ub)/2;
            if(solve(a,n,par,mid))
            {
                ans=mid;
                ub=mid-1;
            }
            else
            lb=mid+1;
        }
        cout<<ans<<endl;
    }
 
 
    return 0;
}
 
