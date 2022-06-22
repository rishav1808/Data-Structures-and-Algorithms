#include<bits/stdc++.h>
bool isCycleDFS(int src, int parent,unordered_map<int,list<int>>adj,unordered_map<int,bool>&visited)
{
    
    visited[src]=1;
    for(auto node : adj[src])
    {
        if(!visited[node])
        {
           bool ans=isCycleDFS(node,src,adj,visited);
            if(ans)
                return true;
        }
        else if(node !=parent)
        return true;
    }
    return false;
}


void createAdjList(unordered_map<int,list<int>>&adj,vector<vector<int>> edges )
{
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>>adj;
    unordered_map<int,bool>visited;
   // createAdjList(adj,edges);
     for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<n;i++)
    {
       
        if(!visited[i])
        {
            bool ans = isCycleDFS(i,-1,adj,visited);
            if(ans==true)
                return "Yes";
        }
    }
    return "No";
}

