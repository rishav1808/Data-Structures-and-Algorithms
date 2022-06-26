// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void dfs(int node ,unordered_map<int,list<int>>&adjlist,unordered_map<int,bool>&visited )
  {
      visited[node]=1;
      for(auto x:adjlist[node])
      {
          if(!visited[x])
          dfs(x,adjlist,visited);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
       unordered_map<int,list<int>>adjlist;
       for(int i=0;i<V;i++)
       {
           for(int j=0;j<V;j++)
           if(adj[i][j]==1)
           adjlist[i+1].push_back(j+1);
       }
       unordered_map<int,bool>visited;
       int count=0;
       for(int i=1;i<=V;i++)
       {
           if(!visited[i])
           {
               count++;
               dfs(i,adjlist,visited);
               
           }
           
           
       }
       return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends
