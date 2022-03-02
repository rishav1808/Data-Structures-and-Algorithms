#include <bits/stdc++.h>

using namespace std;

vector<int> nsl(int a[],int n)
{
    vector<int>left;
    stack<pair<int,int>>st;
    int placeholder=-1;
    for(int i=0;i<n;i++)
    {
        if(st.size()==0)
        {
            left.push_back(placeholder);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first<a[i])
        {
            left.push_back(st.top().second);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first>=a[i])
        {
            while(st.size()>0 && st.top().first>=a[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                left.push_back(placeholder);
                st.push({a[i],i});
            }
            else
            {
                 left.push_back(st.top().second);
                 st.push({a[i],i});
            }
        }
    }
    return left;
    
}
vector<int> nsr(int a[],int n)
{
    vector<int>right;
    stack<pair<int,int>>st;
    int placeholder=n;
    for(int i=n-1;i>=0;i--)
    {
        if(st.size()==0)
        {
            right.push_back(placeholder);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first<a[i])
        {
            right.push_back(st.top().second);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first>=a[i])
        {
            while(st.size()>0 && st.top().first>=a[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                right.push_back(placeholder);
                st.push({a[i],i});
            }
            else
            {
                 right.push_back(st.top().second);
                 st.push({a[i],i});
            }
        }
    }
    reverse(right.begin(),right.end());
    return right;
    
}
int maxHistogram(int *a,int n)
{
    vector<int>left=nsl(a,n);
    vector<int>right=nsr(a,n);
    int width[n];
    for(int i=0;i<n;i++)
    {
        width[i]=right[i]-left[i]-1;
    }
    int ans[n];
    for(int i=0;i<n;i++)
    {
        
        ans[i]=a[i]*width[i];
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    maxi=max(maxi,ans[i]);
    return maxi;
    
}
int main()
{
    int a[]={6,2,5,4,5,1,6};
    int n=7;
    cout<<maxHistogram(a,n);
}

