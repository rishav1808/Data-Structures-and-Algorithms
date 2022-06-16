int findCeil(BinaryTreeNode<int> *node, int x){
    int ans=-1;
    while(node!=NULL)
    {
        if(node->data>=x)
        {
            if(node->data==x)
                return node->data;
            else{
                ans=node->data;
                node=node->left;
            }
        }
        else
            node=node->right;
    }
    return ans;
}
