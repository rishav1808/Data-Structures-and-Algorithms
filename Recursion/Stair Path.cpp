#include <bits/stdc++.h>

using namespace std;

vector<string> solve(int n,string op,vector<string>&ans)
{
    if(n==0)
    {
        ans.push_back(op);
        return ans;
    }
    if(n<0)
    {
        return ans;
    }
    
    solve(n-1,op+'1',ans);
    solve(n-2,op+'2',ans);
    solve(n-3,op+'3',ans);
    return ans;
}


int main()
{
    vector<string>ans;
    solve(5,"",ans);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";

    return 0;
}

