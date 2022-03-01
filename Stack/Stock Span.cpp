#include <bits/stdc++.h>

using namespace std;
vector<int> solve(int *a,int n)
{
    vector<int>v;
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++)
    {
        if(st.size()==0)
        {
            v.push_back(-1);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first>a[i])
        {
            v.push_back(st.top().second);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first<a[i])
        {
            while(st.size()>0 && st.top().first<a[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                v.push_back(-1);
                st.push({a[i],i});
            }
            else{
                v.push_back(st.top().second);
                st.push({a[i],i});
            }
        }
    }
    for(int i=0;i<n;i++)
    v[i]=i-v[i];
    return v;
}
int main()
{
     int price[] = { 10, 4, 5, 90, 120, 80 };
     int n = sizeof(price) / sizeof(price[0]);
     vector<int>ans=solve(price,n);
     for(int i=0;i<n;i++)
     cout<<ans[i]<<" ";

    return 0;
}

