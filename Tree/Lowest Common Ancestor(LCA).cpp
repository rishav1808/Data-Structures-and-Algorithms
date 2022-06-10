class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL)
       return NULL;
       
       if(root->data==n1 || root->data==n2)
       return root;
       
       Node * x = lca(root->left,n1,n2);
       Node * y = lca(root->right,n1,n2);
       
       if(x && y)
       return root;
       
       if(x!=NULL && y==NULL)
       return x;
       if(x==NULL && y!=NULL)
       return y;
       if(x==NULL && y==NULL)
       return NULL;
       
       
    }
};
