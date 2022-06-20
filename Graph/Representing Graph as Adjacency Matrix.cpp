#include <iostream>

using namespace std;



int main()
{
    //Representing a Graph
    int n,m;
    cout<<"Enter Number of Nodes: ";
    cin>>n;
    cout<<"Enter Number of Edges: ";
    cin>>m;
    adj[n+1][n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        //Undirected Graph
        adj[v][u]=1;
    }

    return 0;
}
