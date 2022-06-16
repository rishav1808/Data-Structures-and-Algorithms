class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
             TreeNode * c=new TreeNode(val);
            return c;
        }
           
        TreeNode *curr=root;
       
        while(curr)
        {
            if(curr->val<val)
            {
                
                if(curr->right==NULL)
                {
                    TreeNode * c=new TreeNode(val);
                    curr->right=c;
                     break;
                }
                   
                curr=curr->right;
                
            }
                
            else
            {
                 
                if(curr->left==NULL)
                {
                    TreeNode * c=new TreeNode(val);
                    curr->left=c;
                    break;
                }
                curr=curr->left;
            }
                
        }
        return root;
    }
};
