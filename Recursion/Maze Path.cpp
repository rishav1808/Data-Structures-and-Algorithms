#include <bits/stdc++.h>

using namespace std;

vector<string> solve(int n,int m,int x,int y,string op,vector<string>&ans)
{
    if(x==n && y==m)
    {
        ans.push_back(op);
        return ans;
    }
    if(x>n || y>m)
    {
        return ans;
    }
    //horizontal
    solve(n,m,x+1,y,op+'h',ans);
    //vertical
    solve(n,m,x,y+1,op+'v',ans);
    
    return ans;
}

int main()
{
    vector<string>ans;
    int n=3,m=7;
    string op="";
    solve(n,m,1,1,op,ans);
    
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";


    return 0;
}

