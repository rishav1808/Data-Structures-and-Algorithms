class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int>ans;
        map<int,map<int,vector<int>>>mp;
        queue<pair<Node *,pair<int,int>>>q;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            
            pair<Node *,pair<int,int>>curr=q.front();
            q.pop();
            Node *res=curr.first;
            int hd=curr.second.first;
            int level=curr.second.second;
            
            mp[hd][level].push_back(res->data);
            
            if(res->left)
            q.push(make_pair(res->left,make_pair(hd-1,level+1)));
            if(res->right)
            q.push(make_pair(res->right,make_pair(hd+1,level+1)));
            
            
        }
        for(auto x:mp){
            for(auto y:x.second){
                for(auto z:y.second){
                    ans.push_back(z);
                }
            }
        }
        return ans;
    }
};
