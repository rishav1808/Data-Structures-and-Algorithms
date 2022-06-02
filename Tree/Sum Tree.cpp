class Solution
{
    private:
        pair<bool,int> solve(Node *root){
            //Base Case
            if(root==NULL){
                pair<bool,int>p=make_pair(true,0);
                return p;
            }
            
            //For Leaf Node
            if(root->left==NULL && root->right==NULL){
                pair<bool,int>p=make_pair(true,root->data);
                return p;
            }
            
            pair<bool,int>left=solve(root->left);
            pair<bool,int>right=solve(root->right);
            
            bool condition1=left.first;
            bool condition2=right.first;
            bool condition3= root->data==(left.second)+(right.second);
            
            pair<bool,int>ans;
            
            if(condition1 && condition2 && condition3)
            ans.first=true;
            else
            ans.first=false;
            ans.second=root->data+left.second+right.second;
            return ans;
        }
    public:
    bool isSumTree(Node* root)
    {
         return solve(root).first;
    }
};
