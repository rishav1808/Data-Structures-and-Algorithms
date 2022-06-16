class Solution {
public:
    TreeNode * findMin(TreeNode *root)
{
    while(root->left)
    root=root->left;
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int value) {
        if(root==NULL)
    return root;
    
    if(root->val<value)
    root->right=deleteNode(root->right,value);
    else if(root->val>value)
    root->left=deleteNode(root->left,value);
    else if(root->val==value)
    {
        // 0 child
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        
        //1 child
        else if(!root->left)
        {
         TreeNode *temp=root->right;
         delete root;
         return temp;
        }
        else if(!root->right)
        {
         TreeNode *temp=root->left;
         delete root;
         return temp;
        }
        
        // 2 Childern
        else{
            TreeNode *temp=findMin(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
        }
    }
    return root;
        
    }
};
