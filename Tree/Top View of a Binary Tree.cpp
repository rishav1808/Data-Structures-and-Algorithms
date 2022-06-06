class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
         vector<int>ans;
         map<int,int>mp;
         queue<pair<Node *,int>>q;
         q.push(make_pair(root,0));
         
         while(!q.empty()){
             pair<Node *,int>curr=q.front();
             q.pop();
             Node *frontNode=curr.first;
             int hd=curr.second;
             
             if(mp.find(hd)==mp.end()){
                 mp[hd]=frontNode->data;
             }
             
             if(frontNode->left)
             q.push(make_pair(frontNode->left,hd-1));
             if(frontNode->right)
             q.push(make_pair(frontNode->right,hd+1));
         }
         
         for(auto x:mp){
             ans.push_back(x.second);
         }
         return ans;
    }

};

