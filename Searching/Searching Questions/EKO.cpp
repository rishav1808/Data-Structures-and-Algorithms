#include <bits/stdc++.h>

using namespace std;
bool isValid(long long int *a,long long int n,long long int m,long long int mid)
{
    long long int sum=0;
    for(long long int i=0;i<n;i++)
    {
        if(a[i]>=mid)
        {
            sum=sum+(a[i]-mid);
            if(sum>=m)
            return true;
        }
    }
    return false;
}
int Eko(long long int *a,long long int n,long long int m){
    long long int start=0;
    long long int end=INT_MIN;
    long long int ans=-1;
    for(long long int i=0;i<n;i++)
    end=max(end,a[i]);
    while(start<=end)
    {
        long long int mid=start+(end-start)/2;
        if(isValid(a,n,m,mid))
        {
            ans=mid;
            start=mid+1;
        }
        else if(isValid(a,n,m,mid)==false)
        end=mid-1;
    }
    return ans;
}

int main()
{
    long long int n,m;
    cin>>n>>m;
    long long int a[n];
    for(long long int i=0;i<n;i++)
    cin>>a[i];
    cout<<Eko(a,n,m);

    return 0;
}

