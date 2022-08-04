//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if(s1.size()!=s2.size())
        return false;
        if(s1==s2)
        return true;
        queue<char>q1,q2;
        for(auto x : s1)
        q1.push(x);
        for(auto x : s2)
        q2.push(x);
        
        int goalSize = s1.size();
        while(goalSize--)
        {
            char c = q2.front();
            q2.pop();
            q2.push(c);
            if(q1==q2)
            return true;
            
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends
