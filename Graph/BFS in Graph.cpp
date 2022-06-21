#include<bits/stdc++.h>
void createAdjList(unordered_map<int,set<int>>&adj,int vertex,vector<pair<int, int>> edges)
{
    for(auto x:edges)
    {
        adj[x.first].insert(x.second);
        adj[x.second].insert(x.first);
    }
}
void createVisited(unordered_map<int,bool>&visited,int vertex)
{
    for(int i=0;i<vertex;i++)
    {
        visited[i]=false;
    }
}
void bfs(unordered_map<int,set<int>>adj,unordered_map<int,bool>&visited,vector<int>&ans,int node)
{
 queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty())
    {
        //Step 1: Store frontNode
        int frontNode = q.front();
        //Step 2: Pop from Queue
        q.pop();
        //Step 3: Mark it as Visited
        visited[frontNode]=true;
        //Step 4: Print Node as ans
        ans.push_back(frontNode);
        //Step 5: Push the Non Visited Nodes of the Adj List in Queue
        for (auto x: adj[frontNode])
        {
            if(visited[x]==false)
            {
                q.push(x);
                visited[x]=true;
            }
        }
                
        }
    }

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int>ans;
    unordered_map<int,set<int>>adj;
    unordered_map<int,bool>visited;
    createAdjList(adj,vertex,edges);
    createVisited(visited,vertex);
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            bfs(adj,visited,ans,i);
        }
    }
    
    return ans;
   
}
