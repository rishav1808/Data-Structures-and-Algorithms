// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    string ans="";
		    map<char,int>mp;
		    queue<char>q;
		    for(int i=0;i<s.length();i++)
		    {
		        char x=s[i];
		        mp[x]++;
		        q.push(x);
		        
		        while(q.size()>0)
		        {
		            if(mp[q.front()]>1)
		            q.pop();
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.size()==0)
		        ans.push_back('#');
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
