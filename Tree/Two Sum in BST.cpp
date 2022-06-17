class Solution {
public:
    void inorder(TreeNode *root,vector<int>&v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);
        int start=0;
        int end=v.size()-1;
        while(start<end)
        {
            if(v[start]+v[end]==k)
                return true;
            else if(v[start]+v[end]>k)
                end--;
            else if(v[start]+v[end]<k)
                start++;
        }
        return false;
        
    }
};
