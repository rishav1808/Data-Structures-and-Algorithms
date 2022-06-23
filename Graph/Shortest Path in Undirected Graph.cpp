
#include<bits/stdc++.h>
void bfs(int node ,  unordered_map<int,list<int>>adj, unordered_map<int,bool>&visited,unordered_map<int,int>&parent)
{
    queue<int>q;
    q.push(node);
    visited[node]=1;
    parent[node]=-1;
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
       // visited[frontNode]=1;
        for(auto neighbour : adj[frontNode])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=1;
                parent[neighbour]=frontNode;
                q.push(neighbour);
                
            }
        }
    }
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	

    unordered_map<int,list<int>>adj;
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //bfs
    bfs(s,adj,visited,parent);
    //stack<int>st;
    vector<int>ans;
    int node = t;
    ans.push_back(node);
    while(node !=s)
    {
        node = parent[node];
        ans.push_back(node);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
    
}

