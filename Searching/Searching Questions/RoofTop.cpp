#include<iostream>
using namespace std;

int maxStep(int a[], int n)
    {
            int ans=0,cur=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]>a[i])
        {
            cur++;
            ans=max(ans,cur);
        }
        else
        cur=0;
    }
    return ans;
