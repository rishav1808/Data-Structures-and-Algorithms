#include<bits/stdc++.h>
bool cmp(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];
}
int findParent(int node ,vector<int>&parent)
{
    if(node == parent[node])
        return node;
    parent[node] = findParent(parent[node],parent);
    return parent[node];
}

void unionSet(int u, int v,vector<int>&parent,vector<int>&rank)
{
    u=findParent(u,parent);
    v=findParent(v,parent);
    if(u==v)
        return ;
    else{
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else if(rank[u]==rank[v])
        {
            parent[v]=u;
            rank[u]++;
        }
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int>parent(n);
    vector<int>rank(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
     int minWeight = 0;
    sort(edges.begin(),edges.end(),cmp);
    for(int i=0;i<edges.size()-1;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        
        //Check if u and v are in the same component or not
        if(findParent(u,parent)!=findParent(v,parent))
        {
            
            unionSet(u,v,parent,rank);
            minWeight+=wt;
            
        }
    }
    return minWeight;
}
