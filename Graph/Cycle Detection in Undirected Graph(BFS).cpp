#include<bits/stdc++.h>
bool isCycleBFS(int src,unordered_map<int,list<int>>adj,unordered_map<int,bool>&visited,unordered_map<int,int>&parent)
{
    parent[src]=-1;
    queue<int>q;
    q.push(src);
    visited[src]=1;
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for(auto node : adj[frontNode])
        {
            if(!visited[node])
            {
                visited[node]=1;
                q.push(node);
                parent[node]=frontNode;
            }
            else if( visited[node]==1 && node != parent[frontNode])
                return true;
        }
    }
    return false;
    
    
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans=isCycleBFS(i,adj,visited,parent);
            if(ans==1)
                return "Yes";
        }
    }
    return "No";
}

