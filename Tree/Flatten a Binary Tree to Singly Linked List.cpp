class Solution {
public:
    TreeNode *prev=NULL;
    //Solution 1 : Recursive Solution : TC :O(N) SC:O(N)
    void flatten(TreeNode* root) {
        
        if(root==NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
        
    }
    
    //Solution 2 : Using Morris Traversal: TC :O(N) SC:O(1)
    void flatten(TreeNode* root) {
        
      TreeNode *curr=root;
        while(curr!=NULL){
            
            if(curr->left!=NULL)
            {
                TreeNode *prev=curr->left;
                //Going to the rightmost node of the LeftSubTree
                while(prev->right!=NULL)
                {
                    prev=prev->right;
                }
                prev->right=curr->right;//Observed from Question
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;//Moving to the next node
        }
        
    }
};
