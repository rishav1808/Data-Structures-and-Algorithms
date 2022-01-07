/* Pair with given sum in Unsorted array*/
#include <bits/stdc++.h>

using namespace std;
bool pairSum1(int *a,int n,int sum)//TC: O(N^2)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==sum)
            return true;
        }
    }
    return false;
}
bool pairSum2(int *a,int n,int sum)//TC:O(NlogN)
{
    sort(a,a+n);
    int start=0,end=n-1;
    while(start<end)
    {
        if(a[start]+a[end]==sum)
        return true;
        else if(a[start]+a[end]<sum)
        start++;
        else
        end--;
    }
    return false;
}
bool pairSum3(int *a,int n,int sum)//TC:O(N)  SC:O(N)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        if(s.find(sum-a[i])!=s.end())
        return true;
        else
        s.insert(a[i]);
    }
    return false;
}
int main()
{
    int a[]={3,2,8,15,-8};
    int n=4;
    int sum=17;
    cout<<pairSum1(a,n,sum)<<endl;
    cout<<pairSum2(a,n,sum)<<endl;
    cout<<pairSum3(a,n,sum)<<endl;
    int b[]={8,3,2,5};
    int sum1=6;
    cout<<pairSum1(b,n,sum1)<<endl;
    cout<<pairSum2(b,n,sum1)<<endl;
    cout<<pairSum3(b,n,sum1)<<endl;
    return 0;
}

