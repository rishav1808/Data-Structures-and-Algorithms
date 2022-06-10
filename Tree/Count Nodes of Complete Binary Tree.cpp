class Solution {
public:
    
    int leftHeight(TreeNode *root){
        int l=0;
        while(root)
        {
            l++;
            root=root->left;
        }
        
        return l;
        
        
    }

      int rightHeight(TreeNode *root){
        int r=0;
        while(root)
        {
            r++;
            root=root->right;
        }
        
        return r;
        
        
    }
    
    int countNodes(TreeNode* root) {
        
        if(!root)
            return 0;
        int left=leftHeight(root);
        int right=rightHeight(root);
        
        if(left==right)
            return pow(2,left)-1;
        //else if(left!=right)
            return 1+ (countNodes(root->left)) + (countNodes(root->right));
        
        
    }
};
