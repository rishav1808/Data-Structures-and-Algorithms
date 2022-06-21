
void createAdjList(unordered_map<int,list<int>>&adj,vector<vector<int>>edges,int E)
{
     for(int i=0;i<E;i++)
     {
         int u = edges[i][0];
         int v = edges[i][1];
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
}
void dfs(unordered_map<int,list<int>>adj,unordered_map<int,bool>&visited,vector<int>&component,int node)
{
    component.push_back(node);
    visited[node]=true;
    for(auto x: adj[node])
    {
        if(!visited[x])
            dfs(adj,visited,component,x);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>ans;
    unordered_map<int,list<int>>adj;
    createAdjList(adj,edges,E);
    unordered_map<int,bool>visited;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int>component;
            dfs(adj,visited,component,i);
            ans.push_back(component);
        }
        
    }
    return ans;
}
