#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<vec.size();i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];
        adj[u].push_back(make_pair(v,weight));
        adj[v].push_back(make_pair(u,weight));           
    }
    vector<int>distance(vertices,INT_MAX);
    /*for(int i=0;i<vertices;i++)
    {
        distance[i]=INT_MAX; 
    }*/
    distance[source]=0;
    //pair->(distance,node)
    set<pair<int,int>>s;
    s.insert(make_pair(0,source));
    while(!s.empty())
    {
        auto  top = *(s.begin());
        int dist = top.first;
        int topNode = top.second;
        //Remove TopNode
        s.erase(s.begin());
        for(auto neighbour : adj[topNode])
        {
            if(dist+neighbour.second<distance[neighbour.first])
            {
                auto record = s.find(make_pair(distance[neighbour.first],neighbour.first));
                if(record!=s.end())
                    s.erase(record);
                distance[neighbour.first]=dist+neighbour.second;
                s.insert(make_pair(distance[neighbour.first],neighbour.first));
            }
        }
    }
    return distance;
    
}

