#include <bits/stdc++.h>

using namespace std;
template <typename T>
class graph{
    public:
    unordered_map<T,list<T>>adj;
    
    void addEdges(T u,T v,bool direction)
    {
        //direction=0 ->Undirected graph
        //direction=1 ->Directed Graph
        adj[u].push_back(v);
        if(direction==0)
        adj[v].push_back(u);
        
    }
    
    void printGraph()
    {
        for(auto x:adj)
        {
            cout<<x.first<<"->";
            for(auto y:x.second)
            {
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }
    
};

int main()
{
    int n,m;
    cout<<"Enter Number of Nodes: ";
    cin>>n;
    cout<<"Enter Number of Edges: ";
    cin>>m;
    graph<int> g;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdges(u,v,0);
        
    }
    g.printGraph();

    return 0;
}

