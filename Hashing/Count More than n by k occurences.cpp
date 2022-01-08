/* Count More than n/k occurences */
#include <bits/stdc++.h>

using namespace std;
void solve(int *a,int n,int k)
{
    int freq=n/k;
    unordered_map<int,int>map;
    for(int i=0;i<n;i++)
    map[a[i]]++;
    for(auto x:map)
    {
        if(x.second>freq)
        cout<<x.first<<" ";
    }
}
int main()
{
    int a[]={1,2,2,2,3,3};
    int k=3;
    int n=6;
    solve(a,n,k);

    return 0;
}
