class Solution {
public:
    bool solve(TreeNode *root,long int mini,long int maxi)
    {
        if(root==NULL)
            return true;
        if(root->val >= maxi || root->val <= mini)
            return false;
        bool lst = solve(root->left,mini,root->val);
        bool rst=  solve(root->right,root->val,maxi);
        
        return(lst && rst);
    }
        
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};
