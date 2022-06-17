class BSTIterator {
public:
     vector<int>v;
    int i=0;
    void inorder(TreeNode *root,vector<int>&v)
    {
        if(!root)
            return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    BSTIterator(TreeNode* root) {
       
        inorder(root,v);
        
        
        
    }
    
    int next() {
        
        return v[i++];
        
        
    }
    
    bool hasNext() {
        if(i<v.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
