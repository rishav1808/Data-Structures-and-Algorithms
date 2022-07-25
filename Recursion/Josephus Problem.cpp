//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
  int solve(vector<int>&v,int k,int index)
  {
      if(v.size()==1)
      return v[0];
      index=(index+k)%v.size();
      v.erase(v.begin()+index);
      solve(v,k,index);
  }
    int safePos(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++)
        v.push_back(i);
        
        return solve(v,k-1,0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends
