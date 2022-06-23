#include<unordered_map>
#include<list>
bool isCycleDFS(int node ,unordered_map<int,list<int>>adj,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited)
{
    visited[node]=1;
    dfsVisited[node]=1;
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
           bool ans = isCycleDFS(neighbour,adj,visited,dfsVisited);
            if(ans)
                return 1;
        }
        //Ans condition
        else if(visited[neighbour] && dfsVisited[neighbour])
            return 1;
    }
    dfsVisited[node]=0;
    return 0;
}





int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bool ans = isCycleDFS(i,adj,visited,dfsVisited);
            if(ans==1)
                return 1;
        }
    }
    return 0;
}
