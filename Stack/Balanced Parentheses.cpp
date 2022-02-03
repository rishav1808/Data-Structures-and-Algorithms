#include <bits/stdc++.h>

using namespace std;
unordered_map<char,int>symbols={{'(',-1},{'[',-2},{'{',-3},{')',1},{']',2},{'}',3}};

string isBalanced(string s)
{
    stack<char>st;
    for(auto x:s)
    {
        if(symbols[x]<0)
        st.push(x);
        else
        {
            if(st.empty())
            return "NO";
            char top=st.top();
            st.pop();
            if(symbols[top]+symbols[x]!=0)
            return "NO";
        }
    }
    if(st.empty())return "YES";
    return "NO";
}
int main()
{
    cout<<isBalanced("{}([()])")<<endl;
    cout<<isBalanced("(([])")<<endl;

    return 0;
}
