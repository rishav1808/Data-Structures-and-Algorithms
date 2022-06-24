#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>>adj;
    //Creating Adj List
    for(int i=0;i<g.size();i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int weight = g[i].second;
        adj[u].push_back(make_pair(v,weight));
        adj[v].push_back(make_pair(u,weight));
    }
    //Creating 3 DS needed
    vector<int>key(n+1,INT_MAX);
    vector<int>mst(n+1,0);
    vector<int>parent(n+1,-1);

    
    key[1]=0;
    parent[1]=-1;
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    pq.push({0,1});
    //Prim's Algo
    while(!pq.empty())
    {
         int node = pq.top().second; 
        pq.pop(); 
          mst[node] = true; 
        
        for (auto it : adj[node]) {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < key[v]) {
                parent[v] = node;
                key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
    }
    vector<pair<pair<int, int>, int>>result;
    for(int i=2;i<=n;i++)
    {
        result.push_back(make_pair(make_pair(parent[i],i),key[i]));
    }
    return result;
}

