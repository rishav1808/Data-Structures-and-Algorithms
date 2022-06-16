int floorInBST(TreeNode<int> * root, int x)
{
   int ans=-1;
    
    while(root)
    {
        if(root->val==x)
            return root->val;
        else if(root->val<x)
        {
            ans=root->val;
            root=root->right;
        }
        else
            root=root->left;
    }
    return ans;
}
