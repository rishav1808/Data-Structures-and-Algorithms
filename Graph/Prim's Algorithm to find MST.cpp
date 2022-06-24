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
    //Prim's Algo
    for(int i=1;i<n;i++)
    {
        int mini = INT_MAX;//key[node]
        int node;//minimum node
        for(int j=1;j<=n;j++)
        {//Step1 :Find minimum node which is not included in MST
         if(mst[j]==false && key[j]<mini)//minimum node which is not included in MST
         {
             node=j;//node represent minimum node
             mini=key[j];//Update weight
         }
        }
        //Step2:Mark Mst of node as True; include node in MST
        mst[node]=true;
        //Step3:Check for neighbours
        for(auto it :adj[node])
        {
          int v = it.first;
            int w =it.second;
            if(mst[v]==false && w<key[v])
            {//Step4:Updating weights and parent 
                parent[v]=node;
                key[v]=w;
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

