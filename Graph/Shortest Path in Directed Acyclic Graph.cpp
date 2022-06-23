#include<bits/stdc++.h>
using namespace std;

class graph{
  public:
  unordered_map<int,list<pair<int,int>>>adj;
  
  void addEdge(int u,int v,int weight)
  {
      pair<int,int>p=make_pair(v,weight);
      adj[u].push_back(p);
  }
  
  void printGrpah()
  {
      for(auto x:adj)
      {
          cout<<x.first<<"->";
          for(auto y :x.second)
          {
              cout<<"{"<<y.first<<","<<y.second<<"}";
          }
          cout<<endl;
      }
  }
  
  void topologicalSort(int node,unordered_map<int,bool>&visited,stack<int>&st)
  {
      visited[node]=1;
      for(auto x:adj[node])
      {
          if(!visited[x.first])
          {
              topologicalSort(x.first,visited,st);
              
          }
      
      st.push(node);
      return;
    } 
 }
 void shortestDistance(int src,vector<int>&distance,stack<int>&st)
 {
   distance[src]=0;
   while(!st.empty())
   {
       int top = st.top();
       st.pop();
      if(distance[top]!=INT_MAX)
      {
          for(auto i:adj[top])
       {
           if(distance[top]+i.second<distance[i.first])
           distance[i.first]=distance[top]+i.second;
       }
      }
       
   }
   
 }
};

int main()
{
    graph G;
     G.addEdge(1, 3, 6);

    G.addEdge(1, 2, 2);

    G.addEdge(0, 1, 5);

    G.addEdge(0, 2, 3);

    G.addEdge(3, 4, -1);

    G.addEdge(2, 4, 4);

    G.addEdge(2, 5, 2);

    G.addEdge(2, 3, 7);

    G.addEdge(4, 5, -2);
   unordered_map<int,bool>visited;
   stack<int>st;
   int node =0;
    int src=1;
   G.topologicalSort(node,visited,st);
   vector<int>distance(6,INT_MAX);
   
  G.shortestDistance(src,distance,st);
  for(auto x:distance)
   cout<<x<<" ";
   
}
