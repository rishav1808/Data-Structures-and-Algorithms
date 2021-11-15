#include <bits/stdc++.h>

using namespace std;
string solve(string s,string t)
{
    unordered_map<char,int>m;
    for(auto i:t)
    m[i]++;
    int count = m.size();
    int i=0,j=0,start=0,mini=INT_MAX;
    if(m.find(s[j])!=m.end())
    {
        m[s[j]]--;
        if(m[s[j]]==0)
        count--;
    }
    while(j<s.size())
    {
        if(count>0)
        {
            j++;
            if(m.find(s[j])!=m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                count--;
                cout<<"i :"<<i<<" j :"<<j<<endl;
            }
        }
        else if(count == 0)
        {
            mini=min(mini,j-i+1);
            start=i;
            while(count==0)
            {
                if(m.find(s[i])!=m.end())
                {
                    m[s[i]]++;
                    if(m[s[i]]==1)
                    {
                        count++;
                        mini=min(mini,j-i+1);
                        start=i;
                        cout<<"i :"<<i<<" j :"<<j<<endl;
                    }
                    i++;
                }
                else
                {
                    i++;
                    cout<<"i :"<<i<<" j :"<<j<<endl;
                }
                
            }
        }
    }
    string ans="";
    if(mini!=INT_MAX)
    return ans.append(s.substr(start,mini));
    else
    return ans;
}

int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<solve(s,t);

    return 0;
}
